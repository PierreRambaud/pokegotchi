#pragma once
#ifndef POKEGOTCHI_PET_CLOCK
#define POKEGOTCHI_PET_CLOCK

#include <stdint.h>

namespace Pokegotchi {
  // Hour of the day of the Pokemon (its own clock), for the mini-games to
  // show the same sky. Noon when there is no Pokemon.
  uint8_t pet_hour(void);
}  // namespace Pokegotchi
#endif
