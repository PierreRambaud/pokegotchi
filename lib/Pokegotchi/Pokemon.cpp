#include "Utils.h"
#include "Pokemon.h"

using namespace Pokegotchi;

LV_IMG_DECLARE(stone_thunder)
LV_IMG_DECLARE(stone_water)
LV_IMG_DECLARE(stone_fire)
LV_IMG_DECLARE(stone_leaf)
LV_IMG_DECLARE(stone_ice)

Pokemon* Pokemon::_instance = nullptr;

// Simulation step: small enough to respect the day/night boundaries
// Simulation step, in game seconds
static const uint32_t STEP_SECONDS = 300;

Pokemon::Pokemon(int number) { _number = number; }

/**
 * Advance the simulation to the given wall clock time. The Pokemon has its
 * own clock, faster than the real one. A long gap (device off, save loaded)
 * is simulated step by step, without care mistakes and without letting the
 * Pokemon faint.
 */
void Pokemon::update(uint32_t now) {
  if (_last_update == 0 || now < _last_update) {
    // First update, or the clock was set backwards: start from now
    _last_update = now;
    if (_speed == SPEED_REAL) {
      _game_time = now;
    } else if (_game_time == 0) {
      // A new game starts in the morning of the first day
      _game_time = 86400UL + HOUR_GAME_START * 3600UL;
    }
    _was_night = is_night(_game_time);
    return;
  }

  uint32_t elapsed = now - _last_update;
  if (elapsed == 0) {
    return;
  }

  uint32_t max_real = MAX_CATCH_UP_SECONDS / TIME_SPEEDS[_speed];
  if (elapsed > max_real) {
    _last_update = now - max_real;
  }

  _catching_up = elapsed > 120;
  if (_catching_up) {
    serial_printf("Pokemon", "Catching up %lu seconds", (unsigned long)(now - _last_update));
  }

  while (_last_update < now && !_is_ko) {
    // Small steps of game time, to respect the day/night boundaries
    uint32_t speed = _current_speed();
    uint32_t real_step = LV_MIN(now - _last_update, LV_MAX(STEP_SECONDS / speed, 1UL));
    _last_update += real_step;
    _game_time += real_step * speed;
    _step(real_step * speed, real_step);
  }

  _last_update = now;
  _catching_up = false;
}

uint32_t Pokemon::_current_speed(void) {
  uint32_t speed = TIME_SPEEDS[_speed] * POKEGOTCHI_TIME_SCALE;
  if (_speed != SPEED_REAL && _is_sleeping && is_night(_game_time)) {
    speed *= NIGHT_SLEEP_SPEEDUP;
  }

  return speed;
}

void Pokemon::set_speed(TimeSpeed speed) {
  if (speed >= SPEED_COUNT || speed == _speed) {
    return;
  }

  _speed = speed;
  if (_speed == SPEED_REAL && _last_update != 0) {
    // Back on the real clock
    _game_time = _last_update;
    _was_night = is_night(_game_time);
  }
}

/**
 * Move the clock of the Pokemon, without simulating the time skipped
 */
void Pokemon::set_time_of_day(uint8_t hour, uint8_t minute) {
  uint32_t day_start = _game_time - _game_time % 86400;
  // The next update sees the morning come, and wakes the Pokemon up
  _game_time = day_start + hour * 3600UL + minute * 60UL;
}

/**
 * Count how many periods were completed by adding these seconds
 */
int8_t Pokemon::_tick(uint32_t& accumulator, uint32_t seconds, uint32_t period) {
  accumulator += seconds;
  uint32_t count = accumulator / period;
  accumulator -= count * period;

  return count > 100 ? 100 : count;
}

