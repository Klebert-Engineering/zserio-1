#include <MQTTAsync.h>
#include "MqttPubSubClient.h"
#include "CppRuntimeException.h"
#include "StringConvertUtil.h"
#include "Topic.h"

#include <functional>
#include <iostream>
#include <future>
#include <sstream>
#include <list>
#include <algorithm>

namespace zserio
{

struct MqttPubSubClient::Impl
{
    Impl(MqttPubSubClient::HostInformation host): m_host(std::move(host))
    {  }

    ~Impl()
    {
        // Avoid throwing exception from within dtor by catch
        try {
            disconnect();
        } catch (CppRuntimeException& ex) {
            std::cerr << "Critical error while trying to disconnect: "
                      << ex.what()
                      << std::endl;
            // Free up memory to avoid leak on exception
            MQTTAsync_destroy(&m_client);
            m_client = nullptr;
        }
    }

    static void onConnLost(void* context, char* cause)
    {
        auto& client = *static_cast<MQTTAsync*>(context);
        MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
        int rc;
        conn_opts.keepAliveInterval = 20;
        conn_opts.cleansession = 1;
        if ((rc = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS)
        {
            std::cerr << "Failed to start connect, return code: " <<  rc  <<
                         " Details: " << cause << std::endl;
        }
    }

    static void onAsyncSuccess(void* context, MQTTAsync_successData* /*response*/)
    {
        auto& client = *static_cast<MqttPubSubClient::Impl*>(context);
        client.m_async_res.set_value("");
    }

    static void onAsyncFailure(void* context, MQTTAsync_failureData* response)
    {
        auto& client = *static_cast<MqttPubSubClient::Impl*>(context);
        std::ostringstream stream;
        stream << (response->message ? response->message : "")
               << "(" << response->code << ")";
        client.m_async_res.set_value(stream.str());
    }

    void syncWithAsyncOp(std::function<void()>& asyncTrigger)
    {
        m_async_res = std::promise<std::string>();
        auto future = m_async_res.get_future();

        asyncTrigger();

        future.wait();
        if (!future.get().empty())
            throw CppRuntimeException(future.get());
    }

    void connect()
    {
        if (m_client)
            throw CppRuntimeException("Client is already connected.");

        const std::string hostAddr = "tcp://" + m_host.hostname + ":" + std::to_string(m_host.port);
        std::cout << hostAddr <<  " " << m_host.client_id << std::endl;
        MQTTAsync_create(&m_client, hostAddr.c_str(), m_host.client_id.c_str(), MQTTCLIENT_PERSISTENCE_NONE, nullptr);
        std::cout << "Creation successful" << std::endl;
        MQTTAsync_setCallbacks(m_client, this, onConnLost, onMessageArrived, nullptr);

        MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
        conn_opts.keepAliveInterval = 20;
        conn_opts.cleansession = 1;
        conn_opts.onSuccess = onAsyncSuccess;
        conn_opts.onFailure = onAsyncFailure;
        conn_opts.context = this;

        auto f = std::function<void()>([this, &conn_opts](){
            int rc;
            if ((rc = MQTTAsync_connect(m_client, &conn_opts)) != MQTTASYNC_SUCCESS)
            {
                std::ostringstream stream;
                stream << "Failed to start connect, return code " << rc;
                throw CppRuntimeException(stream.str());
            }
        });
        syncWithAsyncOp(f);
    }

    void disconnect()
    {
        if (!m_client) return;

        MQTTAsync_disconnectOptions disc_opts = MQTTAsync_disconnectOptions_initializer;
        disc_opts.onSuccess = onAsyncSuccess;
        disc_opts.onFailure = onAsyncFailure;
        disc_opts.context = this;

        auto f = std::function<void()>( [this, &disc_opts](){
            int rc;
            if ((rc = MQTTAsync_disconnect(m_client, &disc_opts)) != MQTTASYNC_SUCCESS) {
                std::ostringstream stream;
                stream << "Failed to start disconnect, return code " << rc << std::endl;
                throw CppRuntimeException(stream.str());

            };
        });
        syncWithAsyncOp(f);

        MQTTAsync_destroy(&m_client);
        m_client = nullptr;
    }

    void publish(const std::string &topic,
                 const uint8_t* buffer,
                 size_t size,
                 int qos = 0,
                 bool retain = false)
    {
        MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
        opts.onSuccess = onAsyncSuccess;
        opts.context = this;

        MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
        pubmsg.payload = (void*)buffer;
        pubmsg.payloadlen = static_cast<int>(size);
        pubmsg.qos = qos;
        pubmsg.retained = retain ? 1 : 0;

        auto f = std::function<void()>([this, &opts, &pubmsg, &topic](){
            int rc;
            if ((rc = MQTTAsync_sendMessage(m_client, topic.c_str(), &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
            {
                std::ostringstream stream;
                stream << "Failed to start sendMessage, return code " << rc << std::endl;
                throw CppRuntimeException(stream.str());
            }
        });
        syncWithAsyncOp(f);
    }

    static int onMessageArrived(void* context, char* topicName, int topicLen, MQTTAsync_message* message)
    {
        auto sub = static_cast<MqttPubSubClient::Impl*>(context);
        auto topic = std::string(topicName, topicLen);
        sub->notifyTopics(topic, static_cast<uint8_t*>(message->payload), message->payloadlen);
        MQTTAsync_freeMessage(&message);
        MQTTAsync_free(topicName);
        return 1;
    }

    void subscribe(const Topic& topic)
    {
        if (std::find(m_topics.begin(), m_topics.end(), &topic)
                == m_topics.end())
        {
            MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
            opts.onSuccess = onAsyncSuccess;
            opts.onFailure = onAsyncFailure;
            opts.context = this;

            auto f = std::function<void()>([this, &opts, &topic](){
                int rc;
                // TODO Use host config with quality of service level
                if ((rc = MQTTAsync_subscribe(m_client, topic.topic().c_str(), 2, &opts)) != MQTTASYNC_SUCCESS)
                {
                    std::ostringstream stream;
                    stream << "Failed to start subscribe, return code " << rc;
                    throw CppRuntimeException(stream.str());
                }
            });
            syncWithAsyncOp(f);
            m_topics.push_back(&topic);
        }
    }

    void unsubscribe(const Topic& topic)
    {
        auto it = std::find(m_topics.begin(), m_topics.end(), &topic);
        if (it != m_topics.end())
        {
            MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
            opts.onSuccess = onAsyncSuccess;
            opts.onFailure = onAsyncFailure;
            opts.context = this;

            auto f = std::function<void()>([this, &opts, &topic](){
                int rc;
                if ((rc = MQTTAsync_unsubscribe(m_client, topic.topic().c_str(), &opts)))
                {
                    std::ostringstream stream;
                    stream << "Failed to start unsubscribe, return code " << rc;
                    throw CppRuntimeException(stream.str());
                }
            });
            syncWithAsyncOp(f);
            m_topics.remove(&topic);
        }
    }

    void notifyTopics(std::string& topic, const uint8_t* msgData, size_t msgSize)
    {
        for (auto& t: m_topics)
        {
            if (t->matches(topic))
                t->onMessageAvailable(msgData, msgSize);
        }
    }

private:
    MqttPubSubClient::HostInformation m_host;
    std::promise<std::string> m_async_res;
    MQTTAsync m_client = nullptr;
    std::list<const Topic*> m_topics;
};

MqttPubSubClient::MqttPubSubClient(const MqttPubSubClient::HostInformation &host):
    m_impl(new MqttPubSubClient::Impl(host))
{ }

MqttPubSubClient::~MqttPubSubClient() = default;


void MqttPubSubClient::connect()
{
    m_impl->connect();
}

void MqttPubSubClient::disconnect()
{
   m_impl->disconnect();
};

void MqttPubSubClient::subscribe(const Topic &topic)
{
    m_impl->subscribe(topic);
}

void MqttPubSubClient::unsubscribe(const Topic& topic)
{
    m_impl->unsubscribe(topic);
}

void MqttPubSubClient::publish(const std::string &topic, const uint8_t* buffer, size_t size, int qos = 0, bool retain = false)
{
    m_impl->publish(topic, buffer, size, qos, retain);
};

}
