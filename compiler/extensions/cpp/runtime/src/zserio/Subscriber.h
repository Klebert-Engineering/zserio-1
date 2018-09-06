#ifndef ZSERIO_SUBSCRIBER_H_INC
#define ZSERIO_SUBSCRIBER_H_INC
#include <list>

#include "Topic.h"
#include "PubSubSystem.h"

namespace zserio
{

class Subscriber 
{
public:
    Subscriber(PubSubSystem& system);

    void connect(const PubSubSystem::HostInformation& host);

    void subscribe(const Topic &topic);
    void unsubscribe(const Topic &topic);

    static void onMessage(struct mosquitto *, void *, const struct mosquitto_message *);

private:
    void notifyTopics(const char* topic, const uint8_t* msgData, size_t msgSize);

private:
    PubSubSystem& m_system;
    std::list<const Topic*> m_topics;
    struct mosquitto* m_mosq;
    int m_loop;
};
}
#endif
