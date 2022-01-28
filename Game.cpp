#include "includes/lodepng.h"
#include <lvgl.h>
#include "Game.h"
#include "ActionsMenu.h"
#include "Menu.h"
#include "Pokemon.h"
#include "Utils.h"
#include "assets/background/background_1.c"
#include "assets/background/background_2.c"
#include "assets/background/background_3.c"
#include "assets/background/background_4.c"
#include "assets/background/background_5.c"
#include "assets/background/background_6.c"
#include "assets/background/background_7.c"
#include "assets/background/background_8.c"
#include "assets/background/background_9.c"
#include "assets/background/background_10.c"
#include "assets/background/background_11.c"
#include "assets/background/background_12.c"
#include "assets/background/background_13.c"
#include "assets/background/background_14.c"
#include "assets/background/background_15.c"
#include "assets/background/background_16.c"
#include "assets/background/background_17.c"
#include "assets/background/background_18.c"
#include "assets/background/background_19.c"
#include "assets/background/background_20.c"

LV_IMG_DECLARE(background_1);
LV_IMG_DECLARE(background_2);
LV_IMG_DECLARE(background_3);
LV_IMG_DECLARE(background_4);
LV_IMG_DECLARE(background_5);
LV_IMG_DECLARE(background_6);
LV_IMG_DECLARE(background_6);
LV_IMG_DECLARE(background_7);
LV_IMG_DECLARE(background_8);
LV_IMG_DECLARE(background_9);
LV_IMG_DECLARE(background_10);
LV_IMG_DECLARE(background_11);
LV_IMG_DECLARE(background_12);
LV_IMG_DECLARE(background_13);
LV_IMG_DECLARE(background_14);
LV_IMG_DECLARE(background_15);
LV_IMG_DECLARE(background_16);
LV_IMG_DECLARE(background_17);
LV_IMG_DECLARE(background_18);
LV_IMG_DECLARE(background_19);
LV_IMG_DECLARE(background_20);

static const lv_img_dsc_t* anim_night[11] = {
    &background_6, &background_7, &background_8, &background_9, &background_10, &background_11, &background_12, &background_13, &background_14, &background_15, &background_16,
};
static const lv_img_dsc_t* anim_day[11] = {
    &background_16, &background_17, &background_18, &background_19, &background_20, &background_1, &background_2, &background_3, &background_4, &background_5, &background_6,
};

static void night_animation(void* img, int32_t id) {
  Serial.printf("Animated day image: %d\r\n", id);
  lv_img_set_src((lv_obj_t*)img, anim_night[id]);
}

static void day_animation(void* img, int32_t id) {
  Serial.printf("Animated day image: %d\r\n", id);
  lv_img_set_src((lv_obj_t*)img, anim_day[id]);
}

Game* Game::instance = nullptr;

Game::Game() {}

void Game::setup() {
  _screen = create_window();
  lv_scr_load(_screen);

  Menu* menu = Menu::getInstance();
  menu->setup(_screen);

  ActionsMenu* actions_menu = ActionsMenu::getInstance();
  actions_menu->setup(_screen);

  lv_obj_t* _background = lv_img_create(_screen);
  lv_img_set_src(_background, anim_day[0]);
  lv_obj_set_pos(_background, 0, 0);

  lv_anim_init(&_anim);
  lv_anim_set_var(&_anim, _background);
  lv_anim_set_values(&_anim, 0, 10);
  lv_anim_set_path_cb(&_anim, lv_anim_path_linear);
  lv_anim_set_time(&_anim, 1500);
  lv_anim_set_repeat_count(&_anim, 0);

  switch_to_day();

  _mood_bar = lv_game_bar_create(_screen, LV_PALETTE_GREEN);
  lv_obj_set_pos(_mood_bar, 10, 30);
  lv_bar_set_value(_mood_bar, 0, LV_ANIM_ON);

  _life_bar = lv_game_bar_create(_screen, LV_PALETTE_RED);
  lv_obj_set_pos(_life_bar, 10, 70);
  lv_bar_set_value(_life_bar, 0, LV_ANIM_ON);

  _sleepiness_bar = lv_game_bar_create(_screen, LV_PALETTE_BLUE);
  lv_obj_set_pos(_sleepiness_bar, 180, 30);
  lv_bar_set_value(_sleepiness_bar, 0, LV_ANIM_ON);

  _hunger_bar = lv_game_bar_create(_screen, LV_PALETTE_YELLOW);
  lv_obj_set_pos(_hunger_bar, 180, 70);
  lv_bar_set_value(_hunger_bar, 0, LV_ANIM_ON);
}

void Game::switch_to_day() {
  lv_anim_set_exec_cb(&_anim, day_animation);
  lv_anim_start(&_anim);
}

void Game::switch_to_night() {
  lv_anim_set_exec_cb(&_anim, night_animation);
  lv_anim_start(&_anim);
}

void Game::loop() {
  Pokemon* p = Pokemon::getInstance();
  p->loop();

  lv_bar_set_value(_mood_bar, p->get_mood(), LV_ANIM_ON);
  lv_bar_set_value(_life_bar, p->get_life(), LV_ANIM_ON);
  lv_bar_set_value(_sleepiness_bar, p->get_sleepiness(), LV_ANIM_ON);
  lv_bar_set_value(_hunger_bar, p->get_hunger(), LV_ANIM_ON);

  if (check_action_time(_last_eat_time, PERIOD_EAT)) {
    p->hungry(2);
  }

  if (p->is_sleeping() == true) {
    if (check_action_time(_last_sleep_time, PERIOD_SLEEP)) {
      p->sleep();
    }
  } else {
    if (check_action_time(_last_time_without_sleep, PERIOD_WITHOUT_SLEEP)) {
      p->tiredness(10);
    }
  }
}

void Game::action_train() {}

void Game::action_eat() {}

void Game::action_heal() {}

void Game::action_sleep() {
  Pokemon* p = Pokemon::getInstance();
  if (p->is_sleeping() == false) {
    switch_to_night();

    p->sleep();
  }
}

void Game::action_wake_up() {
  Pokemon* p = Pokemon::getInstance();
  if (p->is_sleeping() == true) {
    switch_to_day();
    p->wake_up();
  }
}
