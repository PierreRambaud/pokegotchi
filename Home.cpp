#include <lvgl.h>
#include "assets/background/background_16.c"
#include "assets/pokegotchi_title.c"
#include "Home.h"
#include "Game.h"
#include "Utils.h"

Home* Home::instance = nullptr;

Home::Home() {
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

Home::~Home() {
  lv_obj_del(_screen);
  Serial.println("Home destroyed");
}

void Home::close() {
  lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  _closed = true;
}

static void start_button_event_handler(lv_event_t* e) {
  Serial.println("Home button pressed");

  Home* h = Home::getInstance();
  h->close();

  Game* g = Game::getInstance();
  g->setup();

  Serial.println("Game created");

  delete h;
}

void Home::loop() {
  if (_loaded == true) {
    return;
  }

  if (lv_obj_get_y(_title) >= 50) {
    lv_obj_t* start_button = lv_btn_create(_screen);
    lv_obj_align(start_button, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(start_button, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(start_button, LV_SIZE_CONTENT);
    lv_obj_add_event_cb(start_button, start_button_event_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t* label = lv_label_create(start_button);
    lv_label_set_text(label, "Start");
    lv_obj_center(label);

    _loaded = true;
    Serial.println("Home loaded");
  }
}
