#include <M5Core2.h>
#include <lvgl.h>
#include "Utils.h"
#include "Pokemon.h"
#include "assets/pokemon/172.c"

Pokemon* Pokemon::instance = nullptr;

Pokemon::Pokemon() {
  LV_IMG_DECLARE(pokemon_172);

  _image = lv_gif_create(lv_scr_act());
  lv_gif_set_src(_image, &pokemon_172);
  lv_obj_align(_image, LV_ALIGN_CENTER, 0, 0);

  lv_anim_t anim;

  lv_anim_init(&anim);
  lv_anim_set_var(&anim, _image);
  lv_anim_set_values(&anim, 160, 80);
  lv_anim_set_path_cb(&anim, lv_anim_path_overshoot);
  lv_anim_set_time(&anim, 1500);
  lv_anim_set_repeat_count(&anim, 0);
  lv_anim_set_exec_cb(&anim, anim_y_callback);

  lv_anim_start(&anim);
};

void Pokemon::loop() {}

void Pokemon::train() {
  _level += 1;
  hungry(2);
  tiredness(10);
}

void Pokemon::play() {
  _mood += 1;
  if (_mood > MAX_MOOD) {
    _mood = MAX_MOOD;
  }
}

void Pokemon::eat() {
  _hunger -= 1;
  if (_hunger < 0) {
    // @TODO random sick because eat too much
    _hunger = 0;
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
  _sleepiness -= 5;
  if (_sleepiness < 0) {
    _sleepiness = 0;
  }
}

void Pokemon::wake_up() { _is_sleeping = false; }

void Pokemon::hungry(int8_t number) {
  _hunger += number;
  if (_hunger > MAX_HUNGER) {
    _hunger = MAX_HUNGER;
    // @TODO random sick or die
  }
}

void Pokemon::tiredness(int8_t number) {
  _sleepiness += number;
  if (_sleepiness > MAX_SLEEPINESS) {
    _sleepiness = MAX_SLEEPINESS;
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

// void random_move() {
//   long current_x = lv_obj_get_x(_image);
//   long new_x = current_x + random(-5, 5);
//   if (new_x > LV_HOR_RES_MAX) {
//     new_x = LV_HOR_RES_MAX;
//   }

//   if (new_x <= 0) {
//     new_x = 0;
//   }

//   Serial.printf("New Pokemon position: %ld to %ld\r\n", current_x, new_x);

//   lv_obj_set_x(_image, new_x);
// }