void Pokemon::_step(uint32_t seconds, uint32_t real_seconds) {
  if (_is_ko) {
    return;
  }

  if (_is_egg) {
    // The egg hatches in real time, whatever the speed of the days
    uint32_t hatch = real_seconds * POKEGOTCHI_TIME_SCALE;
    if (_hatch_seconds > hatch) {
      _hatch_seconds -= hatch;
    } else {
      _hatch(_game_time);
    }
    return;
  }

  bool night = is_night(_game_time);
  int8_t count;

  if (_is_sleeping) {
    count = _tick(_acc_hunger, seconds, HUNGER_SLEEPING_SECONDS);
    if (_hunger > HUNGER_SLEEPING_MIN) {
      _update_property(PROPERTY_HUNGER, -LV_MIN(count, _hunger - HUNGER_SLEEPING_MIN));
    }
  } else {
    count = _tick(_acc_hunger, seconds, HUNGER_SECONDS);
    _update_property(PROPERTY_HUNGER, -count);
  }

  if (!_is_sleeping) {
    count = _tick(_acc_mood, seconds, _is_sick ? MOOD_SICK_SECONDS : MOOD_SECONDS);
    _update_property(PROPERTY_MOOD, -count);
  }

  if (_is_sleeping) {
    count = _tick(_acc_energy, seconds, ENERGY_SLEEPING_SECONDS);
    _update_property(PROPERTY_SLEEPINESS, count);
  } else {
    count = _tick(_acc_energy, seconds, night ? ENERGY_NIGHT_SECONDS : ENERGY_SECONDS);
    _update_property(PROPERTY_SLEEPINESS, -count);
  }

  // Life goes down faster with every unmet need, and slowly comes back
  // when the Pokemon is well cared for. Asleep, only sickness hurts.
  uint8_t pressure = _is_sick ? 1 : 0;
  if (!_is_sleeping) {
    pressure += (_hunger == 0) + (_mood == 0) + (_sleepiness == 0);
  }
  if (pressure > 0) {
    count = _tick(_acc_life, seconds * pressure, LIFE_LOSS_SECONDS);
    _update_property(PROPERTY_LIFE, -count);
    if (_catching_up && _life < CATCH_UP_MIN_LIFE) {
      _life = CATCH_UP_MIN_LIFE;
    }
  } else if (_hunger >= MAX_HUNGER / 2 && _mood >= MAX_MOOD / 2 && _sleepiness >= 30) {
    count = _tick(_acc_life, seconds, LIFE_REGEN_SECONDS);
    _update_property(PROPERTY_LIFE, count);
  } else {
    _acc_life = 0;
  }

  if (_life <= 0) {
    _life = 0;
    _is_ko = true;
    _events |= EVENT_KO;
    return;
  }

  // Digestion: what was eaten comes out a bit later
  if (_pending_poos > 0) {
    if (_tick(_acc_poo, seconds, POO_DIGESTION_SECONDS) > 0) {
      _pending_poos--;
      _update_property(PROPERTY_POOS, 1);
      _events |= EVENT_POOED;
      _acc_poo = 0;
    }
  } else {
    _acc_poo = 0;
  }

  if (_pending_pees > 0) {
    if (_tick(_acc_pee, seconds, PEE_DIGESTION_SECONDS) > 0) {
      _pending_pees--;
      _update_property(PROPERTY_PEES, 1);
      _events |= EVENT_POOED;
      _acc_pee = 0;
    }
  } else {
    _acc_pee = 0;
  }

  // A dirty place makes the Pokemon sick sooner or later
  if (_poos + _pees >= 2 && !_is_sick) {
    _acc_dirty += seconds;
    if (_acc_dirty >= DIRTY_SICKNESS_SECONDS) {
      _acc_dirty -= DIRTY_SICKNESS_RETRY_SECONDS;
      if (hal_random(0, 100) < 25) {
        _is_sick = true;
        _events |= EVENT_GOT_SICK;
      }
    }
  } else {
    _acc_dirty = 0;
  }

  if (_snacks > 0) {
    count = _tick(_acc_snack, seconds, SNACK_DIGESTION_SECONDS);
    _snacks = count >= _snacks ? 0 : _snacks - count;
  }

  _update_property(PROPERTY_POTIONS, _tick(_acc_potion, seconds, POTION_SECONDS));

  // Sleep cycle: wake up in the morning, or at the end of a nap
  if (_is_sleeping) {
    bool morning = _was_night && !night;
    if ((morning && _sleepiness >= MAX_SLEEPINESS / 2) || (!night && _sleepiness >= MAX_SLEEPINESS)) {
      _set_sleeping(false);
      _events |= EVENT_WOKE_UP;
    }
  } else if (_sleepiness == 0) {
    // Exhausted, it falls asleep wherever it is
    _set_sleeping(true);
    _events |= EVENT_FELL_ASLEEP;
  }
  _was_night = night;

  _update_calls(seconds, real_seconds);
}

