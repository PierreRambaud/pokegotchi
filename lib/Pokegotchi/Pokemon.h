#pragma once
#ifndef POKEGOTCHI_POKEMON
#define POKEGOTCHI_POKEMON

#define POKEMON_PICHU 172
#define POKEMON_PIKACHU 25
#define POKEMON_RAICHU 26

#define POKEMON_EEVEE 133
#define POKEMON_VAPOREON 134
#define POKEMON_JOLTEON 135
#define POKEMON_FLAREON 136
#define POKEMON_ESPEON 196
#define POKEMON_UMBREON 197
#define POKEMON_LEAFEON 470
#define POKEMON_GLACEON 471

// Speeds up the simulation to test the pet, e.g. -D POKEGOTCHI_TIME_SCALE=30
#ifndef POKEGOTCHI_TIME_SCALE
#define POKEGOTCHI_TIME_SCALE 1
#endif

#include "lvgl.h"
#include "ArduinoJson.h"
#include "lv_i18n.h"
#include "ActionsMenu.h"

LV_IMG_DECLARE(pokemon_133);
LV_IMG_DECLARE(pokemon_134);
LV_IMG_DECLARE(pokemon_135);
LV_IMG_DECLARE(pokemon_136);
LV_IMG_DECLARE(pokemon_196);
LV_IMG_DECLARE(pokemon_197);
LV_IMG_DECLARE(pokemon_470);
LV_IMG_DECLARE(pokemon_471);
LV_IMG_DECLARE(pokemon_25);
LV_IMG_DECLARE(pokemon_26);
LV_IMG_DECLARE(pokemon_172);

LV_IMG_DECLARE(pokemon_sick_133);
LV_IMG_DECLARE(pokemon_sick_134);
LV_IMG_DECLARE(pokemon_sick_135);
LV_IMG_DECLARE(pokemon_sick_136);
LV_IMG_DECLARE(pokemon_sick_196);
LV_IMG_DECLARE(pokemon_sick_197);
LV_IMG_DECLARE(pokemon_sick_470);
LV_IMG_DECLARE(pokemon_sick_471);
LV_IMG_DECLARE(pokemon_sick_25);
LV_IMG_DECLARE(pokemon_sick_26);
LV_IMG_DECLARE(pokemon_sick_172);

extern const void* eevee_face;
extern const void* vaporeon_face;
extern const void* jolteon_face;
extern const void* flareon_face;
extern const void* espeon_face;
extern const void* umbreon_face;
extern const void* leafeon_face;
extern const void* glaceon_face;
extern const void* pikachu_face;
extern const void* raichu_face;
extern const void* pichu_face;

namespace Pokegotchi {
  // The Pokemon lives on its own clock, faster than the real one so that a
  // whole day (and night) fits in a play session
  // Values are saved: new speeds go at the end
  enum TimeSpeed : uint8_t { SPEED_FAST, SPEED_NORMAL, SPEED_REAL, SPEED_SLOW, SPEED_COUNT };
  // Game seconds per real second: a day lasts 10 minutes, 1 hour, 24 hours
  // or 4 hours
  const uint8_t TIME_SPEEDS[SPEED_COUNT] = {144, 24, 1, 6};
  // Order of the speeds in the menus, from the fastest
  const TimeSpeed SPEEDS_MENU[SPEED_COUNT] = {SPEED_FAST, SPEED_NORMAL, SPEED_SLOW, SPEED_REAL};
  // The needs never go faster than with 1 hour days: with 10 minutes days,
  // the clock and the nights fly by but the Pokemon is not starving every
  // two minutes
  const uint8_t NEEDS_MAX_SPEED = 24;
  // When the Pokemon sleeps at night, the night goes by faster
  const uint8_t NIGHT_SLEEP_SPEEDUP = 4;
  // A new game starts in the morning
  const uint8_t HOUR_GAME_START = 8;

