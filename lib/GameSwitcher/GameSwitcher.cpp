#include "GameSwitcher.h"
#include <lv_i18n.h>
#include <Pokegotchi.h>
#include <FloppyBird.h>
#include <DrawingBoard.h>

using namespace GameSwitcher;

Runner* Runner::_instance = nullptr;

Runner::Runner() {
  lv_i18n_init(lv_i18n_language_pack);
  lv_i18n_set_locale("fr");

  _game_instance = new Pokegotchi::Runner();
}

void Runner::switch_game(int8_t game) {
  switch (game) {
    case GAME_FLOPPYBIRD:
      _game_instance = new FloppyBird::Runner();
      break;
    case GAME_DRAWING_BOARD:
      _game_instance = new DrawingBoard::Runner();
      break;
  }
}

void Runner::loop() { _game_instance->loop(); }
