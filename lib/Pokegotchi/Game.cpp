#include "lvgl.h"
#include "lv_i18n.h"
#include "Game.h"
#include "GameMenu.h"
#include "Utils.h"

#define ANIMATION_NIGHT 6
#define ANIMATION_DAY 6

using namespace Pokegotchi;

LV_IMG_DECLARE(game_pee);
LV_IMG_DECLARE(game_poo);
LV_IMG_DECLARE(game_clean);
LV_IMG_DECLARE(background_2)
LV_IMG_DECLARE(background_4)
LV_IMG_DECLARE(background_6)
LV_IMG_DECLARE(background_8)
LV_IMG_DECLARE(background_10)
LV_IMG_DECLARE(background_12)
LV_IMG_DECLARE(background_14)
LV_IMG_DECLARE(background_16)
LV_IMG_DECLARE(background_18)
LV_IMG_DECLARE(background_20)

static const lv_image_dsc_t* anim_night[ANIMATION_NIGHT] = {
    &background_6, &background_8, &background_10, &background_12, &background_14, &background_16,
};
static const lv_image_dsc_t* anim_day[ANIMATION_DAY] = {
    &background_16, &background_18, &background_20, &background_2, &background_4, &background_6,
};

static void end_game_msg_box_event_handler(lv_event_t* e);
static void drag_clean_event_handler(lv_event_t* e);
static bool check_object_intersect(lv_obj_t* a, lv_obj_t* b);
static void night_animation(void* img, int32_t id) { lv_image_set_src((lv_obj_t*)img, anim_night[id]); }
static void day_animation(void* img, int32_t id) { lv_image_set_src((lv_obj_t*)img, anim_day[id]); }

Game* Game::_instance = nullptr;

Game::Game(poke_config_t* global_config, lv_obj_t* main_screen, Pokemon* p, poke_options_t* game_options) {
  _options = game_options;
  _initialize(global_config, main_screen, p);

  set_lcd_brightness((int32_t)_options->brightness);
}

Game::Game(poke_config_t* global_config, lv_obj_t* main_screen, Pokemon* p) {
  _options = new poke_options_t{OPTIONS_BRIGHTNESS_DEFAULT, OPTIONS_BALL_DEFAULT, NULL};
  _initialize(global_config, main_screen, p);
}

void Game::_initialize(poke_config_t* global_config, lv_obj_t* main_screen, Pokemon* p) {
  _config = global_config;
  _main_screen = main_screen;
  _screen = create_screen(_main_screen);

  lv_obj_t* background_image = lv_image_create(_screen);
  lv_image_set_src(background_image, anim_day[0]);
  lv_obj_set_pos(background_image, 0, 0);

  lv_anim_init(&_anim);
  lv_anim_set_var(&_anim, background_image);
  lv_anim_set_values(&_anim, 0, 5);
  lv_anim_set_path_cb(&_anim, lv_anim_path_linear);
  lv_anim_set_time(&_anim, 600);
  lv_anim_set_repeat_count(&_anim, 0);

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

  _pokemon_image = lv_gif_create(_screen);
  lv_gif_set_src(_pokemon_image, p->get_image());
  lv_obj_align(_pokemon_image, LV_ALIGN_CENTER, 0, 160);

  _pokemon_ball = lv_image_create(_screen);
  serial_printf("Game", "Ball second init %d", _options->ball);
  lv_image_set_src(_pokemon_ball, balls_choice_images[_options->ball]);
  lv_obj_align(_pokemon_ball, LV_ALIGN_CENTER, 0, 90);
  lv_obj_add_flag(_pokemon_ball, LV_OBJ_FLAG_HIDDEN);

  lv_anim_t anim;

  lv_anim_init(&anim);
  lv_anim_set_var(&anim, _pokemon_image);
  lv_anim_set_values(&anim, 160, 80);
  lv_anim_set_path_cb(&anim, lv_anim_path_overshoot);
  lv_anim_set_time(&anim, 1500);
  lv_anim_set_repeat_count(&anim, 0);
  lv_anim_set_exec_cb(&anim, anim_y_callback);

  lv_anim_start(&anim);

  if (p->is_sleeping() == false) {
    switch_to_day();
  } else {
    put_in_pokeball();
  }

  ActionsMenu* actions_menu = new ActionsMenu(new Menu(_main_screen));
  ActionsMenu::setInstance(actions_menu);

  GameMenu* game_menu = new GameMenu(new Menu(_main_screen));
  GameMenu::setInstance(game_menu);
}

