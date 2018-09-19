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

    PubSubClient();

    /** Clean-up and disconnect on demand.*/
    virtual ~PubSubClient();

    PubSubClient(const PubSubClient& pubSub) = delete;
    PubSubClient& operator=(const PubSubClient& pubSub) = delete;
    PubSubClient(PubSubClient&&) = delete;
    PubSubClient& operator=(PubSubClient&&) = delete;
    
    struct HostInformation
    {
        std::string hostname;
        uint32_t	port;
        uint32_t	keepalive;
        bool		clean_session;
        std::string client_id;
    };

    /** Tries to connect ot the specified host. */
    void connect(const PubSubClient::HostInformation& host);

    /** Disconnects from host, if connected otherwise does nothing. */
    void disconnect();

    /** Publishes data using the specified topic */
    void publish(const std::string &topic, const uint8_t* buffer, size_t size, int qos, bool retain);

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