/**
 * Like a Tamagotchi, the Pokemon calls when it needs something. Ignoring a
 * call for too long is a care mistake.
 */
void Pokemon::_update_calls(uint32_t seconds, uint32_t real_seconds) {
  Call call = CALL_NONE;
  if (_is_sick) {
    call = CALL_SICK;
  } else if (_hunger <= 2) {
    call = CALL_HUNGRY;
  } else if (!_is_sleeping && is_night(_game_time)) {
    call = CALL_SLEEPY;
  } else if (_poos + _pees >= 3) {
    call = CALL_DIRTY;
  } else if (!_is_sleeping && _mood <= 1) {
    call = CALL_BORED;
  } else if (!_is_sleeping && _sleepiness <= 10) {
    call = CALL_TIRED;
  }

  if (call == CALL_NONE) {
    _call = CALL_NONE;
    _call_seconds = 0;
    _call_real_seconds = 0;
    _call_mistake_counted = false;
    return;
  }

  if (_call == CALL_NONE) {
    _events |= EVENT_CALL;
    _call_seconds = 0;
    _call_real_seconds = 0;
    _call_mistake_counted = false;
  }

  _call = call;
  _call_seconds += seconds;
  _call_real_seconds += real_seconds;

  bool ignored = _call_seconds >= CALL_CARE_MISTAKE_SECONDS && _call_real_seconds >= CALL_CARE_MISTAKE_MIN_REAL_SECONDS;
  if (!_call_mistake_counted && !_catching_up && ignored) {
    _call_mistake_counted = true;
    _care_mistakes++;
    _add_friendship(-20);
    _events |= EVENT_CARE_MISTAKE;

    if (call == CALL_SLEEPY) {
      // Nobody turned off the light: it falls asleep by itself
      _set_sleeping(true);
      _events |= EVENT_FELL_ASLEEP;
    }
  }
}

/**
 * Hunger and energy change at another rate when sleeping: progress made at
 * the old rate must not count at the new one
 */
void Pokemon::_set_sleeping(bool sleeping) {
  if (_is_sleeping != sleeping) {
    _acc_hunger = 0;
    _acc_energy = 0;
  }
  _is_sleeping = sleeping;
}

void Pokemon::_update_property(int8_t what, int8_t value) {
  if (value == 0) {
    return;
  }

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

  int16_t result = *property + value;
  if (result > max_value) {
    result = max_value;
  }

  if (result < 0) {
    result = 0;
  }

  *property = result;
}

void Pokemon::_add_friendship(int16_t value) {
  int16_t result = _friendship + value;
  _friendship = result < 0 ? 0 : (result > MAX_FRIENDSHIP ? MAX_FRIENDSHIP : result);
}

/**
 * Level up, and evolve like in the games: Pichu and Eevee evolve when they
 * level up with a high friendship, Eevee into Espeon by day or Umbreon by night
 */
void Pokemon::_add_xp(uint16_t xp) {
  if (_level >= MAX_LEVEL) {
    return;
  }

  _xp += xp;
  while (_level < MAX_LEVEL && _xp >= get_xp_to_next_level()) {
    _xp -= get_xp_to_next_level();
    _level++;
    _events |= EVENT_LEVEL_UP;

    if (_friendship >= FRIENDSHIP_EVOLUTION) {
      if (_number == POKEMON_PICHU) {
        _evolve_to(POKEMON_PIKACHU);
      } else if (_number == POKEMON_EEVEE) {
        _evolve_to(is_night(_game_time) ? POKEMON_UMBREON : POKEMON_ESPEON);
      }
    }
  }
}

void Pokemon::_evolve_to(int number) {
  _evolution_from = _number;
  _number = number;
  _events |= EVENT_EVOLVE;
}

ActionResult Pokemon::eat(BagItem* item) {
  if (_is_egg) {
    return ACTION_NO_EFFECT;
  }

  if (item->specs->hunger > 0 && _hunger >= MAX_HUNGER) {
    return ACTION_REFUSED_FULL;
  }

  // Feeding a hungry Pokemon builds trust
  if (_hunger <= MAX_HUNGER / 2) {
    _add_friendship(3);
  }

  _update_property(PROPERTY_MOOD, item->specs->mood);
  _update_property(PROPERTY_HUNGER, item->specs->hunger);
  _update_property(PROPERTY_LIFE, item->specs->life);
  _update_property(PROPERTY_SLEEPINESS, item->specs->sleepiness);
  _pending_poos = LV_MIN(_pending_poos + item->specs->poo, (int)MAX_POOS);
  _pending_pees = LV_MIN(_pending_pees + item->specs->pee, (int)MAX_PEES);

  if (item->specs->snack) {
    _snacks++;
    if (_snacks >= SNACKS_SICKNESS && !_is_sick) {
      _is_sick = true;
      _events |= EVENT_GOT_SICK;
    }
  }

  return ACTION_DONE;
}

