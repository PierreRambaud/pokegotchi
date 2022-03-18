#pragma once
#ifndef POKEGOTCHI_RUNNER
#define POKEGOTCHI_RUNNER

#include "Home.h"
#include "Config.h"

namespace Pokegotchi {
  const unsigned long PERIOD_REFRESH = 5 * 1000UL;

  class Runner {
   public:
    Runner();
    void loop();

   private:
    long _last_refresh_time = 0;
    Home* _home = nullptr;
    poke_config_t* _config = nullptr;
  };
}  // namespace Pokegotchi
#endif
