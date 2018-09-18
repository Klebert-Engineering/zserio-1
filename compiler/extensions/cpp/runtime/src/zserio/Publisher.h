#ifndef ZSERIO_PUBLISHER_H_INC
#define ZSERIO_PUBLISHER_H_INC

#include "PubSubSystem.h"

#include <string>
#include <cstddef>
#include <memory>

namespace zserio
{

class Publisher
{
public:
    Publisher(PubSubSystem& system);
    ~Publisher();

    void connect(const PubSubSystem::HostInformation& host);
    void publish(const std::string &topic, const uint8_t* buffer, size_t size, int qos, bool retain);

private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};

}

#endif // ifndef ZSERIO_PUBLISHER_H_INC