  // Real time: the egg hatches after 5 minutes or 500 steps, whichever
  // comes first
  const uint32_t EGG_HATCH_SECONDS = 5 * 60;
  const uint16_t EGG_HATCH_STEPS = 500;
  // Going for a walk with the Pokemon cheers it up
  const uint16_t WALK_BONUS_STEPS = 100;

  // Game time, paced on a day: about 3 meals and as many play times while
  // awake, a night of sleep to recharge. Asleep, the Pokemon only gets a bit
  // hungry and wakes up hungry, it never starves in its sleep.
  const uint32_t HUNGER_SECONDS = 15 * 60;
  const uint32_t HUNGER_SLEEPING_SECONDS = 60 * 60;
  const int8_t HUNGER_SLEEPING_MIN = 3;
  const uint32_t MOOD_SECONDS = 30 * 60;
  const uint32_t MOOD_SICK_SECONDS = 15 * 60;
  const uint32_t ENERGY_SECONDS = 8 * 60 + 30;
  const uint32_t ENERGY_NIGHT_SECONDS = 4 * 60;
  const uint32_t ENERGY_SLEEPING_SECONDS = 4 * 60 + 30;
  const uint32_t LIFE_LOSS_SECONDS = 6 * 60;
  const uint32_t LIFE_REGEN_SECONDS = 15 * 60;
  const uint32_t POO_DIGESTION_SECONDS = 60 * 60;
  const uint32_t PEE_DIGESTION_SECONDS = 30 * 60;
  const uint32_t DIRTY_SICKNESS_SECONDS = 2 * 60 * 60;
  const uint32_t DIRTY_SICKNESS_RETRY_SECONDS = 30 * 60;
  const uint32_t SNACK_DIGESTION_SECONDS = 3 * 60 * 60;
  const uint32_t POTION_SECONDS = 8 * 60 * 60;
  // A call ignored this long is a care mistake, but a child always gets at
  // least a few real minutes to answer it
  const uint32_t CALL_CARE_MISTAKE_SECONDS = 45 * 60;
  const uint32_t CALL_CARE_MISTAKE_MIN_REAL_SECONDS = 3 * 60;

  // Real time
  const uint32_t PLAY_FRIENDSHIP_COOLDOWN = 5 * 60;
  const uint32_t PET_COOLDOWN = 60;

  // Offline time is simulated when a save is loaded, up to this game time.
  // The Pokemon comes back needy, but never close to fainting.
  const uint32_t MAX_CATCH_UP_SECONDS = 3 * 24 * 60 * 60;
  const int8_t CATCH_UP_MIN_LIFE = 25;

  const uint8_t HOUR_BEDTIME = 21;
  const uint8_t HOUR_WAKE_UP = 7;

  const int8_t MAX_LIFE = 100;
  const int8_t MAX_SLEEPINESS = 100;
  const int8_t MAX_MOOD = 10;
  const int8_t MAX_HUNGER = 20;
  const int8_t MAX_POOS = 10;
  const int8_t MAX_PEES = 10;
  const int8_t MAX_POTIONS = 3;
  const uint8_t MAX_FRIENDSHIP = 255;
  const uint8_t MAX_LEVEL = 100;
  const uint8_t MAX_STONES = 9;

  const uint8_t FRIENDSHIP_BASE = 70;
  const uint8_t FRIENDSHIP_EVOLUTION = 160;
  const uint8_t SNACKS_SICKNESS = 4;

  const int8_t PROPERTY_SLEEPINESS = 1;
  const int8_t PROPERTY_LIFE = 2;
  const int8_t PROPERTY_MOOD = 3;
  const int8_t PROPERTY_HUNGER = 4;
  const int8_t PROPERTY_POOS = 5;
  const int8_t PROPERTY_PEES = 6;
  const int8_t PROPERTY_POTIONS = 7;

