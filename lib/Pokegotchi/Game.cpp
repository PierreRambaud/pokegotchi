#include <lvgl.h>
#include "lv_i18n.h"
#include "Game.h"
#include "Menu.h"
#include "Pokemon.h"
#include "Utils.h"

#define ANIMATION_NIGHT 11
#define ANIMATION_DAY 11

LV_IMG_DECLARE(background_1)
LV_IMG_DECLARE(background_2)
LV_IMG_DECLARE(background_3)
LV_IMG_DECLARE(background_4)
LV_IMG_DECLARE(background_5)
LV_IMG_DECLARE(background_6)
LV_IMG_DECLARE(background_7)
LV_IMG_DECLARE(background_8)
LV_IMG_DECLARE(background_9)
LV_IMG_DECLARE(background_10)
LV_IMG_DECLARE(background_11)
LV_IMG_DECLARE(background_12)
LV_IMG_DECLARE(background_13)
LV_IMG_DECLARE(background_14)
LV_IMG_DECLARE(background_15)
LV_IMG_DECLARE(background_16)
LV_IMG_DECLARE(background_17)
LV_IMG_DECLARE(background_18)
LV_IMG_DECLARE(background_19)
LV_IMG_DECLARE(background_20)

static const lv_img_dsc_t* anim_night[ANIMATION_NIGHT] = {
    &background_6,   &background_7,
    &background_8,   &background_9,
    &background_10,  &background_11,
    &background_12,  &background_13,
    &background_14,  &background_15,
    &background_16,
};
static const lv_img_dsc_t* anim_day[ANIMATION_DAY] = {
    &background_16,  &background_17,
    &background_18,  &background_19,
    &background_20,  &background_1,
    &background_2,   &background_3,
    &background_4,   &background_5,
    &background_6,
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
