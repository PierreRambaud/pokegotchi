#include "Pokegotchi.h"
#include "Utils.h"
#include "conf/poke_conf_hal.h"

using namespace Pokegotchi;

Runner::Runner(void) {
  _config = poke_config;

  lv_obj_t* main_screen = create_screen();
  lv_screen_load(main_screen);

  Home* home = new Home(_config, main_screen);
  Home::setInstance(home);
  _home = home;
}

void Runner::loop(void) {
  if (_home != nullptr) {
    if (_home->isClosed() == false) {
      _home->load_buttons();

      return;
    }

    _home = nullptr;
  }
}