  enum Stone : uint8_t { STONE_THUNDER, STONE_WATER, STONE_FIRE, STONE_LEAF, STONE_ICE, STONE_COUNT };

  // What the Pokemon is calling for, by priority
  enum Call : uint8_t { CALL_NONE, CALL_SICK, CALL_HUNGRY, CALL_SLEEPY, CALL_DIRTY, CALL_BORED, CALL_TIRED };

  // Things that happened during an update, for the screen to react
  enum Event : uint16_t {
    EVENT_HATCHED = 1 << 0,
    EVENT_GOT_SICK = 1 << 1,
    EVENT_POOED = 1 << 2,
    EVENT_FELL_ASLEEP = 1 << 3,
    EVENT_WOKE_UP = 1 << 4,
    EVENT_LEVEL_UP = 1 << 5,
    EVENT_EVOLVE = 1 << 6,
    EVENT_CARE_MISTAKE = 1 << 7,
    EVENT_CALL = 1 << 8,
    EVENT_KO = 1 << 9,
    EVENT_CURED = 1 << 10,
  };

  enum ActionResult : uint8_t { ACTION_DONE, ACTION_REFUSED_FULL, ACTION_REFUSED_SICK, ACTION_REFUSED_TIRED, ACTION_NO_EFFECT };

  class Pokemon {
   public:
    explicit Pokemon(int number);

    void update(uint32_t now);
    uint16_t take_events(void) {
      uint16_t events = _events;
      _events = 0;
      return events;
    }

    static void setInstance(Pokemon* instance) { _instance = instance; }
    static Pokemon* getInstance(void) { return _instance; }

    int8_t get_potions(void) { return _potions; }
    int8_t get_poos(void) { return _poos; }
    int8_t get_pees(void) { return _pees; }
    uint8_t get_level(void) { return _level; }
    uint16_t get_xp(void) { return _xp; }
    uint16_t get_xp_to_next_level(void) { return _level * 8; }
    int8_t get_life(void) { return _life; }
    int8_t get_mood(void) { return _mood; }
    int8_t get_hunger(void) { return _hunger; }
    int8_t get_sleepiness(void) { return _sleepiness; }
    uint8_t get_friendship(void) { return _friendship; }
    uint16_t get_care_mistakes(void) { return _care_mistakes; }
    uint8_t get_stones(Stone stone) { return _stones[stone]; }
    uint32_t get_age_days(void) { return _is_egg || _birth == 0 || _game_time < _birth ? 0 : (_game_time - _birth) / 86400; }
    uint32_t get_game_time(void) { return _game_time; }
    TimeSpeed get_speed(void) { return _speed; }
    void set_speed(TimeSpeed speed);
    void set_time_of_day(uint8_t hour, uint8_t minute);
    int get_number(void) { return _number; }
    int get_evolution_from(void) { return _evolution_from; }
    Call get_call(void) { return _call; }

    bool is_sick(void) { return _is_sick; }
    bool is_sleeping(void) { return _is_sleeping; }
    bool is_ko(void) { return _is_ko; }
    bool is_egg(void) { return _is_egg; }
    float get_hatch_progress(void) {
      float time_progress = 1.0f - (float)_hatch_seconds / EGG_HATCH_SECONDS;
      float steps_progress = (float)_egg_steps / EGG_HATCH_STEPS;
      return time_progress > steps_progress ? time_progress : steps_progress;
    }
    uint16_t get_egg_steps(void) { return _egg_steps; }
    uint32_t get_steps_today(uint32_t now) { return now / 86400 == _steps_day ? _steps_today : 0; }
    uint32_t get_total_steps(void) { return _total_steps; }

    ActionResult eat(BagItem* item);
    ActionResult heal(void);
    ActionResult train(void);
    ActionResult play(void);
    ActionResult use_stone(Stone stone);
    bool pet(void);
    void shake(void);
    void sleep(void);
    void wake_up(void);
    void clean_poo(void);
    void clean_pee(void);
    void tap_egg(void);
    void add_steps(uint16_t steps);
    int8_t reward_minigame(int32_t score);

