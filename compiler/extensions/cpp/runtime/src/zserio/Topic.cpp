#include "Topic.h"
#include <sstream>

namespace zserio
{

namespace
{
// TODO Migrate to runtime
const std::string SUB_WILDCARD_SINGLE_LEVEL = "+";
}

Topic::Topic(const std::vector<std::string> &topicStr):
    topic_(topicStr)
{}

bool Topic::checkIfAllBound() const
{
    for (auto& el: wildcards_)
        if (el.empty()) return false;
    return true;
}

std::string Topic::topic() const
{
    std::string topic;
    size_t wci = 0;
    for (auto& el: topic_) {
        if (!topic.empty()) topic += "/";
        if (el != SUB_WILDCARD_SINGLE_LEVEL)
            topic += el;
        else
            topic += wildcards_.at(wci++);
    }
    return topic;
}

std::string Topic::unboundTopic() const
{
   std::string topic;
   for (auto& el: topic_){
        if (!topic.empty()) topic += "/";
        topic += el;
   }
   return topic;
}

bool Topic::matches(std::string &topic) const
{
    std::vector<std::string> els;
    std::istringstream ss(topic);
    std::string token;
    while (std::getline(ss, token, '/'))
        els.push_back(token);

    if (topic_.size() != els.size())
        return false;

    for (size_t i=0; i<topic_.size(); ++i){
        if (topic_[i] != SUB_WILDCARD_SINGLE_LEVEL &&
            topic_[i] != els[i])
        {
            return false;
        }
    }

    return true;
}

size_t Topic::numWildcards() const
{
   return wildcards_.size();
}

}
