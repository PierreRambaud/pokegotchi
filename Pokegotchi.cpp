#include <M5Core2.h>
#include "Pokegotchi.h"
#include "Home.h"

Pokegotchi::Pokegotchi() {
  _home = Home::getInstance();
  _menu = Menu::getInstance();
}

void Pokegotchi::setup() {}

void Pokegotchi::loop() {
  if (_home->isClosed() == false) {
    _home->loop();

    return;
  }

  if (M5.BtnA.wasPressed()) {
    Serial.printf("Button A pressed\n\r");
  } else if (M5.BtnB.wasPressed()) {
    Serial.printf("Button B pressed\n\r");
  } else if (M5.BtnC.wasPressed()) {
    Serial.printf("Button C pressed\n\r");
    _menu->toggle();
  }
}
