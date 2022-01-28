#include <M5Core2.h>
#include "Pokegotchi.h"
#include "Game.h"
#include "Menu.h"
#include "ActionsMenu.h"
#include "Home.h"

Pokegotchi::Pokegotchi() {}

void Pokegotchi::setup() {}

void Pokegotchi::loop() {
  if (Home::getInstance()->isClosed() == false) {
    Home::getInstance()->loop();

    return;
  }

  Game::getInstance()->loop();

  if (M5.BtnA.wasPressed()) {
    Serial.printf("Button A pressed\n\r");
    ActionsMenu::getInstance()->toggle();
  } else if (M5.BtnB.wasPressed()) {
    Serial.printf("Button B pressed\n\r");
  } else if (M5.BtnC.wasPressed()) {
    Serial.printf("Button C pressed\n\r");
    Menu::getInstance()->toggle();
  }
}
