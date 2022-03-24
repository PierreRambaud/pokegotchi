#include <lvgl.h>
#include <ArduinoJson.h>
#include <lv_i18n.h>
#include <GameSwitcher.h>
#include "Game.h"
#include "GameMenu.h"

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

static void save_game_event_handler(lv_event_t*);
static void open_options_event_handler(lv_event_t*);
static void open_pokemon_event_handler(lv_event_t*);
static void trainercard_event_handler(lv_event_t*);
static void run_game_event_handler(lv_event_t*);
static void slider_set_brightness_event_cb(lv_event_t*);

GameMenu* GameMenu::_instance = nullptr;

GameMenu::GameMenu(Menu* menu) {
  _menu = menu;

  lv_obj_t* save_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_save, &menu_save_pressed, _("menu.save"));
  lv_obj_add_event_cb(save_button, save_game_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* pokemon_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_pokeball, &menu_pokeball_pressed, "Pokémon");
  lv_obj_add_event_cb(pokemon_button, open_pokemon_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* options_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_options, &menu_options_pressed, _("menu.options"));
  lv_obj_add_event_cb(options_button, open_options_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* trainercard_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_trainercard, &menu_trainercard_pressed, _("menu.games"));
  lv_obj_add_event_cb(trainercard_button, trainercard_event_handler, LV_EVENT_CLICKED, NULL);

  Serial.println("Buttons for menu created");

  toggle();
}

void GameMenu::display_pokemon() {
  lv_obj_add_flag(_menu->get_menu_screen(), LV_OBJ_FLAG_HIDDEN);

  _menu_child_screen = create_child_screen(_menu->get_screen());
  Pokemon* p = Pokemon::getInstance();

  lv_style_init(&style_default_title);
  lv_style_set_text_font(&style_default_title, &pokemon_font_12);
  lv_style_set_text_color(&style_default_title, lv_color_white());

  lv_style_init(&style_default_text);
  lv_style_set_text_color(&style_default_text, lv_color_white());

  lv_obj_t* img = lv_img_create(_menu_child_screen);
  lv_img_set_src(img, p->get_avatar());
  lv_obj_set_pos(img, 10, 20);

  lv_obj_t* name = lv_label_create(_menu_child_screen);
  lv_obj_set_pos(name, 155, 20);
  lv_label_set_text(name, p->get_name());
  lv_obj_add_style(name, &style_default_title, 0);

  lv_obj_t* description = lv_label_create(_menu_child_screen);
  lv_obj_set_pos(description, 155, 45);
  lv_obj_set_width(description, 155);
  lv_label_set_text(description, p->get_description());
  lv_obj_add_style(description, &style_default_text, 0);
  lv_obj_set_style_text_font(description, &pokemon_font_10, 0);
}

