#include <M5Core2.h>
#include "Utils.h"
#include "Pokemon.h"

using namespace Pokegotchi;

Pokemon* Pokemon::_instance = nullptr;

Pokemon::Pokemon(int number) {
  _number = number;
  _last_boredom_time = _last_hunger_time = _last_sleep_time = _last_without_sleep_time = _last_simple_check_time = millis();
};

void Pokemon::loop() {
  if (check_action_time(_last_hunger_time, PERIOD_HUNGER)) {
    _update_property(PROPERTY_HUNGER, -2);
  }

  if (is_sleeping() == false && check_action_time(_last_boredom_time, PERIOD_BOREDOM)) {
    _update_property(PROPERTY_MOOD, -1);
  }

  if (is_sleeping() == true) {
    if (check_action_time(_last_sleep_time, PERIOD_SLEEP)) {
      sleep();
    }
  } else {
    if (check_action_time(_last_without_sleep_time, PERIOD_WITHOUT_SLEEP)) {
      _update_property(PROPERTY_SLEEPINESS, -10);
    }
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

void Pokemon::clean_poo() { _update_property(PROPERTY_POOS, -1); }

void Pokemon::clean_pee() { _update_property(PROPERTY_PEES, -1); }

void Pokemon::train() {
  if (_level < 100) {
    _level += 1;
  }

  _update_property(PROPERTY_HUNGER, -2);
  _update_property(PROPERTY_SLEEPINESS, -10);
}

void Pokemon::play() { _update_property(PROPERTY_MOOD, 2); }

void Pokemon::eat(Item* item) {
  _update_property(PROPERTY_MOOD, item->specs->mood);
  _update_property(PROPERTY_HUNGER, item->specs->hunger);
  _update_property(PROPERTY_LIFE, item->specs->life);
  _update_property(PROPERTY_SLEEPINESS, item->specs->sleepiness);
  _update_property(PROPERTY_POOS, item->specs->poo);
  _update_property(PROPERTY_PEES, item->specs->pee);
}

void Pokemon::heal(int8_t restore_points) { _update_property(PROPERTY_LIFE, restore_points); }

void Pokemon::sleep() {
  _is_sleeping = true;
  _update_property(PROPERTY_SLEEPINESS, 5);
}

void Pokemon::wake_up() { _is_sleeping = false; }
