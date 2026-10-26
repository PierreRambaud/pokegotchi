#include "lvgl.h"
#include "ArduinoJson.h"
#include "lv_i18n.h"
#include "GameSwitcher.h"
#include "StorageConfig.h"
#include "Game.h"
#include "GameMenu.h"
#include "storage_hal.h"

using namespace Pokegotchi;

LV_IMG_DECLARE(menu_save)
LV_IMG_DECLARE(menu_save_pressed)
LV_IMG_DECLARE(menu_pokeball)
LV_IMG_DECLARE(menu_pokeball_pressed)
LV_IMG_DECLARE(menu_options)
LV_IMG_DECLARE(menu_options_pressed)
LV_IMG_DECLARE(menu_trainercard)
LV_IMG_DECLARE(menu_trainercard_pressed)

LV_IMG_DECLARE(menu_game_draw)
LV_IMG_DECLARE(menu_game_draw_pressed)
LV_IMG_DECLARE(menu_game_bird)
LV_IMG_DECLARE(menu_game_bird_pressed)
LV_IMG_DECLARE(menu_game_sky)
LV_IMG_DECLARE(menu_game_sky_pressed)
LV_IMG_DECLARE(game_egg)

static void save_game(char*);
static void cancel_new_save_event_handler(lv_event_t*);
static void choice_ball_event_cb(lv_event_t*);
static void choice_save_game_event_handler(lv_event_t*);
static void click_button_save_game_event_handler(lv_event_t*);
static void create_new_save_event_handler(lv_event_t*);
static void delete_save_box_event_handler(lv_event_t*);
static void game_new_save_event_handler(lv_event_t*);
static void open_options_event_handler(lv_event_t*);
static void open_pokemon_event_handler(lv_event_t*);
static void replace_save_box_event_handler(lv_event_t*);
static void run_game_event_handler(lv_event_t*);
static void save_game_event_handler(lv_event_t*);
static void slider_set_brightness_event_cb(lv_event_t*);
static void trainercard_event_handler(lv_event_t*);
static void set_clock_event_handler(lv_event_t*);
static void choice_speed_event_cb(lv_event_t*);
static void sound_switch_event_cb(lv_event_t*);

struct event_choice_game_data {
  lv_obj_t* selected_row;
  char* file_name;
  lv_obj_t* box;
};

GameMenu* GameMenu::_instance = nullptr;

GameMenu::GameMenu(Menu* menu) {
  _menu = menu;

  lv_obj_t* save_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_save, &menu_save_pressed, _("menu.save"));
  lv_obj_add_event_cb(save_button, click_button_save_game_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* pokemon_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_pokeball, &menu_pokeball_pressed, "Pokémon");
  lv_obj_add_event_cb(pokemon_button, open_pokemon_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* options_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_options, &menu_options_pressed, _("menu.options"));
  lv_obj_add_event_cb(options_button, open_options_event_handler, LV_EVENT_CLICKED, NULL);

#ifdef POKEGOTCHI_INCLUDE_GAMES
  lv_obj_t* trainercard_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_trainercard, &menu_trainercard_pressed, _("menu.games"));
  lv_obj_add_event_cb(trainercard_button, trainercard_event_handler, LV_EVENT_CLICKED, NULL);
#endif

  serial_printf("GameMenu", "Buttons for menu created");

  toggle();
}

