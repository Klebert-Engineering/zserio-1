#include "RosPubSubClient.h"
#include "CppRuntimeException.h"
#include "StringConvertUtil.h"
#include "Topic.h"
#include "ZserioWrapper.h"

#include "ros/ros.h"

#include <functional>
#include <iostream>
#include <future>
#include <sstream>
#include <list>
#include <algorithm>

namespace zserio
{

struct RosPubSubClient::Impl
{
    Impl(RosPubSubClient::HostInformation host) //: m_host(std::move(host))
        : m_nodeHandle(nullptr)
    {
	int numArgs = 0;
        ros::init(numArgs, NULL, host.nodeName);
    }

    ~Impl()
    {
//        // Avoid throwing exception from within dtor by catch
//        try {
//            disconnect();
//        } catch (CppRuntimeException& ex) {
//            std::cerr << "Critical error while trying to disconnect: "
//                      << ex.what()
//                      << std::endl;
//            // Free up memory to avoid leak on exception
//            MQTTAsync_destroy(&m_client);
//            m_client = nullptr;
//        }
    }

//    static void onConnLost(void* context, char* cause)
//    {
//        auto& client = *static_cast<MQTTAsync*>(context);
//        MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
//        int rc;
//        conn_opts.keepAliveInterval = 20;
//        conn_opts.cleansession = 1;
//        if ((rc = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS)
//        {
//            std::cerr << "Failed to start connect, return code: " <<  rc  <<
//                         " Details: " << cause << std::endl;
//        }
//    }
//
//    static void onAsyncSuccess(void* context, MQTTAsync_successData* /*response*/)
//    {
//        auto& client = *static_cast<MqttPubSubClient::Impl*>(context);
//        client.m_async_res.set_value("");
//    }
//
//    static void onAsyncFailure(void* context, MQTTAsync_failureData* response)
//    {
//        auto& client = *static_cast<MqttPubSubClient::Impl*>(context);
//        std::ostringstream stream;
//        stream << (response->message ? response->message : "")
//               << "(" << response->code << ")";
//        client.m_async_res.set_value(stream.str());
//    }
//
//    void syncWithAsyncOp(std::function<void()>& asyncTrigger)
//    {
//        m_async_res = std::promise<std::string>();
//        auto future = m_async_res.get_future();
//
//        asyncTrigger();
//
//        future.wait();
//        if (!future.get().empty())
//            throw CppRuntimeException(future.get());
//    }

    void publish(const std::string &topic,
                 const uint8_t* buffer,
                 size_t size,
                 int qos = 0,
                 bool retain = false)
    {
	ros_zserio_test::ZserioWrapper msg;
	msg.zserio_bytes = std::vector<uint8_t>(buffer, buffer + size);

	// TODO: advertise only once
        ros::Publisher pub =
		m_nodeHandle->advertise<ros_zserio_test::ZserioWrapper>(topic, 1000);
	pub.publish(msg);
        ros::spinOnce();

    }

//    static int onMessageArrived(void* context, char* topicName, int topicLen, MQTTAsync_message* message)
//    {
//        auto sub = static_cast<MqttPubSubClient::Impl*>(context);
//        auto topic = std::string(topicName, topicLen);
//        sub->notifyTopics(topic, static_cast<uint8_t*>(message->payload), message->payloadlen);
//        MQTTAsync_freeMessage(&message);
//        MQTTAsync_free(topicName);
//        return 1;
//    }
//
//    void subscribe(const Topic& topic)
//    {
//        if (std::find(m_topics.begin(), m_topics.end(), &topic)
//                == m_topics.end())
//        {
//            MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
//            opts.onSuccess = onAsyncSuccess;
//            opts.onFailure = onAsyncFailure;
//            opts.context = this;
//
//            auto f = std::function<void()>([this, &opts, &topic](){
//                int rc;
//                // TODO Use host config with quality of service level
//                if ((rc = MQTTAsync_subscribe(m_client, topic.topic().c_str(), 2, &opts)) != MQTTASYNC_SUCCESS)
//                {
//                    std::ostringstream stream;
//                    stream << "Failed to start subscribe, return code " << rc;
//                    throw CppRuntimeException(stream.str());
//                }
//            });
//            syncWithAsyncOp(f);
//            m_topics.push_back(&topic);
//        }
//    }
//
//    void unsubscribe(const Topic& topic)
//    {
//        auto it = std::find(m_topics.begin(), m_topics.end(), &topic);
//        if (it != m_topics.end())
//        {
//            MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
//            opts.onSuccess = onAsyncSuccess;
//            opts.onFailure = onAsyncFailure;
//            opts.context = this;
//
//            auto f = std::function<void()>([this, &opts, &topic](){
//                int rc;
//                if ((rc = MQTTAsync_unsubscribe(m_client, topic.topic().c_str(), &opts)))
//                {
//                    std::ostringstream stream;
//                    stream << "Failed to start unsubscribe, return code " << rc;
//                    throw CppRuntimeException(stream.str());
//                }
//            });
//            syncWithAsyncOp(f);
//            m_topics.remove(&topic);
//        }
//    }
//
//    void notifyTopics(std::string& topic, const uint8_t* msgData, size_t msgSize)
//    {
//        for (auto& t: m_topics)
//        {
//            if (t->matches(topic))
//                t->onMessageAvailable(msgData, msgSize);
//        }
//    }
    void connect()
    {
        m_nodeHandle.reset(new ros::NodeHandle());
    }

    void disconnect()
    {
        m_nodeHandle.release();
    }

private:
    std::unique_ptr<ros::NodeHandle> m_nodeHandle;
};

RosPubSubClient::RosPubSubClient(const RosPubSubClient::HostInformation &host):
    m_impl(new RosPubSubClient::Impl(host))
{ }

RosPubSubClient::~RosPubSubClient() = default;


void RosPubSubClient::connect()
{
    m_impl->connect();
}

void RosPubSubClient::disconnect()
{
    m_impl->disconnect();
};

void RosPubSubClient::subscribe(const Topic &topic)
{
    // TODO: m_impl->subscribe(topic);
}

void RosPubSubClient::unsubscribe(const Topic& topic)
{
    // TODO: m_impl->unsubscribe(topic);
}

void RosPubSubClient::publish(const std::string &topic, const uint8_t* buffer, size_t size, int qos = 0, bool retain = false)
{
    m_impl->publish(topic, buffer, size, qos, retain);
};

}
