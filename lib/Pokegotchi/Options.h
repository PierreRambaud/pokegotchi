#pragma once
#ifndef POKEGOTCHI_OPTIONS
#define POKEGOTCHI_OPTIONS

#include <stdint.h>

#define OPTIONS_BRIGHTNESS_DEFAULT 37

namespace Pokegotchi {
  struct game_options_struct {
    int32_t brightness;
  };

  typedef struct game_options_struct poke_options_t;
}  // namespace Pokegotchi
#endif
