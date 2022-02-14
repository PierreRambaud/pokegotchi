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
#include "lv_i18n.h"
#include "Menu.h"

LV_IMG_DECLARE(pokemon_25);
LV_IMG_DECLARE(pokemon_26);
LV_IMG_DECLARE(pokemon_133);
LV_IMG_DECLARE(pokemon_134);
LV_IMG_DECLARE(pokemon_135);
LV_IMG_DECLARE(pokemon_136);
LV_IMG_DECLARE(pokemon_172);
LV_IMG_DECLARE(pokemon_face_25);
LV_IMG_DECLARE(pokemon_face_26);
LV_IMG_DECLARE(pokemon_face_133);
LV_IMG_DECLARE(pokemon_face_134);
LV_IMG_DECLARE(pokemon_face_135);
LV_IMG_DECLARE(pokemon_face_136);
LV_IMG_DECLARE(pokemon_face_172);



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

  int get_pokemon_type() {
    if (_level >= 5) {
      return POKEMON_RAICHU;
    }

    if (_level >= 3) {
      return POKEMON_PIKACHU;
    }

    return POKEMON_PICHU;
  }

  const lv_img_dsc_t* get_image() {
    int type = get_pokemon_type();
    switch(type) {
      case POKEMON_PICHU:
        return &pokemon_172;

      case POKEMON_PIKACHU:
        return &pokemon_25;

      case POKEMON_RAICHU:
        return &pokemon_26;
    }
  }

  const lv_img_dsc_t* get_avatar() {
    int type = get_pokemon_type();
    switch(type) {
      case POKEMON_PICHU:
        return &pokemon_face_172;

      case POKEMON_PIKACHU:
        return &pokemon_face_25;

      case POKEMON_RAICHU:
        return &pokemon_face_26;
    }
  }

  const char* get_description() {
    int type = get_pokemon_type();
    switch(type) {
      case POKEMON_PICHU:
        return _("pokemon.pichu.description");

      case POKEMON_PIKACHU:
        return _("pokemon.pikachu.description");

      case POKEMON_RAICHU:
        return _("pokemon.raichu.description");
    }
  }

  const char* get_name() {
    int type = get_pokemon_type();
    switch(type) {
      case POKEMON_PICHU:
        return _("pokemon.pichu.name");

      case POKEMON_PIKACHU:
        return _("pokemon.pikachu.name");

      case POKEMON_RAICHU:
        return _("pokemon.raichu.name");
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
  int8_t _sleepiness = MAX_SLEEPINESS;
  int8_t _life = MAX_LIFE;
  int8_t _mood = MAX_MOOD;
  int8_t _hunger = MAX_HUNGER;

  bool _is_sleeping = false;
  bool _is_sick = false;

  lv_obj_t* _image;
};
#endif
