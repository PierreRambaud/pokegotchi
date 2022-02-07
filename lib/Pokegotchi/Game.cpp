#include <lvgl.h>
#include "lv_i18n.h"
#include "Game.h"
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

static const lv_img_dsc_t* anim_night[ANIMATION_NIGHT] = {
    &background_6, &background_7, &background_8, &background_9, &background_10, &background_11, &background_12, &background_13, &background_14, &background_15, &background_16,
};
static const lv_img_dsc_t* anim_day[ANIMATION_DAY] = {
    &background_16, &background_17, &background_18, &background_19, &background_20, &background_1, &background_2, &background_3, &background_4, &background_5, &background_6,
};

static void night_animation(void* img, int32_t id) { lv_img_set_src((lv_obj_t*)img, anim_night[id]); }

static void day_animation(void* img, int32_t id) { lv_img_set_src((lv_obj_t*)img, anim_day[id]); }

Game* Game::instance = nullptr;

Game::Game() {}

void Game::setup() {
  _screen = create_window();
  lv_scr_load(_screen);

  Menu* menu = Menu::getInstance();
  menu->setup(_screen);

  ActionsMenu* actions_menu = ActionsMenu::getInstance();
  actions_menu->setup(_screen);

  lv_obj_t* background_image = lv_img_create(_screen);
  lv_img_set_src(background_image, anim_day[0]);
  lv_obj_set_pos(background_image, 0, 0);

  lv_anim_init(&_anim);
  lv_anim_set_var(&_anim, background_image);
  lv_anim_set_values(&_anim, 0, 10);
  lv_anim_set_path_cb(&_anim, lv_anim_path_linear);
  lv_anim_set_time(&_anim, 1500);
  lv_anim_set_repeat_count(&_anim, 0);

  switch_to_day();

  _mood_bar = lv_game_bar_create(_screen, LV_PALETTE_GREEN, _("bar.mood"), 10, 25, MAX_MOOD);
  lv_bar_set_value(_mood_bar, 0, LV_ANIM_ON);

  _life_bar = lv_game_bar_create(_screen, LV_PALETTE_RED, _("bar.life"), 10, 70, MAX_LIFE);
  lv_bar_set_value(_life_bar, 0, LV_ANIM_ON);

  _sleepiness_bar = lv_game_bar_create(_screen, LV_PALETTE_BLUE, _("bar.sleepiness"), 180, 25, MAX_SLEEPINESS);
  lv_bar_set_value(_sleepiness_bar, 0, LV_ANIM_ON);

  _hunger_bar = lv_game_bar_create(_screen, LV_PALETTE_YELLOW, _("bar.hunger"), 180, 70, MAX_HUNGER);
  lv_bar_set_value(_hunger_bar, 0, LV_ANIM_ON);
}

void Game::switch_to_day() {
  lv_anim_set_exec_cb(&_anim, day_animation);
  lv_anim_start(&_anim);
  lv_style_set_text_color(&style_game_bar_label, lv_color_black());
  lv_obj_report_style_change(&style_game_bar_label);
}

void Game::switch_to_night() {
  lv_anim_set_exec_cb(&_anim, night_animation);
  lv_anim_start(&_anim);
  lv_style_set_text_color(&style_game_bar_label, lv_color_white());
  lv_obj_report_style_change(&style_game_bar_label);
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

void Game::action_train() {
  Pokemon* p = Pokemon::getInstance();
  p->train();
}

void Game::action_eat() {
  Pokemon* p = Pokemon::getInstance();
  p->eat();
}

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
