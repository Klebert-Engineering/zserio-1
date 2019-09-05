#ifndef ZSERIO_RTPS_CLIENT_H_INC
#define ZSERIO_RTPS_CLIENT_H_INC

#include "PubSubClient.h"
#include <string>
#include <memory>

namespace zserio
{

    class Topic;

/** Represents the RtpsClient of zserio which provides ROS message support ...  */
    class RtpsClient : public PubSubClient
    {
    public:
        RtpsClient() {}

        /** Clean-up and disconnect on demand.*/
        virtual ~RtpsClient() {}

        RtpsClient(const RtpsClient& pubSub) = delete;
        RtpsClient& operator=(const RtpsClient& pubSub) = delete;
        RtpsClient(RtpsClient&&) = delete;
        RtpsClient& operator=(RtpsClient&&) = delete;

        /** Tries to connect ot the specified host. */
        void connect() override {}

        /** Disconnects from host, if connected otherwise does nothing. */
        void disconnect() override {}

        /** Publishes data using the specified topic */
        void publish(const std::string &topic, const uint8_t* buffer, size_t size, int qos, bool retain) override {}

        /* Subscribe to the specified topic */
        void subscribe(const Topic &topic) override {}

        /* Unsubscribe from specified topic */
        void unsubscribe(const Topic &topic) override {}

    private:
        // struct Impl;
        // std::unique_ptr<Impl> m_impl;
    };
}
#endif
