#include <lvgl.h>
#include <ArduinoJson.h>
#include "lv_i18n.h"
#include "Config.h"
#include "Home.h"
#include "Game.h"
#include "Pokemon.h"
#include "Utils.h"

using namespace Pokegotchi;

LV_IMG_DECLARE(pokegotchi_title)
LV_IMG_DECLARE(background_16)

static void close_msg_box_event_handler(lv_event_t* e);
static void load_button_event_handler(lv_event_t* e);
static void start_button_event_handler(lv_event_t* e);
static void start_new_game_event_handler(lv_event_t* e);

Home* Home::instance = nullptr;

Home::Home() {
  if (sd_begin()) {
    if (SD.exists(global_config->save_file_path)) {
      _has_save_file = true;
    }

    SD.end();
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
 * Choice a pokemon to start a new game
 *
 * @param lv_event_t* e
 */
static void start_button_event_handler(lv_event_t* e) {
  lv_obj_t* choice_box = display_alert(_("home.start.choice"), "");

  static int pichu_value = POKEMON_PICHU;
  lv_obj_t* pichu_btn = lv_img_create(choice_box);
  lv_img_set_src(pichu_btn, "L:/home/pichu.bin");
  lv_obj_add_flag(pichu_btn, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(pichu_btn, start_new_game_event_handler, LV_EVENT_CLICKED, &pichu_value);
  lv_obj_add_event_cb(pichu_btn, close_msg_box_event_handler, LV_EVENT_CLICKED, choice_box);
  lv_obj_set_pos(pichu_btn, 25, 25);

  static int eevee_value = POKEMON_EEVEE;
  lv_obj_t* eevee_btn = lv_img_create(choice_box);
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
  Serial.printf("New game start with pokemon number: %d\n", pokemon_number);

  Home* h = Home::getInstance();
  h->close();

  Pokemon* p = new Pokemon(pokemon_number);
  Pokemon::setInstance(p);

  Game* g = Game::getInstance();
  delete h;

  g->setup(p);
}

static void close_msg_box_event_handler(lv_event_t* e) {
  lv_obj_t* choice_box = (lv_obj_t*)lv_event_get_user_data(e);
  lv_msgbox_close(choice_box);
}

/**
 * Load game if data exists on SD card
 *
 * @param lv_event_t* e
 */
static void load_button_event_handler(lv_event_t* e) {
  StaticJsonDocument<900> doc;

  if (sd_begin() == false) {
    display_alert("", _("sd.card.not_found"));
    return;
  }

  File file = SD.open(global_config->save_file_path);
  if (!file) {
    display_alert("", _("game.load.error"));
    return;
  }

  DeserializationError error = deserializeJson(doc, file);
  file.close();
  SD.end();

  if (error) {
    display_alert("", _("game.load.unserialize.error"));
    Serial.println("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }


  JsonObject pokemon_data = doc["pokemon"];
  Pokemon* p = new Pokemon((int)pokemon_data["number"]);
  Pokemon::setInstance(p);
  p->load(pokemon_data);

  Home* h = Home::getInstance();
  h->close();

  Game* g = Game::getInstance();

  JsonObject data = doc["options"];
  Options* options = new Options{data["brightness"]};
  delete h;

  g->setup(p, options);
}
