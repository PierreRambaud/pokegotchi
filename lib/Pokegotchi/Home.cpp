#include <ArduinoJson.h>
#include <lvgl.h>
#include <M5Core2.h>
#include <lv_i18n.h>
#include "Options.h"
#include "Home.h"
#include "SdConfig.h"
#include "Game.h"
#include "Utils.h"
#include "Pokemon.h"

using namespace Pokegotchi;

LV_IMG_DECLARE(home_title)
LV_IMG_DECLARE(background_16)

static void close_msg_box_event_handler(lv_event_t* e);
static void load_button_event_handler(lv_event_t* e);
static void load_file_button_event_handler(lv_event_t* e);
static void start_button_event_handler(lv_event_t* e);
static void start_new_game_event_handler(lv_event_t* e);

struct event_load_game_data {
  SdConfig* sd_config;
  int index;
};

Home* Home::_instance = nullptr;

Home::Home(poke_config_t* global_config, lv_obj_t* main_screen) {
  _config = global_config;
  _sd_config = new SdConfig(global_config);
  _sd_config->load_save_files();
  _main_screen = main_screen;
  _screen = create_screen(_main_screen);

  lv_obj_t* background_image = lv_img_create(_screen);
  lv_img_set_src(background_image, &background_16);
  lv_obj_set_pos(background_image, 0, 0);

  _title = lv_img_create(_screen);
  lv_img_set_src(_title, &home_title);
  lv_obj_align(_title, LV_ALIGN_TOP_MID, 0, -50);

  lv_anim_t anim;

  lv_anim_init(&anim);
  lv_anim_set_var(&anim, _title);
  lv_anim_set_values(&anim, -50, 50);
  lv_anim_set_path_cb(&anim, lv_anim_path_overshoot);
  lv_anim_set_time(&anim, 1500);
  lv_anim_set_repeat_count(&anim, 0);
  lv_anim_set_exec_cb(&anim, anim_y_callback);

  lv_anim_start(&anim);
}

Home::~Home() { lv_obj_del(_screen); }

void Home::close() {
  lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  _closed = true;
}

