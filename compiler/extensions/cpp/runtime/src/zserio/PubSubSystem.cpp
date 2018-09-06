#include "PubSubSystem.h"
#include <mosquitto.h>

namespace zserio
{

PubSubSystem::PubSubSystem()
{
    mosquitto_lib_init();
}

PubSubSystem::~PubSubSystem()
{
    mosquitto_lib_cleanup();
}

}
