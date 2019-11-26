#ifndef ZSERIO_TOPIC_H_INC
#define ZSERIO_TOPIC_H_INC

#include "PubSubClient.h"
#include "CppRuntimeException.h"
#include "BitStreamWriter.h"
#include "BitStreamReader.h"

#include <string>
#include <vector>

namespace zserio 
{
class Topic 
{
public:
    Topic (const std::vector<std::string>& topicStr);

    /** Checks if the specified topic string is matched by this topic class */
    bool matches(std::string& topic) const;

    /** Returns the number of wildcards */
    size_t numWildcards() const;

    /** Returns the topic as string with all values bound based on user calls*/
    std::string topic() const;

    /** Returns the originally topic string without any binding */
    std::string unboundTopic() const;

    /** Gets called when message with compatible topic has arrived */
    virtual void onMessageAvailable(const std::string& topic, const uint8_t* msgData, size_t msgSize) const = 0;

    /** Activate subscription for this topic at the provided PubSubClient */
    PubSubClient::SubscriptionId subscribe(PubSubClient& sub);

protected:
    template<class T>
    void publish(zserio::PubSubClient &pub, T &pl, int qualityOfService = 2, bool retain = false) const
    {
        if (!checkIfAllBound())
            throw zserio::CppRuntimeException("Tried to publish a message with topic that contains wildcards.");

        zserio::BitStreamWriter writer;
        pl.write(writer);
        size_t bufSize;
        auto buffer = writer.getWriteBuffer(bufSize);
        auto t = topic();
        pub.publish(t, buffer, bufSize, qualityOfService, retain);
    }

    template<class T>
    T dataToSzerio(const uint8_t* msgData, size_t size) const
    {
       T data;
       zserio::BitStreamReader reader(msgData, size);
       data.read(reader);
       return data;
    }

    bool checkIfAllBound() const;

protected:
    std::vector<std::string> wildcards_ = {{""}};

private:
    PubSubClient::SubscriptionId nextId_ = 0;
    const std::vector<std::string> topic_;
};

}
#endif
