#ifndef POKEGOTCHI_POKEMON
#define POKEGOTCHI_POKEMON

#define POKEMON_PICHU 172
#define POKEMON_PIKACHU 25
#define POKEMON_RAICHU 26

#define POKEMON_EEVEE 133
#define POKEMON_VAPOREON 134
#define POKEMON_JOLTEON 135
#define POKEMON_FLAREON 136

#include <lvgl.h>
#include "Menu.h"
#include "assets/pokemon/172.c"
#include "assets/pokemon/25.c"
#include "assets/pokemon/26.c"
#include "assets/pokemon/133.c"
#include "assets/pokemon/134.c"
#include "assets/pokemon/135.c"
#include "assets/pokemon/136.c"

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

  const lv_img_dsc_t* get_image() {
    if (_level >= 5){
      return &pokemon_26;
    } else if (_level >= 3) {
      return &pokemon_25;
    } else {
      return &pokemon_172;
    }
  }

 private:
  Pokemon();
  static Pokemon* instance;

  void try_to_evolve() {
    if (_level == 3 || _level == 5) {
      lv_gif_set_src(_image, get_image());
    }
  }

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
