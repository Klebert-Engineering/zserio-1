<#include "FileHeader.inc.ftl">
<@file_header generatorDescription/>

#include <zserio/PubSubClient.h>

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

void ${name}::publish(::zserio::PubSubClient &pub,
        ${valueTypeName} &pl,
        int qualityOfService = 2,
        bool retain = false) const
{
    Topic::publish(pub, pl, qualityOfService, retain);
}

zserio::PubSubClient::SubscriptionId ${name}::subscribe(
        ::zserio::PubSubClient &sub,
        const ${name}::OnPayloadAvailable& lambda)
{
    auto id = Topic::subscribe(sub);
    subscribers_[id] = lambda;
    return id;
}

void ${name}::unsubscribe(
        zserio::PubSubClient &sub,
        zserio::PubSubClient::SubscriptionId id)
{
    auto it = subscribers_.find(id);
    if (it != subscribers_.end()) {
        subscribers_.erase(it);
        if (subscribers_.empty())
            sub.unsubscribe(*this);
    }
}

void ${name}::onMessageAvailable(const std::string& topic, const uint8_t * msgData, size_t  size) const
{
    auto pl = dataToSzerio<${valueTypeName}>(msgData, size);
    for (auto& sub: subscribers_)
        sub.second(topic, pl);
}

<@namespace_end package.path/>