void Home::load_buttons() {
  if (_loaded == true) {
    return;
  }

  if (lv_obj_get_y(_title) >= 50) {
    lv_obj_t* start_button = lv_btn_create(_screen);
    lv_obj_align(start_button, LV_ALIGN_CENTER, 0, 25);
    lv_obj_add_event_cb(start_button, start_button_event_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t* label;

    label = lv_label_create(start_button);
    lv_label_set_text(label, _("home.start"));
    lv_obj_center(label);

    if (_sd_config->has_save_files() == true) {
      lv_obj_t* load_button = lv_btn_create(_screen);
      lv_obj_align(load_button, LV_ALIGN_CENTER, 0, 60);
      lv_obj_add_event_cb(load_button, load_button_event_handler, LV_EVENT_CLICKED, _sd_config);

      label = lv_label_create(load_button);
      lv_label_set_text(label, _("home.load"));
      lv_obj_center(label);
    }

    _loaded = true;
  }
}

/**
 * Choice a pokemon to start a new game
 *
 * @param lv_event_t* e
 */
static void start_button_event_handler(lv_event_t* e) {
  lv_obj_t* choice_box = display_alert(_("home.start.choice"), "");
  lv_obj_t* choice_box_content = lv_msgbox_get_content(choice_box);

  static int pichu_value = POKEMON_PICHU;
  lv_obj_t* pichu_btn = lv_img_create(choice_box_content);
  lv_img_set_src(pichu_btn, "L:/home/pichu.bin");
  lv_obj_add_flag(pichu_btn, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(pichu_btn, start_new_game_event_handler, LV_EVENT_CLICKED, &pichu_value);
  lv_obj_add_event_cb(pichu_btn, close_msg_box_event_handler, LV_EVENT_CLICKED, choice_box);
  lv_obj_set_pos(pichu_btn, 25, 25);

  static int eevee_value = POKEMON_EEVEE;
  lv_obj_t* eevee_btn = lv_img_create(choice_box_content);
  lv_img_set_src(eevee_btn, "L:/home/eevee.bin");
  lv_obj_add_flag(eevee_btn, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(eevee_btn, start_new_game_event_handler, LV_EVENT_CLICKED, &eevee_value);
  lv_obj_add_event_cb(eevee_btn, close_msg_box_event_handler, LV_EVENT_CLICKED, choice_box);
  lv_obj_set_pos(eevee_btn, 155, 25);
}

/**
 * Start a new game
 *
 * @param lv_event_t* e
 */
static void start_new_game_event_handler(lv_event_t* e) {
  int pokemon_number = *((int*)lv_event_get_user_data(e));
  serial_printf("Home", "New game start with pokemon number: %d", pokemon_number);

  Home* h = Home::getInstance();
  Pokemon* p = new Pokemon(pokemon_number);
  Pokemon::setInstance(p);

  poke_config_t* global_config = h->get_config();
  lv_obj_t* main_screen = h->get_main_screen();
  Home::releaseInstance();

  Game* g = new Game(global_config, main_screen, p);
  Game::setInstance(g);
}

static void close_msg_box_event_handler(lv_event_t* e) {
  lv_obj_t* choice_box = (lv_obj_t*)lv_event_get_user_data(e);
  lv_msgbox_close(choice_box);
}

static void load_button_event_handler(lv_event_t* e) {
  lv_obj_t* choice_box = display_alert(_("home.start.choice"), "");
  lv_obj_t* save_list = lv_list_create(choice_box);
  lv_obj_set_size(save_list, 220, 120);
  SdConfig* sd_config = (SdConfig*)lv_event_get_user_data(e);

  poke_save_file_info* save_files = sd_config->get_save_files();

  for (int i = 0; i < sd_config->get_save_count(); i++) {
    event_load_game_data* event_data = new event_load_game_data;
    event_data->sd_config = sd_config;
    event_data->index = i;

    lv_obj_t* list_btn = lv_list_add_btn(save_list, "X", save_files[i].name);
    lv_obj_add_event_cb(list_btn, load_file_button_event_handler, LV_EVENT_CLICKED, event_data);
    lv_obj_add_event_cb(list_btn, close_msg_box_event_handler, LV_EVENT_CLICKED, choice_box);
  }
}

/**
 * Load game if data exists on SD card
 *
 * @param lv_event_t* e
 */
static void load_file_button_event_handler(lv_event_t* e) {
  JsonDocument doc;
  event_load_game_data* event_data = (event_load_game_data*)lv_event_get_user_data(e);
  poke_save_file_info* save_files = event_data->sd_config->get_save_files();

  sd_begin();
  File file = SD.open(save_files[event_data->index].path);
  if (!file) {
    display_alert(_("game.error"), _("game.load.error"));
    return;
  }

  DeserializationError error = deserializeJson(doc, file);
  file.close();
  SD.end();

  if (error) {
    display_alert(_("game.error"), _("game.load.unserialize.error"));
    serial_printf("Home", "deserializeJson() failed: ");
    serial_printf("Home", "Error: %s", error.c_str());
    return;
  }

  Home* h = Home::getInstance();
  poke_config_t* global_config = h->get_config();
  JsonObject pokemon_data = doc["pokemon"];

  serial_printf("Home", "Load pokemon %d", (int)pokemon_data["number"]);

  Pokemon* p = new Pokemon((int)pokemon_data["number"]);
  Pokemon::setInstance(p);
  p->load(pokemon_data);

  JsonObject data = doc["options"];

  poke_options_t* game_options = new poke_options_t{data["brightness"], data["ball"], strdup(save_files[event_data->index].path)};

  serial_printf("Home", "Brightness value: %d", game_options->brightness);
  serial_printf("Home", "Ball value: %d", game_options->ball);
  serial_printf("Home", "Save file path: %s", game_options->save_file_path);

  lv_obj_t* main_screen = h->get_main_screen();
  Home::releaseInstance();

  // Clear memory
  event_data->sd_config->free_list();
  delete event_data;

  Game* g = new Game(global_config, main_screen, p, game_options);
  Game::setInstance(g);
}
