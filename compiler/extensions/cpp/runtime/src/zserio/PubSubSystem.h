#ifndef ZSERIO_PUB_SUB_SYSTEM_H_INC
#define ZSERIO_PUB_SUB_SYSTEM_H_INC 
#include <string>

namespace zserio 
{
/** Represents the PubSubSystem of zserio which can be used with different implementations
    Mosquitto MQTT broker ...  */
class PubSubSystem 
{
public:
    typedef size_t SubscriptionId;
    PubSubSystem();
    ~PubSubSystem();
    
    struct HostInformation
    {
        std::string hostname;
        uint32_t	port;
        uint32_t	keepalive;
        bool		clean_session;
    };

private:
    PubSubSystem(const PubSubSystem& pubSub);
    PubSubSystem& operator=(const PubSubSystem& pubSub);
};
}
#endif
