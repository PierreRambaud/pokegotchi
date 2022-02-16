#include <lvgl.h>
#include <ArduinoJson.h>
#include "lv_i18n.h"
#include "Config.h"
#include "Home.h"
#include "Game.h"
#include "Utils.h"

LV_IMG_DECLARE(background_16)
LV_IMG_DECLARE(pokegotchi_title)

static void load_button_event_handler(lv_event_t* e);
static void start_button_event_handler(lv_event_t* e);

Home* Home::instance = nullptr;

Home::Home() {
  if (Config::getInstance()->is_sd_card_available) {
    if (SD.exists(Config::getInstance()->save_file_path)) {
      _has_save_file = true;
    }
  }

  _screen = create_window();
  lv_scr_load(_screen);

  lv_obj_t* background_image = lv_img_create(_screen);
  lv_img_set_src(background_image, &background_16);
  lv_obj_set_pos(background_image, 0, 0);

  _title = lv_img_create(_screen);
  lv_img_set_src(_title, &pokegotchi_title);
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

void Home::loop() {
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

    if (_has_save_file == true) {
      lv_obj_t* load_button = lv_btn_create(_screen);
      lv_obj_align(load_button, LV_ALIGN_CENTER, 0, 60);
      lv_obj_add_event_cb(load_button, load_button_event_handler, LV_EVENT_CLICKED, NULL);

      label = lv_label_create(load_button);
      lv_label_set_text(label, _("home.load"));
      lv_obj_center(label);
    }

    _loaded = true;
  }
}

/**
 * Start a new game
 *
 * @param lv_event_t* e
 */
static void start_button_event_handler(lv_event_t* e) {
  Home* h = Home::getInstance();
  h->close();

  Game* g = Game::getInstance();
  g->setup();

  delete h;
}

/**
 * Load game if data exists on SD card
 *
 * @param lv_event_t* e
 */
static void load_button_event_handler(lv_event_t* e) {
  StaticJsonDocument<384> doc;

  File file = SD.open(Config::getInstance()->save_file_path);
  if (!file) {
    Serial.println("Cannot load save file, probably not exists");
    return;
  }

  DeserializationError error = deserializeJson(doc, file);
  file.close();

  if (error) {
    Serial.println("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }

  int options_brightness = doc["options"]["brightness"];

  JsonObject pokemon = doc["pokemon"];
  int pokemon_type = pokemon["type"];
  int pokemon_level = pokemon["level"];
  int pokemon_life = pokemon["life"];
  int pokemon_mood = pokemon["mood"];
  int pokemon_hunger = pokemon["hunger"];
  int pokemon_sleepiness = pokemon["sleepiness"];

  JsonObject pokemon_time = pokemon["time"];
  long unsigned pokemon_time_boredom = pokemon_time["boredom"];
  long unsigned pokemon_time_hunger = pokemon_time["hunger"];
  long unsigned pokemon_time_sleep = pokemon_time["sleep"];
  long unsigned pokemon_time_without_sleep = pokemon_time["without_sleep"];

  start_button_event_handler(e);
}
