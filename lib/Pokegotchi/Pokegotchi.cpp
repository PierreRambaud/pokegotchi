#include "M5Core2.h"
#include "Pokegotchi.h"
#include "Game.h"
#include "ActionsMenu.h"
#include "GameMenu.h"
#include "Utils.h"

using namespace Pokegotchi;

void prepare_sd_card_directory(poke_config_t*);

Runner::Runner() {
  _config = new poke_config_t{hal_start_storage(), "/.pokegotchi", "/.pokegotchi/saves"};

  prepare_sd_card_directory(_config);

  lv_obj_t* main_screen = create_screen();
  lv_screen_load(main_screen);

  Home* home = new Home(_config, main_screen);
  Home::setInstance(home);
  _home = home;
}

void Runner::loop() {
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

  if (M5.BtnA.wasPressed()) {
    serial_printf("Runner", "Button A pressed");
    ActionsMenu::getInstance()->toggle();
    GameMenu::getInstance()->close();
  } else if (M5.BtnB.wasPressed()) {
    serial_printf("Runner", "Button B pressed");
    Game::getInstance()->abort_actions();
  } else if (M5.BtnC.wasPressed()) {
    serial_printf("Runner", "Button C pressed");
    ActionsMenu::getInstance()->close();
    GameMenu::getInstance()->toggle();
  }
}

void prepare_sd_card_directory(poke_config_t* global_config) {
  if (!global_config->use_sd_card) {
    return;
  }

  serial_printf("Runner", "SD card available!");
  File entry = SD.open(global_config->sd_directory_path);
  if (entry && !entry.isDirectory()) {
    entry.close();
    SD.remove(global_config->sd_directory_path);
  }

  entry = SD.open(global_config->sd_directory_path);
  if (!entry) {
    SD.mkdir(global_config->sd_directory_path);
    SD.mkdir(global_config->save_files_path);
    serial_printf("Runner", "Directory %s created", global_config->sd_directory_path);
  }

  SD.end();
}
