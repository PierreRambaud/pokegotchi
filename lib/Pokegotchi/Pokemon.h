#ifndef POKEGOTCHI_POKEMON
#define POKEGOTCHI_POKEMON

#include <lvgl.h>
#include "Menu.h"

const int8_t MAX_LIFE = 100;
const int8_t MAX_SLEEPINESS = 100;
const int8_t MAX_MOOD = 10;
const int8_t MAX_HUNGER = 20;

class Pokemon {
 public:
  void loop();

  static Pokemon* getInstance() {
    if (instance == nullptr) {
      instance = new Pokemon();
    }

    return instance;
  }

  int8_t get_level() { return _level; }
  int8_t get_life() { return _life; }
  int8_t get_mood() { return _mood; }
  int8_t get_hunger() { return _hunger; }
  int8_t get_sleepiness() { return _sleepiness; }

  bool is_sick() { return _is_sick; }
  bool is_sleeping() { return _is_sleeping; }

  void eat(Item* item);
  void heal(int8_t number);
  void train();
  void play();
  void sleep();
  void wake_up();
  void tiredness(int8_t number);
  void boredom(int8_t number);
  void hungry(int8_t number);

 private:
  Pokemon();
  static Pokemon* instance;

  const char* _name;

  int8_t _level = 1;
  int8_t _sleepiness = 0;
  int8_t _life = MAX_LIFE;
  int8_t _mood = MAX_MOOD;
  int8_t _hunger = 0;

  bool _is_sleeping = false;
  bool _is_sick = false;

  lv_obj_t* _image;
};
#endif