ActionResult Pokemon::heal(void) {
  if (_potions <= 0 || _is_egg) {
    return ACTION_NO_EFFECT;
  }

  _update_property(PROPERTY_LIFE, 25);
  _update_property(PROPERTY_POTIONS, -1);

  if (_is_sick) {
    _is_sick = false;
    _snacks = 0;
    _add_friendship(3);
    _events |= EVENT_CURED;
  }

  return ACTION_DONE;
}

ActionResult Pokemon::train(void) {
  if (_is_sick) {
    return ACTION_REFUSED_SICK;
  }

  if (_sleepiness < 10 || _hunger == 0) {
    return ACTION_REFUSED_TIRED;
  }

  _update_property(PROPERTY_HUNGER, -2);
  _update_property(PROPERTY_SLEEPINESS, -8);
  _add_xp(6 + hal_random(0, 5));

  return ACTION_DONE;
}

ActionResult Pokemon::play(void) {
  if (_is_sick) {
    return ACTION_REFUSED_SICK;
  }

  if (_sleepiness < 5) {
    return ACTION_REFUSED_TIRED;
  }

  _update_property(PROPERTY_MOOD, 3);
  _update_property(PROPERTY_SLEEPINESS, -3);

  if (_last_update - _last_play_friendship >= PLAY_FRIENDSHIP_COOLDOWN) {
    _last_play_friendship = _last_update;
    _add_friendship(2);
  }

  return ACTION_DONE;
}

/**
 * Evolution stones, like in the games
 */
ActionResult Pokemon::use_stone(Stone stone) {
  if (_stones[stone] == 0 || _is_egg) {
    return ACTION_NO_EFFECT;
  }

  int target = 0;
  if (_number == POKEMON_PIKACHU && stone == STONE_THUNDER) {
    target = POKEMON_RAICHU;
  } else if (_number == POKEMON_EEVEE) {
    switch (stone) {
      case STONE_THUNDER:
        target = POKEMON_JOLTEON;
        break;
      case STONE_WATER:
        target = POKEMON_VAPOREON;
        break;
      case STONE_FIRE:
        target = POKEMON_FLAREON;
        break;
      case STONE_LEAF:
        target = POKEMON_LEAFEON;
        break;
      case STONE_ICE:
        target = POKEMON_GLACEON;
        break;
      default:
        break;
    }
  }

  if (target == 0) {
    return ACTION_NO_EFFECT;
  }

  _stones[stone]--;
  _evolve_to(target);

  return ACTION_DONE;
}

bool Pokemon::pet(void) {
  if (_is_egg || _is_sleeping || _last_update - _last_pet < PET_COOLDOWN) {
    return false;
  }

  _last_pet = _last_update;
  _add_friendship(1);
  _update_property(PROPERTY_MOOD, 1);

  return true;
}

void Pokemon::shake(void) {
  if (_is_egg) {
    tap_egg();
    return;
  }

  if (_is_sleeping) {
    // Nobody likes to be woken up like that
    wake_up();
    _update_property(PROPERTY_MOOD, -2);
    if (is_night(_game_time)) {
      _add_friendship(-5);
    }
  } else {
    _update_property(PROPERTY_MOOD, -1);
  }
}

void Pokemon::sleep(void) {
  if (_is_sleeping || _is_egg) {
    return;
  }

  _set_sleeping(true);

  // Going to bed on time builds trust, once per night
  if (is_night(_game_time)) {
    uint32_t night = (_game_time - HOUR_WAKE_UP * 3600UL) / 86400;
    if (night != _last_bedtime_day) {
      _last_bedtime_day = night;
      _add_friendship(2);
    }
  }
}

void Pokemon::wake_up(void) { _set_sleeping(false); }

