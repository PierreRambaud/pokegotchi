#ifndef POKE_CONF_H
#define POKE_CONF_H

#define ARDUINO_M5STACK_Core2
#define POKEGOTCHI_BATTERY

#define POKEGOTCHI_INCLUDE_GAMES

#include "Config.h"
#include "storage_hal.h"

using namespace Pokegotchi;

static poke_config_t* poke_config = new poke_config_t({
    hal_start_storage(),
    "/.pokegotchi/saves",
});

#endif
