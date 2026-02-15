#pragma once
#ifndef GAMESWITCHER_GAME_INTERFACE
#define GAMESWITCHER_GAME_INTERFACE

namespace GameSwitcher {
  class GameInterface {
   public:
    virtual void loop() = 0;
    virtual void close() = 0;
  };
}  // namespace GameSwitcher
#endif