void Pokemon::clean_poo(void) {
  _update_property(PROPERTY_POOS, -1);
  _add_friendship(1);
}

void Pokemon::clean_pee(void) {
  _update_property(PROPERTY_PEES, -1);
  _add_friendship(1);
}

void Pokemon::_hatch(uint32_t now) {
  _hatch_seconds = 0;
  _is_egg = false;
  _birth = now;
  _events |= EVENT_HATCHED;
}

/**
 * Walking with the device: the egg hatches after enough steps, a hatched
 * Pokemon enjoys the walk
 */
void Pokemon::add_steps(uint16_t steps) {
  if (_is_ko || steps == 0) {
    return;
  }

  // Pedometer: steps of the day, reset at midnight, and of all time
  uint32_t day = _last_update / 86400;
  if (day != _steps_day) {
    _steps_day = day;
    _steps_today = 0;
  }
  _steps_today += steps;
  _total_steps += steps;

  if (_is_egg) {
    _egg_steps = steps > EGG_HATCH_STEPS - _egg_steps ? EGG_HATCH_STEPS : _egg_steps + steps;
    if (_egg_steps >= EGG_HATCH_STEPS) {
      _hatch(_game_time);
    }
    return;
  }

  if (_is_sleeping) {
    return;
  }

  _walk_steps += steps;
  while (_walk_steps >= WALK_BONUS_STEPS) {
    _walk_steps -= WALK_BONUS_STEPS;
    _update_property(PROPERTY_MOOD, 1);
    _add_friendship(1);
  }
}

/**
 * Taking care of the egg makes it hatch a bit sooner
 */
void Pokemon::tap_egg(void) {
  if (_is_egg && _hatch_seconds > 15) {
    _hatch_seconds -= 5;
  }
}

/**
 * Playing a mini-game cheers the Pokemon up, and sometimes brings back an
 * evolution stone
 *
 * @return the stone found, or -1
 */
int8_t Pokemon::reward_minigame(int32_t score) {
  if (_is_egg) {
    return -1;
  }

  int32_t mood = score / 3 + 1;
  _update_property(PROPERTY_MOOD, mood > 5 ? 5 : mood);
  _update_property(PROPERTY_SLEEPINESS, -5);
  _add_friendship(3);
  _add_xp(score < 2 ? 2 : (score > 30 ? 30 : score));

  int32_t chance = score * 2 > 40 ? 40 : score * 2;
  if (score >= 5 && hal_random(0, 100) < chance) {
    Stone stone = (Stone)hal_random(0, STONE_COUNT);
    if (_stones[stone] < MAX_STONES) {
      _stones[stone]++;
    }
    return stone;
  }

  return -1;
}

const lv_image_dsc_t* Pokemon::get_image(int number, bool sick) {
  switch (number) {
    case POKEMON_EEVEE:
      return sick ? &pokemon_sick_133 : &pokemon_133;
    case POKEMON_VAPOREON:
      return sick ? &pokemon_sick_134 : &pokemon_134;
    case POKEMON_JOLTEON:
      return sick ? &pokemon_sick_135 : &pokemon_135;
    case POKEMON_FLAREON:
      return sick ? &pokemon_sick_136 : &pokemon_136;
    case POKEMON_ESPEON:
      return sick ? &pokemon_sick_196 : &pokemon_196;
    case POKEMON_UMBREON:
      return sick ? &pokemon_sick_197 : &pokemon_197;
    case POKEMON_LEAFEON:
      return sick ? &pokemon_sick_470 : &pokemon_470;
    case POKEMON_GLACEON:
      return sick ? &pokemon_sick_471 : &pokemon_471;
    case POKEMON_PIKACHU:
      return sick ? &pokemon_sick_25 : &pokemon_25;
    case POKEMON_RAICHU:
      return sick ? &pokemon_sick_26 : &pokemon_26;
    case POKEMON_PICHU:
    default:
      return sick ? &pokemon_sick_172 : &pokemon_172;
  }
}

const void* Pokemon::get_avatar(void) {
  switch (_number) {
    case POKEMON_EEVEE:
      return &eevee_face;
    case POKEMON_VAPOREON:
      return &vaporeon_face;
    case POKEMON_JOLTEON:
      return &jolteon_face;
    case POKEMON_FLAREON:
      return &flareon_face;
    case POKEMON_ESPEON:
      return &espeon_face;
    case POKEMON_UMBREON:
      return &umbreon_face;
    case POKEMON_LEAFEON:
      return &leafeon_face;
    case POKEMON_GLACEON:
      return &glaceon_face;
    case POKEMON_PIKACHU:
      return &pikachu_face;
    case POKEMON_RAICHU:
      return &raichu_face;
    case POKEMON_PICHU:
    default:
      return &pichu_face;
  }
}

