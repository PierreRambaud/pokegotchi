#include "Pokegotchi.h"
#include "Home.h"

Pokegotchi::Pokegotchi() {
  _home = Home::getInstance();
}

void Pokegotchi::setup() {

}
void Pokegotchi::loop() {
  _home->loop();
}
