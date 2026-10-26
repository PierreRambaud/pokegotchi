#pragma once
#ifndef GAMESWITCHER_RUNNER
#define GAMESWITCHER_RUNNER

#include <stdint.h>
#include "GameInterface.h"

#define GAME_POKEGOTCHI 1
#define GAME_DRAWING_BOARD 2
#define GAME_FLOPPYBIRD 3
#define GAME_SKYRACE 4

namespace GameSwitcher {
  class Runner {
   public:
    explicit Runner(void);
    void loop(void);

    // Switch at the end of the loop: a game must never be deleted while one
    // of its own callbacks is running
    void request_switch(int8_t game) { _pending_game = game; }

    // A mini-game is over: go back to the Pokemon with its score
    void finish_minigame(int32_t score);
    bool take_minigame_result(int32_t* score);

    static Runner* getInstance(void) { return _instance; }
    static void setInstance(Runner* instance) { _instance = instance; }

   private:
    void switch_game(int8_t game);

    static Runner* _instance;
    GameInterface* _game_instance;
    int8_t _pending_game = 0;
    bool _has_minigame_result = false;
    int32_t _minigame_score = 0;
  };
}  // namespace GameSwitcher
#endif
