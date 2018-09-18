#include <MQTTAsync.h>
#include "CppRuntimeException.h"
#include "StringConvertUtil.h"
#include "Publisher.h"

#include <functional>
#include <iostream>
#include <future>
#include <sstream>

namespace zserio
{

struct Publisher::Impl
{
    Impl(PubSubSystem& system):
        m_system(system)
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

    static void onAsyncSuccess(void* context, MQTTAsync_successData* /*response*/)
    {
        auto& client = *static_cast<Publisher::Impl*>(context);
        client.m_async_res.set_value("");
    }

    static void onAsyncFailure(void* context, MQTTAsync_failureData* response)
    {
        auto& client = *static_cast<Publisher::Impl*>(context);
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
        std::cout << hostAddr <<  " " << host.client_id << std::endl;
        MQTTAsync_create(&m_client, hostAddr.c_str(), host.client_id.c_str(), MQTTCLIENT_PERSISTENCE_NONE, nullptr);
        std::cout << "Creation successful" << std::endl;
        MQTTAsync_setCallbacks(m_client, nullptr, onConnLost, nullptr, nullptr);

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

    void publish(const std::string &topic,
                 const uint8_t* buffer,
                 size_t size,
                 int qos = 0,
                 bool retain = false)
    {
        std::cout << "About to publish with topic " << topic << std::endl;
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

private:
    PubSubSystem& m_system;
    std::promise<std::string> m_async_res;
    MQTTAsync m_client;
};

Publisher::Publisher(PubSubSystem &system):
    m_impl(new Publisher::Impl(system))
{ }

Publisher::~Publisher() = default;

void Publisher::connect(const PubSubSystem::HostInformation &host)
{
    m_impl->connect(host);
};

void Publisher::publish(const std::string &topic, const uint8_t* buffer, size_t size, int qos = 0, bool retain = false)
{
    m_impl->publish(topic, buffer, size, qos, retain);
};

}