const char* Pokemon::get_description(void) {
  if (_is_egg) {
    return _("pokemon.egg.description");
  }

  switch (_number) {
    case POKEMON_EEVEE:
      return _("pokemon.eevee.description");
    case POKEMON_VAPOREON:
      return _("pokemon.vaporeon.description");
    case POKEMON_JOLTEON:
      return _("pokemon.jolteon.description");
    case POKEMON_FLAREON:
      return _("pokemon.flareon.description");
    case POKEMON_ESPEON:
      return _("pokemon.espeon.description");
    case POKEMON_UMBREON:
      return _("pokemon.umbreon.description");
    case POKEMON_LEAFEON:
      return _("pokemon.leafeon.description");
    case POKEMON_GLACEON:
      return _("pokemon.glaceon.description");
    case POKEMON_PIKACHU:
      return _("pokemon.pikachu.description");
    case POKEMON_RAICHU:
      return _("pokemon.raichu.description");
    case POKEMON_PICHU:
    default:
      return _("pokemon.pichu.description");
  }
}

const char* Pokemon::get_name(int number) {
  switch (number) {
    case POKEMON_EEVEE:
      return _("pokemon.eevee.name");
    case POKEMON_VAPOREON:
      return _("pokemon.vaporeon.name");
    case POKEMON_JOLTEON:
      return _("pokemon.jolteon.name");
    case POKEMON_FLAREON:
      return _("pokemon.flareon.name");
    case POKEMON_ESPEON:
      return _("pokemon.espeon.name");
    case POKEMON_UMBREON:
      return _("pokemon.umbreon.name");
    case POKEMON_LEAFEON:
      return _("pokemon.leafeon.name");
    case POKEMON_GLACEON:
      return _("pokemon.glaceon.name");
    case POKEMON_PIKACHU:
      return _("pokemon.pikachu.name");
    case POKEMON_RAICHU:
      return _("pokemon.raichu.name");
    case POKEMON_PICHU:
    default:
      return _("pokemon.pichu.name");
  }
}

const lv_image_dsc_t* Pokemon::get_stone_image(Stone stone) {
  switch (stone) {
    case STONE_WATER:
      return &stone_water;
    case STONE_FIRE:
      return &stone_fire;
    case STONE_LEAF:
      return &stone_leaf;
    case STONE_ICE:
      return &stone_ice;
    case STONE_THUNDER:
    default:
      return &stone_thunder;
  }
}

const char* Pokemon::get_stone_name(Stone stone) {
  switch (stone) {
    case STONE_WATER:
      return _("bag.stone.water");
    case STONE_FIRE:
      return _("bag.stone.fire");
    case STONE_LEAF:
      return _("bag.stone.leaf");
    case STONE_ICE:
      return _("bag.stone.ice");
    case STONE_THUNDER:
    default:
      return _("bag.stone.thunder");
  }
}

