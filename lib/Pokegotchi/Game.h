#ifndef POKEGOTCHI_GAME
#define POKEGOTCHI_GAME

#include <vector>
#include <lvgl.h>
#include "Menu.h"
#include "Pokemon.h"

class Game {
 public:
  void setup(Pokemon* p);
  void loop();
  void switch_to_day();
  void switch_to_night();

  static Game* getInstance() {
    if (instance == nullptr) {
      instance = new Game();
    }

    return instance;
  }

  void action_eat(Item* item);
  void action_clean();
  void action_heal();
  void action_play();
  void action_train();
  void action_sleep();
  void action_wake_up();

  void create_poo();
  void create_pee();

  void abort_actions();
  void try_to_clean();

 private:
  Game();

  static Game* instance;

  lv_obj_t* _pokemon_image;
  lv_obj_t* _screen;
  lv_anim_t _anim;

  lv_obj_t* _level_indic;

  lv_obj_t* _mood_bar;
  lv_obj_t* _sleepiness_bar;
  lv_obj_t* _hunger_bar;
  lv_obj_t* _life_bar;

  lv_obj_t* _clean;

  std::vector<lv_obj_t*> _poos;
  std::vector<lv_obj_t*> _pees;
};
#endif