void GameMenu::display_pokemon(void) {
  lv_obj_add_flag(_menu->get_menu_screen(), LV_OBJ_FLAG_HIDDEN);

  _menu_child_screen = create_child_screen(_menu->get_screen());
  Pokemon* p = Pokemon::getInstance();

  lv_style_init(&style_default_title);
  lv_style_set_text_font(&style_default_title, &pokemon_font_12);
  lv_style_set_text_color(&style_default_title, lv_color_white());

  lv_style_init(&style_default_text);
  lv_style_set_text_color(&style_default_text, lv_color_white());

  lv_obj_t* img = lv_image_create(_menu_child_screen);
  if (p->is_egg()) {
    lv_image_set_src(img, &game_egg);
    lv_obj_set_pos(img, 40, 40);
  } else {
    lv_image_set_src(img, p->get_avatar());
    lv_obj_set_pos(img, 10, 20);
  }

  lv_obj_t* name = lv_label_create(_menu_child_screen);
  lv_obj_set_pos(name, 155, 20);
  lv_label_set_text(name, p->is_egg() ? _("pokemon.egg.name") : p->get_name());
  lv_obj_add_style(name, &style_default_title, 0);

  lv_obj_t* description = lv_label_create(_menu_child_screen);
  lv_obj_set_pos(description, 155, 45);
  lv_obj_set_width(description, 155);
  lv_label_set_text(description, p->get_description());
  lv_obj_add_style(description, &style_default_text, 0);
  lv_obj_set_style_text_font(description, &pokemon_font_10, 0);

  if (p->is_egg()) {
    return;
  }

  // How the Pokemon feels about its trainer, worded like in the games
  uint8_t friendship = p->get_friendship();
  const char* feeling = _("pokemon.friendship.1");
  if (friendship >= 220) {
    feeling = _("pokemon.friendship.5");
  } else if (friendship >= FRIENDSHIP_EVOLUTION) {
    feeling = _("pokemon.friendship.4");
  } else if (friendship >= 100) {
    feeling = _("pokemon.friendship.3");
  } else if (friendship >= 50) {
    feeling = _("pokemon.friendship.2");
  }

  lv_obj_t* stats = lv_label_create(_menu_child_screen);
  lv_obj_set_pos(stats, 10, 142);
  lv_obj_set_width(stats, LV_HOR_RES_MAX - 20);
  lv_obj_add_style(stats, &style_default_text, 0);
  lv_obj_set_style_text_font(stats, &pokemon_font_10, 0);
  lv_label_set_text_fmt(stats, _("pokemon.stats"), p->get_level(), p->get_xp(), p->get_xp_to_next_level(), (unsigned long)p->get_age_days(), feeling, p->get_care_mistakes(),
                        p->is_sick() ? _("pokemon.status.sick") : _("pokemon.status.healthy"), (unsigned long)p->get_steps_today(hal_now()), (unsigned long)p->get_total_steps());
}