void Pokemon::load(JsonObject pokemon) {
  _number = pokemon["number"] | POKEMON_PICHU;
  _level = pokemon["level"] | 1;
  _life = pokemon["life"] | MAX_LIFE;
  _mood = pokemon["mood"] | MAX_MOOD;
  _hunger = pokemon["hunger"] | MAX_HUNGER;
  _sleepiness = pokemon["sleepiness"] | MAX_SLEEPINESS;
  _is_sleeping = pokemon["is_sleeping"] | false;
  _potions = pokemon["potions"] | 0;
  _poos = pokemon["poos"] | 0;
  _pees = pokemon["pees"] | 0;

  if (pokemon["version"].isNull()) {
    // Save from the first version: no egg, no clock, start the time from now
    _is_egg = false;
    _last_update = 0;
    return;
  }

  _xp = pokemon["xp"] | 0;
  _friendship = pokemon["friendship"] | FRIENDSHIP_BASE;
  _care_mistakes = pokemon["care_mistakes"] | 0;
  _is_sick = pokemon["is_sick"] | false;
  _is_egg = pokemon["is_egg"] | false;
  _hatch_seconds = pokemon["hatch_seconds"] | 0;
  _egg_steps = pokemon["egg_steps"] | 0;
  _walk_steps = pokemon["walk_steps"] | 0;
  _steps_today = pokemon["steps_today"] | 0;
  _steps_day = pokemon["steps_day"] | 0;
  _total_steps = pokemon["total_steps"] | 0;
  _birth = pokemon["birth"] | 0;
  _last_update = pokemon["last_update"] | 0;
  _game_time = pokemon["game_time"] | 0;
  _speed = (TimeSpeed)(pokemon["speed"] | (int)SPEED_FAST);
  if (_speed >= SPEED_COUNT) {
    _speed = SPEED_FAST;
  }
  if (_game_time == 0) {
    // Saved before the game clock: the Pokemon wakes up in the morning
    _last_update = 0;
  }
  _last_bedtime_day = pokemon["last_bedtime_day"] | 0;
  _pending_poos = pokemon["pending_poos"] | 0;
  _pending_pees = pokemon["pending_pees"] | 0;
  _snacks = pokemon["snacks"] | 0;
  _call_seconds = pokemon["call_seconds"] | 0;
  _call_real_seconds = pokemon["call_real_seconds"] | 0;

  JsonArray stones = pokemon["stones"];
  for (uint8_t i = 0; i < STONE_COUNT && i < stones.size(); i++) {
    _stones[i] = stones[i] | 0;
  }

  JsonObject acc = pokemon["acc"];
  _acc_hunger = acc["hunger"] | 0;
  _acc_mood = acc["mood"] | 0;
  _acc_energy = acc["energy"] | 0;
  _acc_life = acc["life"] | 0;
  _acc_poo = acc["poo"] | 0;
  _acc_pee = acc["pee"] | 0;
  _acc_dirty = acc["dirty"] | 0;
  _acc_snack = acc["snack"] | 0;
  _acc_potion = acc["potion"] | 0;

  _was_night = is_night(_game_time);
}

void Pokemon::save(JsonObject pokemon) {
  pokemon["version"] = 2;
  pokemon["number"] = _number;
  pokemon["level"] = _level;
  pokemon["xp"] = _xp;
  pokemon["life"] = _life;
  pokemon["mood"] = _mood;
  pokemon["hunger"] = _hunger;
  pokemon["sleepiness"] = _sleepiness;
  pokemon["is_sleeping"] = _is_sleeping;
  pokemon["potions"] = _potions;
  pokemon["poos"] = _poos;
  pokemon["pees"] = _pees;
  pokemon["friendship"] = _friendship;
  pokemon["care_mistakes"] = _care_mistakes;
  pokemon["is_sick"] = _is_sick;
  pokemon["is_egg"] = _is_egg;
  pokemon["hatch_seconds"] = _hatch_seconds;
  pokemon["egg_steps"] = _egg_steps;
  pokemon["walk_steps"] = _walk_steps;
  pokemon["steps_today"] = _steps_today;
  pokemon["steps_day"] = _steps_day;
  pokemon["total_steps"] = _total_steps;
  pokemon["birth"] = _birth;
  pokemon["last_update"] = _last_update;
  pokemon["game_time"] = _game_time;
  pokemon["speed"] = (int)_speed;
  pokemon["last_bedtime_day"] = _last_bedtime_day;
  pokemon["pending_poos"] = _pending_poos;
  pokemon["pending_pees"] = _pending_pees;
  pokemon["snacks"] = _snacks;
  pokemon["call_seconds"] = _call_seconds;
  pokemon["call_real_seconds"] = _call_real_seconds;

  JsonArray stones = pokemon["stones"].to<JsonArray>();
  for (uint8_t i = 0; i < STONE_COUNT; i++) {
    stones.add(_stones[i]);
  }

  JsonObject acc = pokemon["acc"].to<JsonObject>();
  acc["hunger"] = _acc_hunger;
  acc["mood"] = _acc_mood;
  acc["energy"] = _acc_energy;
  acc["life"] = _acc_life;
  acc["poo"] = _acc_poo;
  acc["pee"] = _acc_pee;
  acc["dirty"] = _acc_dirty;
  acc["snack"] = _acc_snack;
  acc["potion"] = _acc_potion;
}
