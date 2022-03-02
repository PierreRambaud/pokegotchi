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
const unsigned long PERIOD_SIMPLE_CHECK = 5 * 1000UL;   // 1*60*1000UL;
const unsigned long PERIOD_POO = 5 * 1000UL;        // 10*60*1000UL;


#include <lvgl.h>
#include <ArduinoJson.h>
#include "lv_i18n.h"
#include "Menu.h"

const int8_t MAX_LIFE = 100;
const int8_t MAX_SLEEPINESS = 100;
const int8_t MAX_MOOD = 10;
const int8_t MAX_HUNGER = 20;

class Pokemon {
 public:
  Pokemon(int number);
  void loop();
  void animate();

  static void setInstance(Pokemon* instance) { _instance = instance; }
  static Pokemon* getInstance() { return _instance; }

  int8_t get_poos() { return _poos; }
  int8_t get_level() { return _level; }
  int8_t get_life() { return _life; }
  int8_t get_mood() { return _mood; }
  int8_t get_hunger() { return _hunger; }
  int8_t get_sleepiness() { return _sleepiness; }
  int get_number() { return _number; }

  long unsigned get_last_simple_check_time() { return _last_simple_check_time; }
  long unsigned get_last_boredom_time() { return _last_boredom_time; }
  long unsigned get_last_hunger_time() { return _last_hunger_time; }
  long unsigned get_last_sleep_time() { return _last_sleep_time; }
  long unsigned get_last_without_sleep_time() { return _last_without_sleep_time; }
  long unsigned get_last_poo_time() { return _last_poo_time; }

  bool is_sick() { return _is_sick; }
  bool is_sleeping() { return _is_sleeping; }
  bool is_ko() { return _is_ko; }

  void eat(Item* item);
  void heal(int8_t number);
  void train();
  void play();
  void sleep();
  void wake_up();
  void poo();
  void clean_poo();
  void tiredness(int8_t number);
  void boredom(int8_t number);
  void hungry(int8_t number);
  void simple_check();

  const lv_img_dsc_t* get_image() {
    switch (_number) {
      case POKEMON_EEVEE:
        LV_IMG_DECLARE(pokemon_133);
        return &pokemon_133;
      case POKEMON_VAPOREON:
        LV_IMG_DECLARE(pokemon_134);
        return &pokemon_134;
      case POKEMON_JOLTEON:
        LV_IMG_DECLARE(pokemon_135);
        return &pokemon_135;
      case POKEMON_FLAREON:
        LV_IMG_DECLARE(pokemon_136);
        return &pokemon_136;
      case POKEMON_PIKACHU:
        LV_IMG_DECLARE(pokemon_25);
        return &pokemon_25;
      case POKEMON_RAICHU:
        LV_IMG_DECLARE(pokemon_26);
        return &pokemon_26;
      case POKEMON_PICHU:
      default:
        LV_IMG_DECLARE(pokemon_172);
        return &pokemon_172;
    }
  }

  const char* get_avatar() {
    switch (_number) {
      case POKEMON_EEVEE:
        return "L:/pokemon/face/133.bin";
      case POKEMON_VAPOREON:
        return "L:/pokemon/face/134.bin";
      case POKEMON_JOLTEON:
        return "L:/pokemon/face/135.bin";
      case POKEMON_FLAREON:
        return "L:/pokemon/face/136.bin";
      case POKEMON_PIKACHU:
        return "L:/pokemon/face/25.bin";
      case POKEMON_RAICHU:
        return "L:/pokemon/face/26.bin";
      case POKEMON_PICHU:
      default:
        return "L:/pokemon/face/172.bin";
    }
  }

  const char* get_description() {
    switch (_number) {
      case POKEMON_EEVEE:
        return _("pokemon.eevee.description");
      case POKEMON_VAPOREON:
        return _("pokemon.vaporeon.description");
      case POKEMON_JOLTEON:
        return _("pokemon.jolteon.description");
      case POKEMON_FLAREON:
        return _("pokemon.flareon.description");
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
    switch (_number) {
      case POKEMON_EEVEE:
        return _("pokemon.eevee.name");
      case POKEMON_VAPOREON:
        return _("pokemon.vaporeon.name");
      case POKEMON_JOLTEON:
        return _("pokemon.jolteon.name");
      case POKEMON_FLAREON:
        return _("pokemon.flareon.name");
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
    _level = pokemon["level"];
    _life = pokemon["life"];
    _mood = pokemon["mood"];
    _hunger = pokemon["hunger"];
    _sleepiness = pokemon["sleepiness"];
    _is_sleeping = pokemon["is_sleeping"];

    JsonObject pokemon_time = pokemon["time"];
    _last_simple_check_time = pokemon_time["simple_check"];
    _last_boredom_time = pokemon_time["boredom"];
    _last_hunger_time = pokemon_time["hunger"];
    _last_sleep_time = pokemon_time["sleep"];
    _last_without_sleep_time = pokemon_time["without_sleep"];
  }

  bool try_to_evolve() {
    if (_level == 3) {
      if (_number == POKEMON_PICHU) {
        _number = POKEMON_PIKACHU;
      } else if (_number == POKEMON_EEVEE) {
        _number = POKEMON_FLAREON;
      }
    } else if (_level == 5) {
      if (_number == POKEMON_PIKACHU) {
        _number = POKEMON_RAICHU;
      } else if (_number == POKEMON_FLAREON) {
        _number = POKEMON_VAPOREON;
      }
    } else if (_level == 10) {
      if (_number == POKEMON_VAPOREON) {
        _number = POKEMON_JOLTEON;
      }
    } else {
      return false;
    }

    return true;
  }

 private:
  static Pokemon* _instance;

  const char* _name;

  int _number = POKEMON_PICHU;

  int8_t _poos = 0;
  int8_t _level = 1;
  int8_t _sleepiness = MAX_SLEEPINESS;
  int8_t _life = MAX_LIFE;
  int8_t _mood = MAX_MOOD;
  int8_t _hunger = MAX_HUNGER;

  bool _is_sleeping = false;
  bool _is_sick = false;
  bool _is_ko = false;

  long unsigned _last_boredom_time;
  long unsigned _last_hunger_time;
  long unsigned _last_sleep_time;
  long unsigned _last_without_sleep_time;
  long unsigned _last_simple_check_time;
  long unsigned _last_poo_time;
};
#endif
