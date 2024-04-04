#include "ArduinoJson.h"
#include "lvgl.h"
#include "lv_i18n.h"
#include "Options.h"
#include "Home.h"
#include "Utils.h"
#include "SD.h"

using namespace Pokegotchi;

LV_IMG_DECLARE(home_title)
LV_IMG_DECLARE(background_16)

static void start_button_event_handler(lv_event_t* e);


Home* Home::_instance = nullptr;

Home::Home(poke_config_t* global_config, lv_obj_t* main_screen) {
  _config = global_config;
  _main_screen = main_screen;
  _screen = create_screen(_main_screen);

  lv_obj_t* background_image = lv_image_create(_screen);
  lv_image_set_src(background_image, &background_16);
  lv_obj_set_pos(background_image, 0, 0);

  _title = lv_image_create(_screen);
  lv_image_set_src(_title, &home_title);
  lv_obj_align(_title, LV_ALIGN_TOP_MID, 0, -50);

  lv_obj_t* start_button = lv_button_create(_screen);
  lv_obj_align(start_button, LV_ALIGN_CENTER, 0, 25);
  lv_obj_add_event_cb(start_button, start_button_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* label;

  label = lv_label_create(start_button);
  lv_label_set_text(label, _("home.start"));
  lv_obj_center(label);
}

Home::~Home(void) { lv_obj_delete(_screen); }

void Home::close(void) {
  lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  _closed = true;
}

void Home::load_buttons(void) {
}

/**
 * Choice a pokemon to start a new game
 *
 * @param lv_event_t* e
 */
static void start_button_event_handler(lv_event_t* e) {
  File entry = SD.open("/.pokegotchi/saves/got.json");
  if (entry && !entry.isDirectory()) {
    Serial.println("Original: File found");
    entry.close();
  } else {
    Serial.println("Original: File found");
  }

  lv_fs_file_t f;
  lv_fs_res_t res;
  res = lv_fs_open(&f, "S:/.pokegotchi/saves/got.json", LV_FS_MODE_RD);
  if(res != LV_FS_RES_OK) {
    Serial.println("Driver: File not found");
    return;
  }
    Serial.println("Driver: File found");


  uint32_t read_num;
  char buf[1024];
  res = lv_fs_read(&f, buf, 512, &read_num);
  if(res != LV_FS_RES_OK) {
    Serial.println("Can't read file");
    return;
  }

  Serial.printf("%s", buf);

  lv_fs_close(&f);
}

