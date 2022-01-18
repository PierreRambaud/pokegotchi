#pragma once
#include "Home.h"

class Pokegotchi {
 public:
  Pokegotchi();
  void setup();
  void loop();

 protected:
  Home * _home;
};
