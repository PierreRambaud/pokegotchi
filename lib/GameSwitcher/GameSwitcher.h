#pragma once
#ifndef GAMESWITCHER_RUNNER
#define GAMESWITCHER_RUNNER

#include <stdint.h>
#include "GameInterface.h"

#define GAME_POKEGOTCHI 1
#define GAME_DRAWING_BOARD 2
#define GAME_FLOPPYBIRD 3

namespace GameSwitcher {
  class Runner {
   public:
    explicit Runner(void);
    void loop(void);
    void switch_game(int8_t game);
    static Runner* getInstance(void) { return _instance; }
    static void setInstance(Runner* instance) { _instance = instance; }

   private:
    static Runner* _instance;
    GameInterface* _game_instance;
  };
}  // namespace GameSwitcher
#endif