void Game::switch_to_day() {
  lv_anim_set_exec_cb(&_anim, day_animation);
  lv_anim_start(&_anim);
  lv_style_set_text_color(&style_game_label, lv_color_black());
  lv_obj_report_style_change(&style_game_label);

  if (lv_obj_is_valid(_pokemon_image) && lv_obj_has_flag(_pokemon_image, LV_OBJ_FLAG_HIDDEN)) {
    lv_obj_remove_flag(_pokemon_image, LV_OBJ_FLAG_HIDDEN);
  }

  lv_obj_add_flag(_pokemon_ball, LV_OBJ_FLAG_HIDDEN);
}

void Game::put_in_pokeball() {
  lv_obj_add_flag(_pokemon_image, LV_OBJ_FLAG_HIDDEN);

  lv_image_set_src(_pokemon_ball, balls_choice_images[_options->ball]);
  lv_obj_remove_flag(_pokemon_ball, LV_OBJ_FLAG_HIDDEN);
}

void Game::switch_to_night() {
  lv_anim_set_exec_cb(&_anim, night_animation);
  lv_anim_start(&_anim);
  lv_style_set_text_color(&style_game_label, lv_color_white());
  lv_obj_report_style_change(&style_game_label);

  put_in_pokeball();
}

void Game::loop() {
  if (game_over) {
    return;
  }

  Pokemon* p = Pokemon::getInstance();
  if (p->is_ko()) {
    serial_printf("Game", "Pokemon is ko!");
    poke_messagebox_t* messagebox = create_message_box(_("pokemon.ko.title"), _("pokemon.ko.message"));
    lv_obj_add_event_cb(messagebox->close_button, end_game_msg_box_event_handler, LV_EVENT_PRESSED, NULL);

    game_over = true;
    return;
  }

  p->loop();

  lv_bar_set_value(_mood_bar, p->get_mood(), LV_ANIM_ON);
  lv_bar_set_value(_life_bar, p->get_life(), LV_ANIM_ON);
  lv_bar_set_value(_sleepiness_bar, p->get_sleepiness(), LV_ANIM_ON);
  lv_bar_set_value(_hunger_bar, p->get_hunger(), LV_ANIM_ON);
  lv_label_set_text_fmt(_level_indic, "%d", p->get_level());

  if (p->get_poos() != _poos.size()) {
    create_poo();
  }

  if (p->get_pees() != _pees.size()) {
    create_pee();
  }
}

void Game::create_poo() {
  lv_obj_t* poo = lv_image_create(_screen);
  lv_image_set_src(poo, &game_poo);
  lv_obj_set_pos(poo, random(1, LV_HOR_RES_MAX - game_poo.header.w), random(LV_VER_RES_MAX / 2, LV_VER_RES_MAX - game_poo.header.h));
  _poos.push_back(poo);
}

void Game::create_pee() {
  lv_obj_t* pee = lv_image_create(_screen);
  lv_image_set_src(pee, &game_pee);
  lv_obj_set_pos(pee, random(1, LV_HOR_RES_MAX - game_pee.header.w), random(LV_VER_RES_MAX / 2, LV_VER_RES_MAX - game_pee.header.h));
  _pees.push_back(pee);
}

