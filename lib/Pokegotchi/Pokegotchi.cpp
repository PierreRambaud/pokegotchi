#include <M5Core2.h>
#include "lv_i18n.h"
#include "Pokegotchi.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "Home.h"
#include "Utils.h"

Pokegotchi::Pokegotchi() {}

void Pokegotchi::setup() {
  lv_i18n_init(lv_i18n_language_pack);
  lv_i18n_set_locale("fr");

  Config* c = Config::getInstance();
  if (c->is_sd_card_available) {
    Serial.println("SD card available!");
    File entry = SD.open(c->sd_directory_path);
    if (entry && !entry.isDirectory()) {
      entry.close();
      SD.remove(c->sd_directory_path);
    }

    entry = SD.open(c->sd_directory_path);
    if (!entry) {
      SD.mkdir(c->sd_directory_path);
      Serial.printf("Directory %s created\n", c->sd_directory_path);
    } else {
      Serial.printf("Directory %s already exists\n", c->sd_directory_path);
    }
  }
}

void Pokegotchi::loop() {
  if (Home::getInstance()->isClosed() == false) {
    Home::getInstance()->loop();

    return;
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
  } else if (M5.BtnC.wasPressed()) {
    Serial.println("Button C pressed");
    ActionsMenu::getInstance()->close();
    Menu::getInstance()->toggle();
  }
}
