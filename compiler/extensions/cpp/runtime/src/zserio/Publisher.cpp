#include <mosquitto.h>
#include "CppRuntimeException.h"
#include "StringConvertUtil.h"
#include "Publisher.h"

namespace zserio
{

Publisher::Publisher(PubSubSystem &system): m_system(system)
{  }

void Publisher::connect(const PubSubSystem::HostInformation &host)
{
    m_mosq = mosquitto_new(NULL, host.clean_session, NULL);

    if (mosquitto_connect(m_mosq, host.hostname.c_str(), host.port, host.keepalive))
        throw CppRuntimeException("Publisher: Could not connect to host");

    m_loop = mosquitto_loop_start(m_mosq);
    if (m_loop != MOSQ_ERR_SUCCESS)
        throw CppRuntimeException("Publisher: Unable to start loop: " + convertToString(m_loop) + "\n");
};

void Publisher::publish(const std::string &topic, const uint8_t* buffer, size_t size, int qos = 0, bool retain = false)
{
    int result = mosquitto_publish(m_mosq, NULL, topic.c_str(), size, reinterpret_cast<const void*>(buffer), qos, retain);
    if (result != MOSQ_ERR_SUCCESS)
        throw CppRuntimeException("Publisher: MQTT send error:  " + convertToString(result) + "\n");
};

}
