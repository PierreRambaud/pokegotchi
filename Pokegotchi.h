#ifndef POKEGOTCHI_POKEGOTCHI
#define POKEGOTCHI_POKEGOTCHI

#include "Home.h"
#include "Menu.h"

class Pokegotchi {
 public:
  Pokegotchi();
  void setup();
  void loop();

 protected:
  Home* _home;
  Menu* _menu;
};
#endif
