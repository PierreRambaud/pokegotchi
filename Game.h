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

  void action_eat();
  void action_heal();
  void action_train();
  void action_sleep();
  void action_wakeup();

 private:
  Game();

  static Game* instance;

  lv_obj_t* _screen;
  lv_obj_t* _background;
  lv_anim_t _anim;

  lv_obj_t* _mood_bar;
  lv_obj_t* _sleepiness_bar;
  lv_obj_t* _hunger_bar;
  lv_obj_t* _life_bar;

  long unsigned _last_eat_time;
  long unsigned _last_sleep_time;
  long unsigned _last_hunger_time;
};
#endif
