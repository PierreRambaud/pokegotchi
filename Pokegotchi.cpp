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
    Serial.println("Button A pressed");
    ActionsMenu::getInstance()->toggle();
  } else if (M5.BtnB.wasPressed()) {
    Serial.println("Button B pressed");
  } else if (M5.BtnC.wasPressed()) {
    Serial.println("Button C pressed");
    Menu::getInstance()->toggle();
  }
}
