#include <M5Core2.h>
#include "lv_i18n.h"
#include "Runner.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "Home.h"
#include "Utils.h"

using namespace Pokegotchi;

void prepare_sd_card_directory();

Runner::Runner() {
  prepare_sd_card_directory();

  lv_i18n_init(lv_i18n_language_pack);
  lv_i18n_set_locale("fr");

  lv_obj_t* screen = create_window();
  lv_scr_load(screen);

  _home = Home::getInstance();
}

void Runner::loop() {
  if (_home != nullptr) {
    if (_home->isClosed() == false) {
      _home->loop();

      return;
    }

    _home = nullptr;
  }

  Game::getInstance()->loop();
  if (check_action_time(_last_refresh_time, PERIOD_REFRESH)) {
    Menu::getInstance()->refresh_battery_status();
  }

  if (M5.BtnA.wasPressed()) {
    Serial.println("Button A pressed");
    Menu::getInstance()->close();
    ActionsMenu::getInstance()->toggle();
  } else if (M5.BtnB.wasPressed()) {
    Serial.println("Button B pressed");
    Game::getInstance()->abort_actions();
  } else if (M5.BtnC.wasPressed()) {
    Serial.println("Button C pressed");
    ActionsMenu::getInstance()->close();
    Menu::getInstance()->toggle();
  }
}

void prepare_sd_card_directory() {
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
