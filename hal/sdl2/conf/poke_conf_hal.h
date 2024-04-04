#ifndef POKE_CONF_H
#define POKE_CONF_H

#define SDL_HOR_RES 480
#define SDL_VER_RES 320
#define SDL_ZOOM 1

#include "Config.h"

using namespace Pokegotchi;

static poke_config_t* poke_config = new poke_config_t({
    false,
    "/.pokegotchi/saves",
});

#endif
