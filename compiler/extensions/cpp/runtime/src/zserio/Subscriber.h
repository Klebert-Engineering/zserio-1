#ifndef ZSERIO_SUBSCRIBER_H_INC
#define ZSERIO_SUBSCRIBER_H_INC
#include <list>
#include <memory>

#include "Topic.h"
#include "PubSubSystem.h"

namespace zserio
{

class Subscriber 
{
public:
    Subscriber(PubSubSystem& system);
    ~Subscriber();

    /* Connect this subscriber to the specified host */
    void connect(const PubSubSystem::HostInformation& host);

    /* Subscribe to the specified topic */
    void subscribe(const Topic &topic);

    /* Unsubscribe from specified topic */
    void unsubscribe(const Topic &topic);

private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};
}
#endif
