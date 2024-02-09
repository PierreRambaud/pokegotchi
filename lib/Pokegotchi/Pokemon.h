#pragma once
#ifndef POKEGOTCHI_POKEMON
#define POKEGOTCHI_POKEMON

#define POKEMON_EVOLVE_ONE 16
#define POKEMON_EVOLVE_TWO 34
#define POKEMON_EVOLVE_THREE 50

#define POKEMON_PICHU 172
#define POKEMON_PIKACHU 25
#define POKEMON_RAICHU 26

#define POKEMON_EEVEE 133
#define POKEMON_VAPOREON 134
#define POKEMON_JOLTEON 135
#define POKEMON_FLAREON 136

#include "lvgl.h"
#include "ArduinoJson.h"
#include "lv_i18n.h"
#include "ActionsMenu.h"

LV_IMG_DECLARE(pokemon_133);
LV_IMG_DECLARE(pokemon_134);
LV_IMG_DECLARE(pokemon_135);
LV_IMG_DECLARE(pokemon_136);
LV_IMG_DECLARE(pokemon_25);
LV_IMG_DECLARE(pokemon_26);
LV_IMG_DECLARE(pokemon_172);

namespace Pokegotchi {
  const unsigned long PERIOD_BOREDOM = 15 * 1000UL;
  const unsigned long PERIOD_HUNGER = 15 * 1000UL;
  const unsigned long PERIOD_MOOD = 25 * 1000UL;
  const unsigned long PERIOD_SLEEP = 5 * 1000UL;
  const unsigned long PERIOD_WITHOUT_SLEEP = 15 * 1000UL;
  const unsigned long PERIOD_SIMPLE_CHECK = 15 * 1000UL;
  const unsigned long PERIOD_POTION = 60 * 1000UL;

  const int8_t MAX_LIFE = 100;
  const int8_t MAX_SLEEPINESS = 100;
  const int8_t MAX_MOOD = 10;
  const int8_t MAX_HUNGER = 20;
  const int8_t MAX_POOS = 10;
  const int8_t MAX_PEES = 10;
  const int8_t MAX_POTIONS = 3;

  const int8_t PROPERTY_SLEEPINESS = 1;
  const int8_t PROPERTY_LIFE = 2;
  const int8_t PROPERTY_MOOD = 3;
  const int8_t PROPERTY_HUNGER = 4;
  const int8_t PROPERTY_POOS = 5;
  const int8_t PROPERTY_PEES = 6;
  const int8_t PROPERTY_POTIONS = 7;

  class Pokemon {
   public:
    explicit Pokemon(int number);
    void loop();
    void animate();

    static void setInstance(Pokemon* instance) { _instance = instance; }
    static Pokemon* getInstance() { return _instance; }

    int8_t get_potions() { return _potions; }
    int8_t get_poos() { return _poos; }
    int8_t get_pees() { return _pees; }
    int8_t get_level() { return _level; }
    int8_t get_life() { return _life; }
    int8_t get_mood() { return _mood; }
    int8_t get_hunger() { return _hunger; }
    int8_t get_sleepiness() { return _sleepiness; }
    int get_number() { return _number; }

    long get_last_simple_check_time() { return _last_simple_check_time; }
    long get_last_boredom_time() { return _last_boredom_time; }
    long get_last_hunger_time() { return _last_hunger_time; }
    long get_last_sleep_time() { return _last_sleep_time; }
    long get_last_without_sleep_time() { return _last_without_sleep_time; }
    long get_last_potion_time() { return _last_potion_time; }

    bool is_sick() { return _is_sick; }
    bool is_sleeping() { return _is_sleeping; }
    bool is_ko() { return _is_ko; }

    void eat(BagItem* item);
    void heal();
    void train();
    void play();
    void sleep();
    void wake_up();
    void poo();
    void clean_poo();
    void clean_pee();
    void simple_check();

    const lv_image_dsc_t* get_image() {
      switch (_number) {
        case POKEMON_EEVEE:
          return &pokemon_133;
        case POKEMON_VAPOREON:
          return &pokemon_134;
        case POKEMON_JOLTEON:
          return &pokemon_135;
        case POKEMON_FLAREON:
          return &pokemon_136;
        case POKEMON_PIKACHU:
          return &pokemon_25;
        case POKEMON_RAICHU:
          return &pokemon_26;
        case POKEMON_PICHU:
        default:
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
      _potions = pokemon["potions"];
      _poos = pokemon["poos"];
      _pees = pokemon["pees"];

      JsonObject pokemon_time = pokemon["time"];
      _last_simple_check_time = pokemon_time["simple_check"];
      _last_boredom_time = pokemon_time["boredom"];
      _last_hunger_time = pokemon_time["hunger"];
      _last_sleep_time = pokemon_time["sleep"];
      _last_without_sleep_time = pokemon_time["without_sleep"];
      _last_potion_time = pokemon_time["potion"];
    }

    bool try_to_evolve() {
      if (_level == POKEMON_EVOLVE_ONE) {
        if (_number == POKEMON_PICHU) {
          _number = POKEMON_PIKACHU;
        } else if (_number == POKEMON_EEVEE) {
          _number = POKEMON_FLAREON;
        }
      } else if (_level == POKEMON_EVOLVE_TWO) {
        if (_number == POKEMON_PIKACHU) {
          _number = POKEMON_RAICHU;
        } else if (_number == POKEMON_FLAREON) {
          _number = POKEMON_VAPOREON;
        }
      } else if (_level == POKEMON_EVOLVE_THREE) {
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

    int8_t _potions = 0;
    int8_t _poos = 0;
    int8_t _pees = 0;
    int8_t _level = 1;
    int8_t _sleepiness = MAX_SLEEPINESS;
    int8_t _life = MAX_LIFE;
    int8_t _mood = MAX_MOOD;
    int8_t _hunger = MAX_HUNGER;

    void _update_property(int8_t what, int8_t value) {
      int8_t max_value;
      int8_t* property;

      if (what == PROPERTY_HUNGER) {
        max_value = MAX_HUNGER;
        property = &_hunger;
      } else if (what == PROPERTY_LIFE) {
        max_value = MAX_LIFE;
        property = &_life;
      } else if (what == PROPERTY_MOOD) {
        max_value = MAX_MOOD;
        property = &_mood;
      } else if (what == PROPERTY_SLEEPINESS) {
        max_value = MAX_SLEEPINESS;
        property = &_sleepiness;
      } else if (what == PROPERTY_POOS) {
        max_value = MAX_POOS;
        property = &_poos;
      } else if (what == PROPERTY_POTIONS) {
        max_value = MAX_POTIONS;
        property = &_potions;
      } else if (what == PROPERTY_PEES) {
        max_value = MAX_PEES;
        property = &_pees;
      } else {
        serial_printf("Pokemon", "Property %d not found", what);
        return;
      }

      *property += value;
      if (*property > max_value) {
        *property = max_value;
      }

      if (*property < 0) {
        *property = 0;
      }
    }

    bool _is_sleeping = false;
    bool _is_sick = false;
    bool _is_ko = false;

    long _last_boredom_time;
    long _last_hunger_time;
    long _last_sleep_time;
    long _last_without_sleep_time;
    long _last_simple_check_time;
    long _last_potion_time;
  };
}  // namespace Pokegotchi
#endif
