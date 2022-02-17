#ifndef POKEGOTCHI_POKEMON
#define POKEGOTCHI_POKEMON

#define POKEMON_PICHU 172
#define POKEMON_PIKACHU 25
#define POKEMON_RAICHU 26

#define POKEMON_EEVEE 133
#define POKEMON_VAPOREON 134
#define POKEMON_JOLTEON 135
#define POKEMON_FLAREON 136

const unsigned long PERIOD_BOREDOM = 5 * 1000UL;        // 30*60*1000UL;
const unsigned long PERIOD_HUNGER = 5 * 1000UL;         // 10*60*1000UL;
const unsigned long PERIOD_MOOD = 5 * 1000UL;           // 5*60*1000UL;
const unsigned long PERIOD_SLEEP = 5 * 1000UL;          // 30*60*1000UL;
const unsigned long PERIOD_WITHOUT_SLEEP = 5 * 1000UL;  // 5*60*1000UL;

#include <lvgl.h>
#include <ArduinoJson.h>
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

  long unsigned get_last_boredom_time() { return _last_boredom_time; }
  long unsigned get_last_hunger_time() { return _last_hunger_time; }
  long unsigned get_last_sleep_time() { return _last_sleep_time; }
  long unsigned get_last_without_sleep_time() { return _last_without_sleep_time; }

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
    switch (_type) {
      case POKEMON_PIKACHU:
        return &pokemon_25;

      case POKEMON_RAICHU:
        return &pokemon_26;

      case POKEMON_PICHU:
      default:
        return &pokemon_172;
    }
  }

  const lv_img_dsc_t* get_avatar() {
    switch (_type) {
      case POKEMON_PIKACHU:
        return &pokemon_face_25;

      case POKEMON_RAICHU:
        return &pokemon_face_26;

      case POKEMON_PICHU:
      default:
        return &pokemon_face_172;
    }
  }

  const char* get_description() {
    switch (_type) {
      case POKEMON_PIKACHU:
        return _("pokemon.pikachu.description");

      case POKEMON_RAICHU:
        return _("pokemon.raichu.description");

      case POKEMON_PICHU:
      default:
        return _("pokemon.pichu.description");
    }
  }

  const char* get_name() {
    switch (_type) {
      case POKEMON_PIKACHU:
        return _("pokemon.pikachu.name");

      case POKEMON_RAICHU:
        return _("pokemon.raichu.name");

      case POKEMON_PICHU:
      default:
        return _("pokemon.pichu.name");
    }
  }

  void load(JsonObject pokemon) {
    _type = pokemon["type"];
    _level = pokemon["level"];
    _life = pokemon["life"];
    _mood = pokemon["mood"];
    _hunger = pokemon["hunger"];
    _sleepiness = pokemon["sleepiness"];
    _is_sleeping = pokemon["is_sleeping"];

    JsonObject pokemon_time = pokemon["time"];
    _last_boredom_time = pokemon_time["boredom"];
    _last_hunger_time = pokemon_time["hunger"];
    _last_sleep_time = pokemon_time["sleep"];
    _last_without_sleep_time = pokemon_time["without_sleep"];

    lv_gif_set_src(_image, get_image());
  }

 private:
  Pokemon();
  static Pokemon* instance;

  void try_to_evolve() {
    if (_level == 3) {
      if (_type == POKEMON_PICHU) {
        _type = POKEMON_PIKACHU;
      } else if (_type == POKEMON_EEVEE) {
        _type = POKEMON_FLAREON;
      }
    } else if (_level == 5) {
      if (_type == POKEMON_PIKACHU) {
        _type = POKEMON_RAICHU;
      } else if (_type == POKEMON_FLAREON) {
        _type = POKEMON_VAPOREON;
      }
    } else {
      return;
    }

    lv_gif_set_src(_image, get_image());
  }

  const char* _name;

  int _type = POKEMON_PICHU;

  int8_t _level = 1;
  int8_t _sleepiness = MAX_SLEEPINESS;
  int8_t _life = MAX_LIFE;
  int8_t _mood = MAX_MOOD;
  int8_t _hunger = MAX_HUNGER;

  bool _is_sleeping = false;
  bool _is_sick = false;

  lv_obj_t* _image;

  long unsigned _last_boredom_time;
  long unsigned _last_hunger_time;
  long unsigned _last_sleep_time;
  long unsigned _last_without_sleep_time;
};
#endif
