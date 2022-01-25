#ifndef POKEGOTCHI_GAME
#define POKEGOTCHI_GAME

#include <lvgl.h>
#include "Pokemon.h"

class Game {
 public:
  void setup();
  void loop();
  void switch_to_day();
  void switch_to_night();

  static Game* getInstance() {
    if (instance == nullptr) {
      instance = new Game();
    }

    return instance;
  }

 private:
  Game();

  static Game* instance;

  lv_obj_t* _screen;
  lv_obj_t* _background;
  lv_anim_t _anim;
};
#endif
