#ifndef ZSERIO_ROS_PUB_SUB_SYSTEM_H_INC
#define ZSERIO_ROS_PUB_SUB_SYSTEM_H_INC

#include "PubSubClient.h"
#include <string>
#include <memory>

namespace zserio
{

class Topic;

/** Represents the RosPubSubClient of zserio which provides ROS message support ...  */
class RosPubSubClient: public PubSubClient
{
public:
    using SubscriptionId = size_t;

    struct HostInformation
    {
        std::string client_id;
        std::string nodeName;
        std::string nodeSubname;
    };

    RosPubSubClient(const RosPubSubClient::HostInformation& host);

    /** Clean-up and disconnect on demand.*/
    virtual ~RosPubSubClient();

    RosPubSubClient(const RosPubSubClient& pubSub) = delete;
    RosPubSubClient& operator=(const RosPubSubClient& pubSub) = delete;
    RosPubSubClient(RosPubSubClient&&) = delete;
    RosPubSubClient& operator=(RosPubSubClient&&) = delete;

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
