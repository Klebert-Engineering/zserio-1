#ifndef ZSERIO_PUBLISHER_H_INC
#define ZSERIO_PUBLISHER_H_INC

#include "PubSubSystem.h"

#include <string>
#include <cstddef>

namespace zserio
{

class Publisher
{
public:
    Publisher(PubSubSystem& system);

    void connect(const PubSubSystem::HostInformation& host);
    void publish(const std::string &topic, const uint8_t* buffer, size_t size, int qos, bool retain);

private:
    PubSubSystem& m_system;
    struct mosquitto* m_mosq;
    int m_loop;
};

}

#endif // ifndef ZSERIO_PUBLISHER_H_INC
