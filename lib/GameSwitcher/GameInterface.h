#pragma once
#ifndef GAMESWITCHER_GAME_INTERFACE
#define GAMESWITCHER_GAME_INTERFACE

namespace GameSwitcher {
  class GameInterface {
   public:
    virtual void loop();
  };
}  // namespace GameSwitcher
#endif
