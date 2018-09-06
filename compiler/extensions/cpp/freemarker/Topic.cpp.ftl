<#include "FileHeader.inc.ftl">
<@file_header generatorDescription/>

#include <zserio/Publisher.h>
#include <zserio/Subscriber.h>

<@user_include package.path, "${name}.h"/>
<@user_includes cppUserIncludes, false/>

<@namespace_begin package.path/>

${name}::${name}()
    : Topic(std::vector<std::string>({{<#list topicNameParts as part>"${part}"<#sep>, </#list>}}))
{
}

${name}::${name}(const std::array<std::string, ${numWildcards}> &wildcards)
    : ${name}()
{
    wildcards_ = std::vector<std::string>(wildcards.begin(), wildcards.end());
}

void ${name}::publish(::zserio::Publisher &pub,
        ${valueTypeName} &pl,
        int qualityOfService = 2,
        bool retain = false) const
{
    Topic::publish(pub, pl, qualityOfService, retain);
}

zserio::PubSubSystem::SubscriptionId ${name}::subscribe(
        ::zserio::Subscriber &sub,
        const ${name}::OnPayloadAvailable& lambda)
{
    sub.subscribe(*this);
    subscribers_[nextId_] = lambda;
    return nextId_++;
}

void ${name}::unsubscribe(
        zserio::Subscriber &sub,
        zserio::PubSubSystem::SubscriptionId id)
{
    auto it = subscribers_.find(id);
    if (it != subscribers_.end()) {
        subscribers_.erase(it);
        if (subscribers_.empty())
            sub.unsubscribe(*this);
    }
}

void ${name}::notifySubscribers(${valueTypeName} &&pl) const
{
    for (auto& sub: subscribers_)
        sub.second(pl);
}

void ${name}::onMessageAvailable(const uint8_t * msgData, size_t  size) const
{
    notifySubscribers(dataToSzerio<${valueTypeName}>(msgData, size));
}

<@namespace_end package.path/>
