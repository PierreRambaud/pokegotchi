#include <M5Core2.h>
#include <lvgl.h>
#include "Utils.h"
#include "Pokemon.h"

Pokemon* Pokemon::_instance = nullptr;

Pokemon::Pokemon(int number) { _number = number; };

void Pokemon::animate() {
}

void Pokemon::loop() {
  if (check_action_time(_last_hunger_time, PERIOD_HUNGER)) {
    hungry(2);
  }

  if (is_sleeping() == false && check_action_time(_last_boredom_time, PERIOD_BOREDOM)) {
    boredom(1);
  }

  if (is_sleeping() == true) {
    if (check_action_time(_last_sleep_time, PERIOD_SLEEP)) {
      sleep();
    }
  } else {
    if (check_action_time(_last_without_sleep_time, PERIOD_WITHOUT_SLEEP)) {
      tiredness(10);
    }
  }

  if (check_action_time(_last_poo_time, PERIOD_POO)) {
    poo();
  }

  if (check_action_time(_last_simple_check_time, PERIOD_SIMPLE_CHECK)) {
    simple_check();
  }
}

void Pokemon::simple_check() {
  if (_mood == 0) {
    _life -= 3;
  }

  if (_hunger == 0) {
    _life -= 5;
  }

  if (_sleepiness == 0) {
    _life -= 4;
  }

  if (_life <= 0) {
    _life = 0;
    _is_ko = true;
  }
}

void Pokemon::poo() {
  _poos += 1;
}

void Pokemon::clean_poo() {
  if (_poos > 0) {
    _poos -= 1;
  }
}

void Pokemon::train() {
  if (_level < 100) {
    _level += 1;
  }

  hungry(2);
  tiredness(10);
}

void Pokemon::play() {
  _mood += 2;
  if (_mood > MAX_MOOD) {
    _mood = MAX_MOOD;
  }
}

void Pokemon::eat(Item* item) {
  _hunger += 5;
  if (_hunger > MAX_HUNGER) {
    // @TODO random sick because eat too much
    _hunger = MAX_HUNGER;
  }
}

void Pokemon::heal(int8_t restore_points) {
  _life += restore_points;
  if (_life > MAX_LIFE) {
    _life = MAX_LIFE;
  }
}

void Pokemon::sleep() {
  _is_sleeping = true;
  _sleepiness += 5;
  if (_sleepiness > MAX_SLEEPINESS) {
    _sleepiness = MAX_SLEEPINESS;
  }
}

void Pokemon::wake_up() { _is_sleeping = false; }

void Pokemon::hungry(int8_t number) {
  _hunger -= number;
  if (_hunger < 0) {
    _hunger = 0;
    // @TODO random sick or die
  }
}

void Pokemon::tiredness(int8_t number) {
  _sleepiness -= number;
  if (_sleepiness < 0) {
    _sleepiness = 0;
    // @TODO random fall asleep or die
  }
}

void Pokemon::boredom(int8_t number) {
  _mood -= number;
  if (_mood < 0) {
    _mood = 0;
    // @TODO random act or die
  }
}
