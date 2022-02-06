#include <M5Core2.h>
#include "lv_i18n.h"
#include "assets/fonts/pokemon_font.c"
#include "Pokegotchi.h"
#include "Game.h"
#include "Menu.h"
#include "ActionsMenu.h"
#include "Home.h"
#include "Utils.h"

Pokegotchi::Pokegotchi() {}

void Pokegotchi::setup() {
  lv_i18n_init(lv_i18n_language_pack);
  lv_i18n_set_locale("fr");
}

void Pokegotchi::loop() {
  if (Home::getInstance()->isClosed() == false) {
    Home::getInstance()->loop();

    return;
  }

  Game::getInstance()->loop();

  if (M5.BtnA.wasPressed()) {
    Serial.println("Button A pressed");
    ActionsMenu::getInstance()->toggle();
  } else if (M5.BtnB.wasPressed()) {
    Serial.println("Button B pressed");
  } else if (M5.BtnC.wasPressed()) {
    Serial.println("Button C pressed");
    Menu::getInstance()->toggle();
  }
}
