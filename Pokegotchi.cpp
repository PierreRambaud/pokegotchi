#include "Pokegotchi.h"
#include "Home.h"

Pokegotchi::Pokegotchi() {
  _home = new Home();
}

void Pokegotchi::setup() {

}
void Pokegotchi::loop() {
  _home->loop();
}
