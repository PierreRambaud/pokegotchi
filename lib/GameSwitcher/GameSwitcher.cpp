#include "GameSwitcher.h"
#include "lv_i18n.h"
#include "Pokegotchi.h"

#ifdef POKEGOTCHI_INCLUDE_GAMES
#include "FloppyBird.h"
#include "DrawingBoard.h"
#endif

using namespace GameSwitcher;

Runner* Runner::_instance = nullptr;

Runner::Runner(void) {
  lv_i18n_init(lv_i18n_language_pack);
  lv_i18n_set_locale(POKEGOTCHI_DEFAULT_LOCALE);

  _game_instance = new Pokegotchi::Runner();
}

void Runner::switch_game(int8_t game) {
#ifdef POKEGOTCHI_INCLUDE_GAMES
  if (_game_instance != nullptr) {
    _game_instance->close();
    delete _game_instance;
  }

  switch (game) {
    case GAME_FLOPPYBIRD:
      _game_instance = new FloppyBird::Runner();
      break;
    case GAME_DRAWING_BOARD:
      _game_instance = new DrawingBoard::Runner();
      break;
  }
#endif
}

void Runner::loop(void) { _game_instance->loop(); }
