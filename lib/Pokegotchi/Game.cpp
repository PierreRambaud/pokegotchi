#include <lvgl.h>
#include "lv_i18n.h"
#include "Game.h"
#include "Menu.h"
#include "Pokemon.h"
#include "Utils.h"

#define ANIMATION_NIGHT 11
#define ANIMATION_DAY 11

static const char* anim_night[ANIMATION_NIGHT] = {
    "L:background/6.png",   "L:background/7.png",
    "L:background/8.png",   "L:background/9.png",
    "L:background/10.png",  "L:background/11.png",
    "L:background/12.png",  "L:background/13.png",
    "L:background/14.png",  "L:background/15.png",
    "L:background/16.png"
};
static const char* anim_day[ANIMATION_DAY] = {
    "L:background/16.png",  "L:background/17.png",
    "L:background/18.png",  "L:background/19.png",
    "L:background/20.png",  "L:background/1.png",
    "L:background/2.png",   "L:background/3.png",
    "L:background/4.png",   "L:background/5.png",
    "L:background/6.png"
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
  lv_anim_set_values(&_anim, 0, 11);
  lv_anim_set_path_cb(&_anim, lv_anim_path_linear);
  lv_anim_set_time(&_anim, 1200);
  lv_anim_set_repeat_count(&_anim, 0);

  switch_to_day();

  _mood_bar = lv_game_bar_create(_screen, LV_PALETTE_GREEN, _("bar.mood"), 10, 25, MAX_MOOD);
  lv_bar_set_value(_mood_bar, 0, LV_ANIM_ON);

  _life_bar = lv_game_bar_create(_screen, LV_PALETTE_RED, _("bar.life"), 10, 70, MAX_LIFE);
  lv_bar_set_value(_life_bar, 0, LV_ANIM_ON);

  _sleepiness_bar = lv_game_bar_create(_screen, LV_PALETTE_BLUE, _("bar.sleepiness"), 185, 25, MAX_SLEEPINESS);
  lv_bar_set_value(_sleepiness_bar, 0, LV_ANIM_ON);

  _hunger_bar = lv_game_bar_create(_screen, LV_PALETTE_YELLOW, _("bar.hunger"), 185, 70, MAX_HUNGER);
  lv_bar_set_value(_hunger_bar, 0, LV_ANIM_ON);

  lv_obj_t* level_label = lv_label_create(_screen);
  lv_label_set_text(level_label, _("game.level"));
  lv_obj_add_style(level_label, &style_game_label, 0);
  lv_obj_align(level_label, LV_ALIGN_TOP_MID, 0, 10);

  _level_indic = lv_label_create(_screen);
  lv_obj_align_to(_level_indic, level_label, LV_ALIGN_OUT_BOTTOM_MID, 10, 0);
  lv_obj_add_style(_level_indic, &style_game_label, 0);
  lv_label_set_text(_level_indic, "1");
}

void Game::switch_to_day() {
  lv_anim_set_exec_cb(&_anim, day_animation);
  lv_anim_start(&_anim);
  lv_style_set_text_color(&style_game_label, lv_color_black());
  lv_obj_report_style_change(&style_game_label);
}

void Game::switch_to_night() {
  lv_anim_set_exec_cb(&_anim, night_animation);
  lv_anim_start(&_anim);
  lv_style_set_text_color(&style_game_label, lv_color_white());
  lv_obj_report_style_change(&style_game_label);
}

void Game::loop() {
  Pokemon* p = Pokemon::getInstance();
  p->loop();

  lv_bar_set_value(_mood_bar, p->get_mood(), LV_ANIM_ON);
  lv_bar_set_value(_life_bar, p->get_life(), LV_ANIM_ON);
  lv_bar_set_value(_sleepiness_bar, p->get_sleepiness(), LV_ANIM_ON);
  lv_bar_set_value(_hunger_bar, p->get_hunger(), LV_ANIM_ON);
  lv_label_set_text_fmt(_level_indic, "%d", p->get_level());
}

void Game::action_train() {
  Pokemon* p = Pokemon::getInstance();
  p->train();
}

void Game::action_play() {
  Pokemon* p = Pokemon::getInstance();
  p->play();
}

void Game::action_eat(Item* item) {
  Pokemon* p = Pokemon::getInstance();
  p->eat(item);
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
