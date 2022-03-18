#include <M5Core2.h>
#include "lv_i18n.h"
#include "Runner.h"
#include "Game.h"
#include "ActionsMenu.h"
#include "GameMenu.h"
#include "Utils.h"

using namespace Pokegotchi;

void prepare_sd_card_directory(poke_config_t*);

Runner::Runner() {
  _config = new poke_config_t{"/.pokegotchi", "/.pokegotchi/pokegotchi.json"};

  prepare_sd_card_directory(_config);
  lv_i18n_init(lv_i18n_language_pack);
  lv_i18n_set_locale("fr");

  lv_obj_t* main_screen = create_screen();
  lv_scr_load(main_screen);

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
    Serial.println("Button A pressed");
    ActionsMenu::getInstance()->toggle();
    GameMenu::getInstance()->close();
  } else if (M5.BtnB.wasPressed()) {
    Serial.println("Button B pressed");
    Game::getInstance()->abort_actions();
  } else if (M5.BtnC.wasPressed()) {
    Serial.println("Button C pressed");
    ActionsMenu::getInstance()->close();
    GameMenu::getInstance()->toggle();
  }
}

void prepare_sd_card_directory(poke_config_t* global_config) {
  if (sd_begin() == false) {
    return;
  }

  Serial.println("SD card available!");
  File entry = SD.open(global_config->sd_directory_path);
  if (entry && !entry.isDirectory()) {
    entry.close();
    SD.remove(global_config->sd_directory_path);
  }

  entry = SD.open(global_config->sd_directory_path);
  if (!entry) {
    SD.mkdir(global_config->sd_directory_path);
    Serial.printf("Directory %s created\n", global_config->sd_directory_path);
  }

  SD.end();
}