    const lv_image_dsc_t* get_image(void) { return get_image(_number, _is_sick); }
    static const lv_image_dsc_t* get_image(int number, bool sick);
    const void* get_avatar(void);
    const char* get_description(void);
    const char* get_name(void) { return get_name(_number); }
    static const char* get_name(int number);
    static const lv_image_dsc_t* get_stone_image(Stone stone);
    static const char* get_stone_name(Stone stone);
    static const char* get_speed_name(TimeSpeed speed);

    void load(JsonObject pokemon);
    void save(JsonObject pokemon);

    static uint8_t hour_of(uint32_t time) { return (time % 86400) / 3600; }
    static bool is_night(uint32_t time) {
      uint8_t hour = hour_of(time);
      return hour >= HOUR_BEDTIME || hour < HOUR_WAKE_UP;
    }

   private:
    static Pokemon* _instance;

    void _step(uint32_t day_seconds, uint32_t seconds, uint32_t real_seconds);
    void _update_calls(uint32_t seconds, uint32_t real_seconds);
    uint32_t _current_speed(void);
    void _add_xp(uint16_t xp);
    void _evolve_to(int number);
    void _add_friendship(int16_t value);
    void _set_sleeping(bool sleeping);
    void _count_care_mistake(void);
    void _hatch(uint32_t now);
    int8_t _tick(uint32_t& accumulator, uint32_t seconds, uint32_t period);
    void _update_property(int8_t what, int8_t value);

    int _number = POKEMON_PICHU;
    int _evolution_from = 0;

    int8_t _potions = 0;
    int8_t _poos = 0;
    int8_t _pees = 0;
    uint8_t _level = 1;
    uint16_t _xp = 0;
    int8_t _sleepiness = MAX_SLEEPINESS;
    int8_t _life = MAX_LIFE;
    int8_t _mood = MAX_MOOD;
    int8_t _hunger = MAX_HUNGER;
    uint8_t _friendship = FRIENDSHIP_BASE;
    uint16_t _care_mistakes = 0;
    uint8_t _stones[STONE_COUNT] = {0};

    bool _is_sleeping = false;
    bool _is_sick = false;
    bool _is_ko = false;
    bool _is_egg = true;
    bool _catching_up = false;
    bool _was_night = false;

    uint32_t _hatch_seconds = EGG_HATCH_SECONDS;
    uint16_t _egg_steps = 0;
    uint16_t _walk_steps = 0;
    uint32_t _steps_today = 0;
    uint32_t _steps_day = 0;
    uint32_t _total_steps = 0;
    uint32_t _birth = 0;
    // Real time of the last update, and the clock of the Pokemon
    uint32_t _last_update = 0;
    uint32_t _game_time = 0;
    TimeSpeed _speed = SPEED_FAST;
    uint32_t _last_play_friendship = 0;
    uint32_t _last_pet = 0;
    uint32_t _last_bedtime_day = 0;

    uint8_t _pending_poos = 0;
    uint8_t _pending_pees = 0;
    uint8_t _snacks = 0;

    Call _call = CALL_NONE;
    uint32_t _call_seconds = 0;
    uint32_t _call_real_seconds = 0;
    bool _call_mistake_counted = false;

    // Seconds accumulated towards the next change of each property
    uint32_t _acc_hunger = 0;
    uint32_t _acc_mood = 0;
    uint32_t _acc_energy = 0;
    uint32_t _acc_life = 0;
    uint32_t _acc_poo = 0;
    uint32_t _acc_pee = 0;
    uint32_t _acc_dirty = 0;
    uint32_t _acc_snack = 0;
    uint32_t _acc_potion = 0;

    uint16_t _events = 0;
  };
}  // namespace Pokegotchi
#endif
