#include "ArduinoJson.h"
#include "lvgl.h"
#include "lv_i18n.h"
#include "Options.h"
#include "Home.h"
#include "StorageConfig.h"
#include "Game.h"
#include "Utils.h"
#include "Pokemon.h"
#include "storage_hal.h"

extern const void* eevee_home_face;
extern const void* pichu_home_face;

using namespace Pokegotchi;

LV_IMG_DECLARE(home_title)
LV_IMG_DECLARE(background_16)

static void close_msg_box_event_handler(lv_event_t* e);
static void load_button_event_handler(lv_event_t* e);
static void load_file_button_event_handler(lv_event_t* e);
static void start_button_event_handler(lv_event_t* e);
static void start_new_game_event_handler(lv_event_t* e);

struct event_load_game_data {
  StorageConfig* storage_config;
  int index;
};

Home* Home::_instance = nullptr;

Home::Home(poke_config_t* global_config, lv_obj_t* main_screen) {
  _config = global_config;
  _storage_config = new StorageConfig(global_config);
  _storage_config->load_save_files();
  _main_screen = main_screen;
  _screen = create_screen(_main_screen);

  lv_obj_t* background_image = lv_image_create(_screen);
  lv_image_set_src(background_image, &background_16);
  lv_obj_set_pos(background_image, 0, 0);

  _title = lv_image_create(_screen);
  lv_image_set_src(_title, &home_title);
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

Home::~Home(void) { lv_obj_delete(_screen); }

void Home::close(void) {
  lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  _closed = true;
}

void Home::load_buttons(void) {
  if (_loaded == true) {
    return;
  }

  if (lv_obj_get_y(_title) >= 50) {
    lv_obj_t* start_button = lv_button_create(_screen);
    lv_obj_align(start_button, LV_ALIGN_CENTER, 0, 25);
    lv_obj_add_event_cb(start_button, start_button_event_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t* label;

    label = lv_label_create(start_button);
    lv_label_set_text(label, _("home.start"));
    lv_obj_center(label);

    if (_storage_config->has_save_files() == true) {
      lv_obj_t* load_button = lv_button_create(_screen);
      lv_obj_align(load_button, LV_ALIGN_CENTER, 0, 60);
      lv_obj_add_event_cb(load_button, load_button_event_handler, LV_EVENT_CLICKED, _storage_config);

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
  poke_messagebox_t* messagebox = create_message_box(_("home.start.choice"), "");
  lv_obj_t* choice_box_content = lv_msgbox_get_content(messagebox->box);
  lv_obj_set_flex_flow(choice_box_content, LV_FLEX_FLOW_ROW_WRAP);

  static int pichu_value = POKEMON_PICHU;
  lv_obj_t* pichu_btn = lv_image_create(choice_box_content);
  lv_image_set_src(pichu_btn, &pichu_home_face);
  lv_obj_add_flag(pichu_btn, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(pichu_btn, start_new_game_event_handler, LV_EVENT_CLICKED, &pichu_value);
  lv_obj_add_event_cb(pichu_btn, close_msg_box_event_handler, LV_EVENT_CLICKED, messagebox->box);

  static int eevee_value = POKEMON_EEVEE;
  lv_obj_t* eevee_btn = lv_image_create(choice_box_content);
  lv_image_set_src(eevee_btn, &eevee_home_face);
  lv_obj_add_flag(eevee_btn, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(eevee_btn, start_new_game_event_handler, LV_EVENT_CLICKED, &eevee_value);
  lv_obj_add_event_cb(eevee_btn, close_msg_box_event_handler, LV_EVENT_CLICKED, messagebox->box);
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

/**
 * Close message box
 *
 * @param lv_event_t* e
 */
static void close_msg_box_event_handler(lv_event_t* e) {
  lv_obj_t* choice_box = (lv_obj_t*)lv_event_get_user_data(e);
  lv_msgbox_close(choice_box);
}

/**
 * Click on load button
 *
 * @param lv_event_t* e
 */
static void load_button_event_handler(lv_event_t* e) {
  poke_messagebox_t* messagebox = create_message_box(_("home.start.choice"), "");
  lv_obj_t* save_list = lv_list_create(messagebox->box);
  lv_obj_set_size(save_list, 220, 120);
  StorageConfig* storage_config = (StorageConfig*)lv_event_get_user_data(e);

  poke_save_file_info* save_files = storage_config->get_save_files();

  for (int i = 0; i < storage_config->get_save_count(); i++) {
    event_load_game_data* event_data = new event_load_game_data;
    event_data->storage_config = storage_config;
    event_data->index = i;

    lv_obj_t* list_btn = lv_list_add_btn(save_list, "X", save_files[i].name);
    lv_obj_add_event_cb(list_btn, load_file_button_event_handler, LV_EVENT_CLICKED, event_data);
    lv_obj_add_event_cb(list_btn, close_msg_box_event_handler, LV_EVENT_CLICKED, messagebox->box);
  }
}

/**
 * Load game if data exists on SD card
 *
 * @param lv_event_t* e
 */
static void load_file_button_event_handler(lv_event_t* e) {
  event_load_game_data* event_data = (event_load_game_data*)lv_event_get_user_data(e);
  poke_save_file_info* save_files = event_data->storage_config->get_save_files();

  hal_start_storage();

  JsonDocument doc;
  DeserializationError error = hal_load_save_file(&doc, save_files[event_data->index].path);

  if (error) {
    create_message_box(_("game.error"), _("game.load.unserialize.error"));
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
  event_data->storage_config->free_list();
  delete event_data;

  Game* g = new Game(global_config, main_screen, p, game_options);
  Game::setInstance(g);
}