void Game::try_to_clean() {
  int8_t i;
  for (i = 0; i < _poos.size(); i++) {
    lv_obj_t* poo = _poos[i];
    if (check_object_intersect(_clean, poo)) {
      lv_obj_delete(poo);
      Pokemon::getInstance()->clean_poo();
      _poos.erase(_poos.begin() + i);
    }
  }

  for (i = 0; i < _pees.size(); i++) {
    lv_obj_t* pee = _pees[i];
    if (check_object_intersect(_clean, pee)) {
      lv_obj_delete(pee);
      Pokemon::getInstance()->clean_pee();
      _pees.erase(_pees.begin() + i);
    }
  }
}

static bool check_object_intersect(lv_obj_t* a, lv_obj_t* b) {
  int32_t x = lv_obj_get_x(a);
  int32_t y = lv_obj_get_y(a);

  int32_t d1x = lv_obj_get_x(b) - (x + lv_obj_get_height(a));
  int32_t d1y = lv_obj_get_y(b) - (y + lv_obj_get_width(a));
  int32_t d2x = x - (lv_obj_get_x(b) + lv_obj_get_width(b));
  int32_t d2y = y - (lv_obj_get_y(b) + lv_obj_get_height(b));

  if (d1x < 0 && d1y < 0 && d2x < 0 && d2y < 0) {
    return true;
  }

  return false;
}

void Game::action_clean() {
  if (lv_obj_is_valid(_clean)) {
    return;
  }

  _clean = lv_image_create(_screen);
  lv_image_set_src(_clean, &game_clean);
  lv_obj_set_pos(_clean, LV_HOR_RES_MAX / 2, LV_VER_RES_MAX / 2);
  lv_obj_add_flag(_clean, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(_clean, LV_OBJ_FLAG_CLICK_FOCUSABLE);
  lv_obj_add_event_cb(_clean, drag_clean_event_handler, LV_EVENT_PRESSING, NULL);
}

void Game::action_train() {
  Pokemon* p = Pokemon::getInstance();
  p->train();
  if (p->try_to_evolve() == true) {
    lv_gif_set_src(_pokemon_image, p->get_image());
  }
}

void Game::action_play() {
  Pokemon* p = Pokemon::getInstance();
  p->play();
}

void Game::action_eat(BagItem* item) {
  Pokemon* p = Pokemon::getInstance();
  p->eat(item);
}

void Game::action_heal() {
  Pokemon* p = Pokemon::getInstance();
  p->heal();
}

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

void Game::abort_actions() {
  if (lv_obj_is_valid(_clean)) {
    lv_obj_delete(_clean);
  }
}

/**
 * Drag event for clean up action
 *
 * @param lv_event_t* e
 */
static void drag_clean_event_handler(lv_event_t* e) {
  lv_obj_t* obj = lv_event_get_target_obj(e);

  lv_indev_t* indev = lv_indev_active();
  if (indev == NULL) return;

  lv_point_t vect;
  lv_indev_get_vect(indev, &vect);

  int32_t x = lv_obj_get_x(obj) + vect.x;
  int32_t y = lv_obj_get_y(obj) + vect.y;

  int32_t obj_width = lv_obj_get_width(obj);
  int32_t obj_height = lv_obj_get_height(obj);

  // Make sure the object could not go outside the screen
  if ((x + obj_width) > LV_HOR_RES_MAX) {
    x = LV_HOR_RES_MAX - obj_width;
  } else if (x < 0) {
    x = 0;
  }

  if ((y + obj_height) > LV_VER_RES_MAX) {
    y = LV_VER_RES_MAX - obj_height;
  } else if (y < 0) {
    y = 0;
  }

  lv_obj_set_pos(obj, x, y);

  Game::getInstance()->try_to_clean();
}

static void end_game_msg_box_event_handler(lv_event_t* e) {
  LV_UNUSED(e);
  serial_printf("Game", "Restart game");
  ESP.restart();
}
