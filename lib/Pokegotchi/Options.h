#pragma once
#ifndef POKEGOTCHI_OPTIONS
#define POKEGOTCHI_OPTIONS

#include <stdint.h>

#define OPTIONS_BRIGHTNESS_DEFAULT 37
#define OPTIONS_BALL_DEFAULT 7

namespace Pokegotchi {
  struct game_options_struct {
    uint8_t brightness;
    uint8_t ball;
  };

  typedef struct game_options_struct poke_options_t;
}  // namespace Pokegotchi
#endif
