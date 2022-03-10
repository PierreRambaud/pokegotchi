#pragma once
#ifndef POKEGOTCHI_RUNNER
#define POKEGOTCHI_RUNNER

#include "Home.h"

namespace Pokegotchi {
  const unsigned long PERIOD_REFRESH = 20 * 1000UL;

  class Runner {
  public:
    Runner();
    void loop();

  private:
    long unsigned _last_refresh_time = 0;
    Home* _home = nullptr;
  };
}
#endif
