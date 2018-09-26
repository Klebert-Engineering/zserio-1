#include "RosPubSubClient.h"
#include "CppRuntimeException.h"
#include "StringConvertUtil.h"
#include "Topic.h"
#include "ZserioWrapper.h"

#include <ros/ros.h>
#include <std_msgs/String.h>

#include <functional>
#include <future>
#include <sstream>
#include <list>
#include <algorithm>
#include <map>

namespace zserio
{

struct RosPubSubClient::Impl
{
    Impl(RosPubSubClient::HostInformation host): m_hostCfg(host)
    {
        int numArgs = 0;
        if (!ros::Time::isValid()){
            ros::init(numArgs, nullptr, m_hostCfg.nodeName);
        }
    }

    ~Impl()
    { }

    void publish(const std::string &topic,
                 const uint8_t* buffer,
                 size_t size,
                 int qos = 0,
                 bool retain = false)
    {
        ros_zserio_test::ZserioWrapper msg;
        msg.zserio_bytes = std::vector<uint8_t>(buffer, buffer + size);

        if (m_pub.getTopic().empty()) {
            m_pub = m_nodeHandle->advertise<ros_zserio_test::ZserioWrapper>(topic, 1000);
        }

        m_pub.publish(msg);
        ros::spinOnce();
    }

    void onRosMessageAvailable(const boost::shared_ptr<ros_zserio_test::ZserioWrapper const> msg,
                               std::string topic)
    {
        auto rawData = static_cast<const uint8_t*>(&msg->zserio_bytes[0]); 
        notifyTopics(topic, rawData, msg->zserio_bytes.size()); 
    }

    void subscribe(const Topic& topic)
    {
        const auto topicStr = topic.topic();
        auto it = m_subscribers.find(topicStr);
        if (it == m_subscribers.end())
        {
            auto callback = boost::bind(
                        &RosPubSubClient::Impl::onRosMessageAvailable,
                        this,
                        _1,
                        topicStr);

            m_subscribers[topicStr] = m_nodeHandle->subscribe<ros_zserio_test::ZserioWrapper>(
                    topic.topic(),
                    100,
                    callback
                    );


            if (!m_subscribers[topicStr]) throw CppRuntimeException("Unable to create subscriber.");

            if (!m_future.valid())
                m_future = std::async(std::launch::async, std::function<void()>([](){ ros::spin(); }));
        }

        if (m_subscribers.find(topicStr) != m_subscribers.end())
        {
            auto& topics = m_topics[topicStr];
            if (std::find(topics.begin(), topics.end(), &topic) == topics.end()) {
                topics.push_back(&topic);
            }
        }
    }

    void unsubscribe(const Topic& topic)
    {
        const auto topicStr = topic.topic();
        if (m_subscribers.find(topicStr) != m_subscribers.end())
        {
            auto& topics = m_topics[topicStr];
            std::remove(topics.begin(), topics.end(), &topic);
            if (topics.size() == 0)
                m_subscribers.erase(topicStr);
        }
    }

    void notifyTopics(std::string topic, const uint8_t* msgData, size_t msgSize)
    {
        for (auto& kv: m_topics)
            for (auto& t: kv.second)
            {
                if (t->matches(topic))
                    t->onMessageAvailable(msgData, msgSize);
            }
    }

    void connect()
    {
        if (!ros::isInitialized()) 
            ros::Rate loop_rate(10);

        if (!ros::master::check())
            throw CppRuntimeException("ROS Master is not available.");

        if (!m_nodeHandle.get())
            m_nodeHandle.reset(new ros::NodeHandle());
    }

    void disconnect()
    {
        m_nodeHandle.release();
    }

private:
    std::unique_ptr<ros::NodeHandle> m_nodeHandle = nullptr;
    std::future<void> m_future;
    ros::Publisher m_pub;
    std::map<std::string, ros::Subscriber> m_subscribers;
    std::map<std::string, std::list<const Topic*>> m_topics;
    RosPubSubClient::HostInformation m_hostCfg;
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
    m_impl->subscribe(topic);
}

void RosPubSubClient::unsubscribe(const Topic& topic)
{
    m_impl->unsubscribe(topic);
}

void RosPubSubClient::publish(const std::string &topic, const uint8_t* buffer, size_t size, int qos = 0, bool retain = false)
{
    m_impl->publish(topic, buffer, size, qos, retain);
};

}
