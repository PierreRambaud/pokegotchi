#ifndef POKE_CONF_H
#define POKE_CONF_H

#define POKEGOTCHI_BATTERY

#include "Config.h"

using namespace Pokegotchi;

static poke_config_t* poke_config = new poke_config_t({
    false,
    "/.pokegotchi/saves",
});

#endif
