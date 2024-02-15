#include "Pokegotchi.h"
#include "Game.h"
#include "ActionsMenu.h"
#include "GameMenu.h"
#include "Utils.h"
#include "conf/poke_conf_hal.h"
#include "storage_hal.h"
#include "keyboard_hal.h"

using namespace Pokegotchi;

void prepare_storage_directory(poke_config_t*);

Runner::Runner(void) {
  _config = poke_config;

  prepare_storage_directory(_config);

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

  Game::getInstance()->loop();
  if (check_action_time(_last_refresh_time, PERIOD_REFRESH)) {
    ActionsMenu::getInstance()->get_menu()->refresh_battery_status();
    GameMenu::getInstance()->get_menu()->refresh_battery_status();
  }

  if (hal_button_a_pressed()) {
    serial_printf("Runner", "Button A pressed");
    ActionsMenu::getInstance()->toggle();
    GameMenu::getInstance()->close();
  } else if (hal_button_b_pressed()) {
    serial_printf("Runner", "Button B pressed");
    Game::getInstance()->abort_actions();
  } else if (hal_button_c_pressed()) {
    serial_printf("Runner", "Button C pressed");
    ActionsMenu::getInstance()->close();
    GameMenu::getInstance()->toggle();
  }
}

void prepare_storage_directory(poke_config_t* global_config) {
  if (!global_config->use_storage) {
    return;
  }

  serial_printf("Runner", "Storage available");
  hal_prepare_storage(global_config);
}
