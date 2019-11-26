#ifndef ZSERIO_PUB_SUB_SYSTEM_H_INC
#define ZSERIO_PUB_SUB_SYSTEM_H_INC 

#include <string>
#include <memory>

namespace zserio 
{

class Topic;

/** Represents the PubSubClient of zserio which can be used with different implementations
    Mosquitto MQTT broker ...  */
class PubSubClient
{
public:
    using SubscriptionId = size_t;

    /** Tries to connect ot the specified host. */
    virtual void connect() = 0;

    /** Disconnects from host, if connected otherwise does nothing. */
    virtual void disconnect() = 0;

    /** Publishes data using the specified topic */
    virtual void publish(const std::string &topic,
                         const uint8_t* buffer,
                         size_t size,
                         int qos,
                         bool retain) = 0;

    /* Subscribe to the specified topic */
    virtual void subscribe(const Topic &topic) = 0;

    /* Unsubscribe from specified topic */
    virtual void unsubscribe(const Topic &topic) = 0;

};
}
#endif
