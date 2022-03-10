#pragma once
#ifndef POKEGOTCHI_OPTIONS
#define POKEGOTCHI_OPTIONS

#include <stdint.h>

namespace Pokegotchi {
  struct options_struct {
    int32_t brightness;
  };

  typedef struct options_struct Options;

  static Options* global_options = new Options{37};
}
#endif