void GameMenu::display_options() {
  lv_obj_add_flag(_menu->get_menu_screen(), LV_OBJ_FLAG_HIDDEN);

  _menu_child_screen = create_child_screen(_menu->get_screen());

  lv_style_init(&style_default_title);
  lv_style_set_text_font(&style_default_title, &pokemon_font_12);
  lv_style_set_text_color(&style_default_title, lv_color_white());

  lv_style_init(&style_default_text);
  lv_style_set_text_color(&style_default_text, lv_color_white());

  static lv_coord_t options_grid_col_dsc[] = {10, LV_GRID_FR(1), LV_GRID_FR(1), 10, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t options_grid_row_dsc[] = {LV_GRID_CONTENT, /*Title*/
                                              5,               /*Separator*/
                                              LV_GRID_CONTENT, /*Box title*/
                                              30,              /*Boxes*/
                                              5,               /*Separator*/
                                              LV_GRID_CONTENT, /*Box title*/
                                              30,              /*Boxes*/
                                              LV_GRID_TEMPLATE_LAST};

  lv_obj_set_grid_dsc_array(_menu_child_screen, options_grid_col_dsc, options_grid_row_dsc);

  lv_obj_t* options_title = lv_label_create(_menu_child_screen);
  lv_label_set_text(options_title, _("menu.options.title"));
  lv_obj_add_style(options_title, &style_default_title, 0);
  lv_obj_set_grid_cell(options_title, LV_GRID_ALIGN_START, 1, 2, LV_GRID_ALIGN_CENTER, 0, 1);

  lv_obj_t* brightness_slider_label = lv_label_create(_menu_child_screen);
  lv_obj_t* brightness_slider = lv_slider_create(_menu_child_screen);
  lv_obj_set_width(brightness_slider, LV_PCT(95));
  lv_slider_set_value(brightness_slider, Game::getInstance()->get_options()->brightness, LV_ANIM_OFF);
  lv_obj_set_grid_cell(brightness_slider, LV_GRID_ALIGN_CENTER, 1, 2, LV_GRID_ALIGN_CENTER, 3, 1);

  lv_obj_t* brightness_label = lv_label_create(_menu_child_screen);
  lv_label_set_text(brightness_label, _("menu.options.brightness"));
  lv_obj_set_grid_cell(brightness_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 2, 1);
  lv_obj_add_style(brightness_label, &style_default_text, 0);

  char buf[8];
  lv_snprintf(buf, sizeof(buf), "%d%%", Game::getInstance()->get_options()->brightness);
  lv_label_set_text(brightness_slider_label, buf);
  lv_obj_add_style(brightness_slider_label, &style_default_text, 0);
  lv_obj_align_to(brightness_slider_label, brightness_slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
  lv_obj_set_grid_cell(brightness_slider_label, LV_GRID_ALIGN_CENTER, 1, 2, LV_GRID_ALIGN_CENTER, 4, 1);
  lv_obj_add_event_cb(brightness_slider, slider_set_brightness_event_cb, LV_EVENT_VALUE_CHANGED, brightness_slider_label);
}

void GameMenu::display_games() {
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
}

static void slider_set_brightness_event_cb(lv_event_t* e) {
  lv_obj_t* slider = lv_event_get_target(e);
  char buf[8];
  lv_snprintf(buf, sizeof(buf), "%d%%", (int32_t)lv_slider_get_value(slider));

  lv_obj_t* brightness_slider_label = (lv_obj_t*)lv_event_get_user_data(e);
  lv_label_set_text(brightness_slider_label, buf);
  lv_obj_report_style_change(&style_game_label);

  set_lcd_brightness((int32_t)lv_slider_get_value(slider));

  Game::getInstance()->get_options()->brightness = (int32_t)lv_slider_get_value(slider);
}

/**
 * Save game information
 *
 * @param lv_event_t* e
 */
static void save_game_event_handler(lv_event_t* e) {
  Pokemon* p = Pokemon::getInstance();

  StaticJsonDocument<900> doc;
  doc["options"]["brightness"] = Game::getInstance()->get_options()->brightness;

  JsonObject pokemon = doc.createNestedObject("pokemon");
  pokemon["number"] = p->get_number();
  pokemon["level"] = p->get_level();
  pokemon["life"] = p->get_life();
  pokemon["mood"] = p->get_mood();
  pokemon["hunger"] = p->get_hunger();
  pokemon["sleepiness"] = p->get_sleepiness();
  pokemon["is_sleeping"] = p->is_sleeping();
  pokemon["poos"] = p->get_poos();
  pokemon["pees"] = p->get_pees();

  unsigned long current_time = millis();
  JsonObject pokemon_time = pokemon.createNestedObject("time");
  pokemon_time["simple_check"] = p->get_last_simple_check_time() - current_time;
  pokemon_time["boredom"] = p->get_last_boredom_time() - current_time;
  pokemon_time["hunger"] = p->get_last_hunger_time() - current_time;
  pokemon_time["sleep"] = p->get_last_sleep_time() - current_time;
  pokemon_time["without_sleep"] = p->get_last_without_sleep_time() - current_time;

  if (sd_begin() == false) {
    display_alert("", _("sd.card.not_found"));
    return;
  }

  File file = SD.open(Game::getInstance()->get_config()->save_file_path, FILE_WRITE);
  if (!file) {
    display_alert("", _("game.save.failed"));
  } else {
    serializeJson(doc, Serial);
    serializeJson(doc, file);
    file.close();

    display_alert("", _("game.save.success"));
  }

  SD.end();
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
  Serial.printf("%d\n", game_number);

  GameSwitcher::Runner::getInstance()->switch_game(game_number);
}
