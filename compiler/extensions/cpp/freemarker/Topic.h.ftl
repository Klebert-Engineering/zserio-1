<#include "FileHeader.inc.ftl">
<@file_header generatorDescription/>

<@include_guard_begin package.path, name/>

#include <zserio/Topic.h>
#include <zserio/PubSubSystem.h>

#include <functional>
#include <string>
#include <array>
#include <map>

<@system_includes headerSystemIncludes/>
<@user_includes headerUserIncludes, true/>

namespace zserio
{
class Publisher;
class Subscriber;
}

<@namespace_begin package.path/>

class ${name} final : public zserio::Topic
{
public:
    /** Keep the topic string as it is, no bound wildcards */
    ${name}();
    /** Bind the wildcards (needed for publishing) */
    ${name}(const std::array<std::string, ${numWildcards}>& wildcards);

    /** Publishes Payload pl using the provided Publisher pub */
    void publish(zserio::Publisher& pub, ${valueTypeName} &pl, int qualityOfService, bool retain) const;

    /** Subscribe to this topic get notifications if payload is available */
    using OnPayloadAvailable = std::function<void(const ${valueTypeName}& pl)>;
    zserio::PubSubSystem::SubscriptionId subscribe(zserio::Subscriber& sub, const OnPayloadAvailable& callback);
    void unsubscribe(zserio::Subscriber& sub, zserio::PubSubSystem::SubscriptionId id);

    /** Gets invoked when message with compatible topic is available */
    void onMessageAvailable(const uint8_t *msgData, size_t size) const override;

private:
    void notifySubscribers(${valueTypeName} &&pl) const;

private:
    // TODO As soon as zserio runtime allows C++11 subscription functionality could also migrated
    zserio::PubSubSystem::SubscriptionId nextId_ = 0;
    std::map<zserio::PubSubSystem::SubscriptionId, OnPayloadAvailable> subscribers_;
};

<@namespace_end package.path/>

<@include_guard_end package.path, name/>