void GameMenu::display_options(void) {
  lv_obj_add_flag(_menu->get_menu_screen(), LV_OBJ_FLAG_HIDDEN);

  _menu_child_screen = create_child_screen(_menu->get_screen());

  lv_style_init(&style_default_title);
  lv_style_set_text_font(&style_default_title, &pokemon_font_12);
  lv_style_set_text_color(&style_default_title, lv_color_white());

  lv_style_init(&style_default_text);
  lv_style_set_text_color(&style_default_text, lv_color_white());

  static int32_t options_grid_col_dsc[] = {10, LV_GRID_FR(1), LV_GRID_FR(1), 30, LV_GRID_TEMPLATE_LAST};
  static int32_t options_grid_row_dsc[] = {30, 20, 30, 20, 20, 30, 40, 24, 36, 24, 44, LV_GRID_TEMPLATE_LAST};

  lv_obj_set_grid_dsc_array(_menu_child_screen, options_grid_col_dsc, options_grid_row_dsc);

  lv_obj_t* options_title = lv_label_create(_menu_child_screen);
  lv_label_set_text(options_title, _("menu.options.title"));
  lv_obj_add_style(options_title, &style_default_title, 0);
  lv_obj_set_grid_cell(options_title, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);

  lv_obj_t* brightness_label = lv_label_create(_menu_child_screen);
  lv_label_set_text(brightness_label, _("menu.options.brightness"));
  lv_obj_set_grid_cell(brightness_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 1, 1);
  lv_obj_add_style(brightness_label, &style_default_text, 0);

  lv_obj_t* brightness_slider_label = lv_label_create(_menu_child_screen);
  lv_obj_t* brightness_slider = lv_slider_create(_menu_child_screen);
  lv_obj_set_width(brightness_slider, LV_PCT(90));
  lv_slider_set_value(brightness_slider, Game::getInstance()->get_options()->brightness, LV_ANIM_OFF);
  lv_obj_set_grid_cell(brightness_slider, LV_GRID_ALIGN_CENTER, 1, 2, LV_GRID_ALIGN_CENTER, 2, 1);

  char buf[8];
  lv_snprintf(buf, sizeof(buf), "%d%%", Game::getInstance()->get_options()->brightness);
  lv_label_set_text(brightness_slider_label, buf);
  lv_obj_add_style(brightness_slider_label, &style_default_text, 0);
  lv_obj_align_to(brightness_slider_label, brightness_slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
  lv_obj_set_grid_cell(brightness_slider_label, LV_GRID_ALIGN_CENTER, 1, 2, LV_GRID_ALIGN_CENTER, 3, 1);
  lv_obj_add_event_cb(brightness_slider, slider_set_brightness_event_cb, LV_EVENT_VALUE_CHANGED, brightness_slider_label);

  lv_obj_t* ball_label = lv_label_create(_menu_child_screen);
  lv_label_set_text(ball_label, _("menu.options.ball"));
  lv_obj_set_grid_cell(ball_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, LV_BUTTONMATRIX_CTRL_CHECKABLE, 1);
  lv_obj_add_style(ball_label, &style_default_text, 0);

  lv_obj_t* ball_choice_dropdown = lv_dropdown_create(_menu_child_screen);
  lv_dropdown_clear_options(ball_choice_dropdown);

  const char* balls_choice[9] = {_("ball.poke"), _("ball.super"), _("ball.hyper"), _("ball.master"), _("ball.love"), _("ball.fast"), _("ball.memory"), _("ball.moon"), _("ball.dream")};

  for (int8_t i = 0; i <= 7; i++) {
    lv_dropdown_add_option(ball_choice_dropdown, balls_choice[i], i);
  }

  lv_dropdown_set_symbol(ball_choice_dropdown, LV_SYMBOL_RIGHT);
  lv_dropdown_set_selected(ball_choice_dropdown, Game::getInstance()->get_options()->ball);
  lv_obj_set_grid_cell(ball_choice_dropdown, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 5, 1);
  lv_obj_add_event_cb(ball_choice_dropdown, choice_ball_event_cb, LV_EVENT_ALL, NULL);

  _ball_image = lv_image_create(_menu_child_screen);
  lv_image_set_src(_ball_image, balls_choice_images[Game::getInstance()->get_options()->ball]);
  lv_obj_set_grid_cell(_ball_image, LV_GRID_ALIGN_START, 2, 1, LV_GRID_ALIGN_START, 5, 1);

  // Sound effects on or off
  lv_obj_t* sound_label = lv_label_create(_menu_child_screen);
  lv_label_set_text(sound_label, _("menu.options.sound"));
  lv_obj_set_grid_cell(sound_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_CENTER, 6, 1);
  lv_obj_add_style(sound_label, &style_default_text, 0);

  lv_obj_t* sound_switch = lv_switch_create(_menu_child_screen);
  if (Game::getInstance()->get_options()->sound) {
    lv_obj_add_state(sound_switch, LV_STATE_CHECKED);
  }
  lv_obj_set_grid_cell(sound_switch, LV_GRID_ALIGN_START, 2, 1, LV_GRID_ALIGN_CENTER, 6, 1);
  lv_obj_add_event_cb(sound_switch, sound_switch_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

  // Speed of the days of the Pokemon
  Pokemon* p = Pokemon::getInstance();
  lv_obj_t* speed_label = lv_label_create(_menu_child_screen);
  lv_label_set_text(speed_label, _("menu.options.speed"));
  lv_obj_set_grid_cell(speed_label, LV_GRID_ALIGN_START, 1, 2, LV_GRID_ALIGN_END, 7, 1);
  lv_obj_add_style(speed_label, &style_default_text, 0);

  lv_obj_t* speed_dropdown = lv_dropdown_create(_menu_child_screen);
  lv_dropdown_clear_options(speed_dropdown);
  for (uint8_t i = 0; i < SPEED_COUNT; i++) {
    lv_dropdown_add_option(speed_dropdown, Pokemon::get_speed_name(SPEEDS_MENU[i]), i);
    if (SPEEDS_MENU[i] == p->get_speed()) {
      lv_dropdown_set_selected(speed_dropdown, i);
    }
  }
  lv_obj_set_width(speed_dropdown, LV_PCT(100));
  lv_obj_set_grid_cell(speed_dropdown, LV_GRID_ALIGN_STRETCH, 1, 2, LV_GRID_ALIGN_CENTER, 8, 1);
  lv_obj_add_event_cb(speed_dropdown, choice_speed_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

  // Clock: the day and night of the Pokemon follow it
  lv_obj_t* clock_label = lv_label_create(_menu_child_screen);
  lv_label_set_text(clock_label, _("menu.options.clock"));
  lv_obj_set_grid_cell(clock_label, LV_GRID_ALIGN_START, 1, 2, LV_GRID_ALIGN_END, 9, 1);
  lv_obj_add_style(clock_label, &style_default_text, 0);

  lv_obj_t* clock_row = lv_obj_create(_menu_child_screen);
  lv_obj_remove_style_all(clock_row);
  lv_obj_set_size(clock_row, LV_PCT(100), 44);
  lv_obj_set_flex_flow(clock_row, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(clock_row, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_set_style_pad_column(clock_row, 6, 0);
  lv_obj_set_grid_cell(clock_row, LV_GRID_ALIGN_STRETCH, 1, 2, LV_GRID_ALIGN_CENTER, 10, 1);

  static char hours[24 * 3];
  static char minutes[60 * 3];
  if (hours[0] == '\0') {
    for (uint8_t i = 0; i < 24; i++) {
      lv_snprintf(hours + i * 3, 4, i < 23 ? "%02d\n" : "%02d", i);
    }
    for (uint8_t i = 0; i < 60; i++) {
      lv_snprintf(minutes + i * 3, 4, i < 59 ? "%02d\n" : "%02d", i);
    }
  }

  // The clock shown in the game: the real one only at the real speed
  uint32_t now = p->get_game_time();
  _hour_roller = lv_roller_create(clock_row);
  lv_roller_set_options(_hour_roller, hours, LV_ROLLER_MODE_INFINITE);
  lv_roller_set_visible_row_count(_hour_roller, 1);
  lv_roller_set_selected(_hour_roller, (now % 86400) / 3600, LV_ANIM_OFF);

  lv_obj_t* separator = lv_label_create(clock_row);
  lv_label_set_text(separator, ":");
  lv_obj_add_style(separator, &style_default_text, 0);

  _minute_roller = lv_roller_create(clock_row);
  lv_roller_set_options(_minute_roller, minutes, LV_ROLLER_MODE_INFINITE);
  lv_roller_set_visible_row_count(_minute_roller, 1);
  lv_roller_set_selected(_minute_roller, (now % 3600) / 60, LV_ANIM_OFF);

  lv_obj_t* set_button = lv_button_create(clock_row);
  lv_obj_add_event_cb(set_button, set_clock_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_t* set_label = lv_label_create(set_button);
  lv_label_set_text(set_label, _("menu.options.clock.set"));
}

void GameMenu::set_clock(void) {
  Pokemon* p = Pokemon::getInstance();
  uint8_t hour = lv_roller_get_selected(_hour_roller);
  uint8_t minute = lv_roller_get_selected(_minute_roller);

  if (p->get_speed() == SPEED_REAL) {
    // The real clock of the device
    uint32_t now = hal_now();
    hal_set_now(now - now % 86400 + hour * 3600UL + minute * 60UL);
  } else {
    // Only the clock of the Pokemon: handy to skip to the morning
    p->set_time_of_day(hour, minute);
  }

  serial_printf("GameMenu", "Clock set to %02d:%02d", hour, minute);
  create_message_box("", _("menu.options.clock.done"));
}

void GameMenu::display_games(void) {
  lv_obj_add_flag(_menu->get_menu_screen(), LV_OBJ_FLAG_HIDDEN);

  _menu_child_screen = create_child_screen(_menu->get_screen());
  static lv_style_t flex_style;
  lv_style_set_flex_flow(&flex_style, LV_FLEX_FLOW_ROW_WRAP);
  lv_style_set_flex_main_place(&flex_style, LV_FLEX_ALIGN_SPACE_AROUND);
  lv_style_set_layout(&flex_style, LV_LAYOUT_FLEX);

  lv_obj_add_style(_menu_child_screen, &flex_style, 0);

  static int8_t game_drawingboard = GAME_DRAWING_BOARD;
  lv_obj_t* draw_button = lv_menu_button_create(_menu_child_screen, &menu_game_draw, &menu_game_draw_pressed, _("menu.game.draw"));
  lv_obj_add_event_cb(draw_button, run_game_event_handler, LV_EVENT_CLICKED, &game_drawingboard);

  static int8_t game_floppybird = GAME_FLOPPYBIRD;
  lv_obj_t* bird_button = lv_menu_button_create(_menu_child_screen, &menu_game_bird, &menu_game_bird_pressed, _("menu.game.bird"));
  lv_obj_add_event_cb(bird_button, run_game_event_handler, LV_EVENT_CLICKED, &game_floppybird);

  static int8_t game_skyrace = GAME_SKYRACE;
  lv_obj_t* sky_button = lv_menu_button_create(_menu_child_screen, &menu_game_sky, &menu_game_sky_pressed, _("menu.game.sky"));
  lv_obj_add_event_cb(sky_button, run_game_event_handler, LV_EVENT_CLICKED, &game_skyrace);
}

void GameMenu::display_saves(void) {
  lv_obj_add_flag(_menu->get_menu_screen(), LV_OBJ_FLAG_HIDDEN);

  _menu_child_screen = create_child_screen(_menu->get_screen());

  lv_obj_set_style_bg_opa(_menu_child_screen, LV_STATE_DEFAULT, LV_OPA_TRANSP);
  lv_obj_t* save_list = lv_list_create(_menu_child_screen);
  lv_obj_set_pos(save_list, 10, 10);
  lv_obj_set_size(save_list, LV_HOR_RES_MAX - 20, LV_VER_RES_MAX - 125);

  StorageConfig* storage_config = new StorageConfig(Game::getInstance()->get_config());
  storage_config->load_save_files();

  poke_save_file_info* save_files = storage_config->get_save_files();

  for (int i = 0; i < storage_config->get_save_count(); i++) {
    lv_obj_t* list_btn = lv_list_add_btn(save_list, NULL, save_files[i].name);
    lv_obj_add_event_cb(list_btn, choice_save_game_event_handler, LV_EVENT_CLICKED, save_files[i].name);
  }

  lv_obj_t* new_save_button = lv_button_create(_menu_child_screen);
  lv_obj_align(new_save_button, LV_ALIGN_BOTTOM_LEFT, 10, -10);
  lv_obj_add_event_cb(new_save_button, game_new_save_event_handler, LV_EVENT_CLICKED, _menu_child_screen);

  lv_obj_t* label = lv_label_create(new_save_button);
  lv_label_set_text(label, _("game.save.create.button"));
  lv_obj_center(label);

  lv_obj_t* existing_game_save_button = lv_button_create(_menu_child_screen);
  lv_obj_align(existing_game_save_button, LV_ALIGN_BOTTOM_RIGHT, -10, -10);
  lv_obj_add_event_cb(existing_game_save_button, save_game_event_handler, LV_EVENT_CLICKED, NULL);

  label = lv_label_create(existing_game_save_button);
  lv_label_set_text(label, _("game.save.replace.button"));
  lv_obj_center(label);
}

void GameMenu::change_ball(uint16_t index) {
  lv_image_set_src(_ball_image, balls_choice_images[index]);
  Game::getInstance()->get_options()->ball = index;
}

static void choice_save_game_event_handler(lv_event_t* e) {
  poke_messagebox_t* messagebox = create_message_box(_("game.save.box.choose"), "");

  lv_obj_t* replace_button = lv_msgbox_add_footer_button(messagebox->box, _("game.save.box.replace"));
  lv_obj_t* delete_button = lv_msgbox_add_footer_button(messagebox->box, _("game.save.box.delete"));

  event_choice_game_data* event_data = new event_choice_game_data;
  event_data->selected_row = lv_event_get_current_target_obj(e);
  event_data->file_name = (char*)lv_event_get_user_data(e);
  event_data->box = messagebox->box;

  lv_obj_add_event_cb(replace_button, replace_save_box_event_handler, LV_EVENT_CLICKED, event_data);
  lv_obj_add_event_cb(delete_button, delete_save_box_event_handler, LV_EVENT_CLICKED, event_data);
}

static void delete_save_box_event_handler(lv_event_t* e) {
  event_choice_game_data* event_data = (event_choice_game_data*)lv_event_get_user_data(e);

  char json_path[50];
  strcpy(json_path, Game::getInstance()->get_config()->save_files_path);
  strcat(json_path, "/");
  strcat(json_path, event_data->file_name);
  strcat(json_path, ".json");

  hal_remove_file(json_path);

  serial_printf("GameMenu", "Delete file \"%s\"", json_path);
  lv_obj_delete(event_data->selected_row);

  lv_msgbox_close(event_data->box);
}

static void replace_save_box_event_handler(lv_event_t* e) {
  event_choice_game_data* event_data = (event_choice_game_data*)lv_event_get_user_data(e);

  save_game(event_data->file_name);

  lv_msgbox_close(event_data->box);
}

static void game_new_save_event_handler(lv_event_t* e) {
  lv_obj_t* screen = (lv_obj_t*)lv_event_get_user_data(e);
  lv_obj_clean(screen);

  lv_obj_t* keyboard_textarea = lv_textarea_create(screen);
  lv_textarea_set_one_line(keyboard_textarea, true);
  lv_obj_align(keyboard_textarea, LV_ALIGN_TOP_MID, 0, 10);
  lv_obj_add_state(keyboard_textarea, LV_STATE_FOCUSED);
  lv_obj_align(keyboard_textarea, LV_ALIGN_TOP_MID, 0, 0);

  lv_obj_t* keyboard = lv_keyboard_create(screen);
  lv_obj_add_event_cb(keyboard, create_new_save_event_handler, LV_EVENT_READY, keyboard_textarea);
  lv_obj_add_event_cb(keyboard, cancel_new_save_event_handler, LV_EVENT_CANCEL, NULL);

  static const char* kb_map[] = {"a", "z", "e",  "r", "t", "y", "u", "i", "o", "p",  LV_SYMBOL_BACKSPACE, "\n",         "q", "s", "d", "f", "g", "j", "k",
                                 "l", "m", "\n", "w", "x", "c", "v", "b", "n", "\n", LV_SYMBOL_CLOSE,     LV_SYMBOL_OK, NULL};

  /*Set the relative width of the buttons and other controls*/
  static const lv_buttonmatrix_ctrl_t kb_ctrl[] = {
      LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE,
      LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_HIDDEN,    LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE,
      LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE,
      LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_HIDDEN,    LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE,
      LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE,
      LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_NO_REPEAT, LV_BUTTONMATRIX_CTRL_HIDDEN,    LV_BUTTONMATRIX_CTRL_NO_REPEAT};

  lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_USER_1, kb_map, kb_ctrl);
  lv_keyboard_set_mode(keyboard, LV_KEYBOARD_MODE_USER_1);
  lv_keyboard_set_textarea(keyboard, keyboard_textarea);
}

static void cancel_new_save_event_handler(lv_event_t* e) { GameMenu::getInstance()->toggle(); }

static void create_new_save_event_handler(lv_event_t* e) {
  lv_obj_t* textarea = (lv_obj_t*)lv_event_get_user_data(e);
  const char* text_content = lv_textarea_get_text(textarea);
  if (text_content[0] == '\0') {
    create_message_box(_("game.error"), _("game.save.file.invalid"));
    return;
  }

  save_game((char*)text_content);
}

static void slider_set_brightness_event_cb(lv_event_t* e) {
  lv_obj_t* slider = lv_event_get_target_obj(e);
  char buf[8];
  lv_snprintf(buf, sizeof(buf), "%d%%", (uint32_t)lv_slider_get_value(slider));

  lv_obj_t* brightness_slider_label = (lv_obj_t*)lv_event_get_user_data(e);
  lv_label_set_text(brightness_slider_label, buf);
  lv_obj_report_style_change(&style_game_label);

  set_lcd_brightness((uint32_t)lv_slider_get_value(slider));

  Game::getInstance()->get_options()->brightness = (uint32_t)lv_slider_get_value(slider);
}

static void choice_ball_event_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t* obj = lv_event_get_target_obj(e);
  if (code == LV_EVENT_VALUE_CHANGED) {
    GameMenu::getInstance()->change_ball(lv_dropdown_get_selected(obj));
  }
}

static void click_button_save_game_event_handler(lv_event_t* e) { GameMenu::getInstance()->display_saves(); }

/**
 * Save game information
 *
 * @param lv_event_t* e
 */
static void save_game_event_handler(lv_event_t* e) { save_game(NULL); }

/**
 * Save game information
 *
 * @param char* save_file_name
 */
static void save_game(char* save_file_name) {
  Game* g = Game::getInstance();
  poke_options_t* options = g->get_options();

  char json_path[64];
  const char* path = options->save_file_path;
  if (save_file_name != NULL || path == NULL) {
    lv_snprintf(json_path, sizeof(json_path), "%s/%s.json", g->get_config()->save_files_path, save_file_name);
    path = json_path;
  }

  serial_printf("GameMenu", "Save file \"%s\"", path);
  if (!g->save(path)) {
    create_message_box(_("game.error"), _("game.save.failed"));
    return;
  }

  // Next saves, and the autosave, go to this file
  if (path == json_path) {
    options->save_file_path = strdup(json_path);
  }

  create_message_box("", _("game.save.success"));
  GameMenu::getInstance()->toggle();
}

/**
 * Open options screen
 *
 * @param lv_event_t* e
 */
static void open_options_event_handler(lv_event_t* e) { GameMenu::getInstance()->display_options(); }

/**
 * Open pokemon screen
 *
 * @param lv_event_t* e
 */
static void open_pokemon_event_handler(lv_event_t* e) { GameMenu::getInstance()->display_pokemon(); }

/**
 * Display trainer card
 *
 * @param lv_event_t* e
 */
static void trainercard_event_handler(lv_event_t* e) { GameMenu::getInstance()->display_games(); }

/**
 * Switch game
 *
 * @param lv_event_t* e
 */
static void run_game_event_handler(lv_event_t* e) {
  int8_t game_number = *((int8_t*)lv_event_get_user_data(e));

  // The pet keeps living in memory, but save in case the game never returns
  Game::getInstance()->autosave();
  GameSwitcher::Runner::getInstance()->request_switch(game_number);
}

static void sound_switch_event_cb(lv_event_t* e) {
  bool enabled = lv_obj_has_state(lv_event_get_target_obj(e), LV_STATE_CHECKED);
  Game::getInstance()->get_options()->sound = enabled;
  hal_set_sound(enabled);
  // A little beep to hear it is back
  hal_beep(2000, 50);
}

static void choice_speed_event_cb(lv_event_t* e) {
  lv_obj_t* dropdown = lv_event_get_target_obj(e);
  Pokemon::getInstance()->set_speed(SPEEDS_MENU[lv_dropdown_get_selected(dropdown)]);
}

static void set_clock_event_handler(lv_event_t* e) {
  LV_UNUSED(e);
  GameMenu::getInstance()->set_clock();
}
