#include "Subscriber.h"
#include "CppRuntimeException.h"
#include "StringConvertUtil.h"

#include <MQTTAsync.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <future>

namespace zserio
{

struct Subscriber::Impl
{
    Impl(PubSubSystem& system):
        m_system(system),
        m_client()
    { }

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

    static int onMessageArrived(void* context, char* topicName, int topicLen, MQTTAsync_message* message)
    {
        auto sub = static_cast<Subscriber::Impl*>(context);
        auto topic = std::string(topicName, topicLen);
        sub->notifyTopics(topic, static_cast<uint8_t*>(message->payload), message->payloadlen);
        MQTTAsync_freeMessage(&message);
        MQTTAsync_free(topicName);
        return 1;
    }

    static void onAsyncSuccess(void* context, MQTTAsync_successData* /*response*/)
    {
        auto& client = *static_cast<Subscriber::Impl*>(context);
        client.m_async_res.set_value("");
    }

    static void onAsyncFailure(void* context, MQTTAsync_failureData* response)
    {
        auto& client = *static_cast<Subscriber::Impl*>(context);
        std::ostringstream stream;
        stream << (response->message ? response->message : "")
               << "(" << response->code << ")";
        client.m_async_res.set_value(stream.str());
    }

    ~Impl()
    {
        MQTTAsync_disconnectOptions disc_opts = MQTTAsync_disconnectOptions_initializer;
        disc_opts.onSuccess = onAsyncSuccess;
        disc_opts.onFailure = onAsyncFailure;

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

    void syncWithAsyncOp(std::function<void()>& asyncTrigger)
    {
        m_async_res = std::promise<std::string>();
        auto future = m_async_res.get_future();

        asyncTrigger();

        future.wait();
        if (!future.get().empty())
            throw CppRuntimeException(future.get());
    }

    void connect(const PubSubSystem::HostInformation& host)
    {
        const std::string hostAddr = "tcp://" + host.hostname + ":" + std::to_string(host.port);
        MQTTAsync_create(&m_client, hostAddr.c_str(), host.client_id.c_str(), MQTTCLIENT_PERSISTENCE_NONE, nullptr);
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

    void notifyTopics(std::string& topic, const uint8_t* msgData, size_t msgSize)
    {
        for (auto& t: m_topics)
        {
            if (t->matches(topic))
                t->onMessageAvailable(msgData, msgSize);
        }
    }

private:
    PubSubSystem& m_system;
    std::promise<std::string> m_async_res;
    MQTTAsync m_client;
    std::list<const Topic*> m_topics;
};


Subscriber::Subscriber(PubSubSystem& system):
    m_impl(new Subscriber::Impl(system))
{ }

Subscriber::~Subscriber() = default;

void Subscriber::connect(const PubSubSystem::HostInformation &host)
{
    m_impl->connect(host);
};

void Subscriber::subscribe(const Topic &topic)
{
    m_impl->subscribe(topic);
}

void Subscriber::unsubscribe(const Topic& topic)
{
    m_impl->unsubscribe(topic);
}

}
