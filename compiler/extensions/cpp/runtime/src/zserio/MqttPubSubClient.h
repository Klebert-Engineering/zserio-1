#ifndef ZSERIO_MQTT_PUB_SUB_SYSTEM_H_INC
#define ZSERIO_MQTT_PUB_SUB_SYSTEM_H_INC

#include "PubSubClient.h"
#include <string>
#include <memory>

namespace zserio
{

class Topic;

/** Represents the MqttPubSubClient of zserio which provides MQTT support ...  */
class MqttPubSubClient: public PubSubClient
{
public:
    using SubscriptionId = size_t;

    struct HostInformation
    {
        std::string hostname;
        uint32_t	port;
        uint32_t	keepalive;
        bool		clean_session;
        std::string client_id;
    };

    MqttPubSubClient(const MqttPubSubClient::HostInformation& host);

    /** Clean-up and disconnect on demand.*/
    virtual ~MqttPubSubClient();

    MqttPubSubClient(const MqttPubSubClient& pubSub) = delete;
    MqttPubSubClient& operator=(const MqttPubSubClient& pubSub) = delete;
    MqttPubSubClient(MqttPubSubClient&&) = delete;
    MqttPubSubClient& operator=(MqttPubSubClient&&) = delete;

    /** Tries to connect ot the specified host. */
    void connect() override;

    /** Disconnects from host, if connected otherwise does nothing. */
    void disconnect() override;

    /** Publishes data using the specified topic */
    void publish(const std::string &topic, const uint8_t* buffer, size_t size, int qos, bool retain) override;

    /* Subscribe to the specified topic */
    void subscribe(const Topic &topic) override;

    /* Unsubscribe from specified topic */
    void unsubscribe(const Topic &topic) override;

private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};
}
#endif
