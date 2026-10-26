#pragma once
#ifndef POKEGOTCHI_RUNNER
#define POKEGOTCHI_RUNNER

#include "GameInterface.h"
#include "Home.h"
#include "Config.h"
#include "Options.h"

namespace Pokegotchi {
  const unsigned long PERIOD_REFRESH = 5 * 1000UL;
  const unsigned long IDLE_DIM_DELAY = 60 * 1000UL;
  const int32_t IDLE_BRIGHTNESS = 8;

  class Runner : public GameSwitcher::GameInterface {
   public:
    // Resume: back from a mini-game, the Pokemon is still in memory
    explicit Runner(bool resume);
    void loop(void);
    void close(void);

   private:
    void update_idle_dimming(void);

    // Options of the running game, kept while a mini-game is played
    static poke_options_t* _resume_options;

    unsigned long _last_activity = 0;
    bool _dimmed = false;
    long _last_refresh_time = 0;
    poke_config_t* _config = nullptr;
  };
}  // namespace Pokegotchi
#endif
