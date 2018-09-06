#include <mosquitto.h>
#include "Subscriber.h"
#include "CppRuntimeException.h"
#include "StringConvertUtil.h"

#include <algorithm>
#include <iostream>

namespace zserio
{

Subscriber::Subscriber(PubSubSystem& system):
   m_system(system),
   m_mosq(NULL),
   m_loop(0)
{ }

void Subscriber::connect(const PubSubSystem::HostInformation &host)
{
    m_mosq = mosquitto_new(NULL, host.clean_session, this);

    if (mosquitto_connect(m_mosq, host.hostname.c_str(), host.port, host.keepalive))
        throw CppRuntimeException("Subscriber: Could not connect to host");

    mosquitto_message_callback_set(m_mosq, Subscriber::onMessage);
    m_loop = mosquitto_loop_start(m_mosq);

    if (m_loop != MOSQ_ERR_SUCCESS)
        throw CppRuntimeException("Subscriber: Unable to start loop: " + convertToString(m_loop) + "\n");
};

void Subscriber::subscribe(const Topic &topic)
{
    if (std::find(m_topics.begin(), m_topics.end(), &topic)
            == m_topics.end())
    {
        int ret = mosquitto_subscribe(m_mosq, NULL, topic.topic().c_str(),2);
        // TODO Define QoS enum and use it here
        if (ret != MOSQ_ERR_SUCCESS)
            throw CppRuntimeException("Subscription for topic failed.");
        m_topics.push_back(&topic);
    }
}

void Subscriber::unsubscribe(const Topic& topic)
{
    int ret = mosquitto_unsubscribe(m_mosq, NULL, topic.topic().c_str());
    if (ret != MOSQ_ERR_SUCCESS)
        throw CppRuntimeException("Unsubscription failed.");
    m_topics.remove(&topic);
}

void Subscriber::onMessage(mosquitto * moq, void * subscriber, const mosquitto_message* msg)
{
   Subscriber* sub = reinterpret_cast<Subscriber*>(subscriber);
   sub->notifyTopics(msg->topic, reinterpret_cast<uint8_t*>(msg->payload), msg->payloadlen);
}

void Subscriber::notifyTopics(const char *topic, const uint8_t *msgData, size_t msgSize)
{
    for (std::list<const Topic*>::iterator it = m_topics.begin();
         it != m_topics.end(); ++it)
    {
        const Topic* t = *it;
        std::string tAsStr(topic);
        if (t->matches(tAsStr))
            t->onMessageAvailable(msgData, msgSize);
    }
}

}
