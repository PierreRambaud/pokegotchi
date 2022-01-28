#ifndef POKEGOTCHI_UTILS
#define POKEGOTCHI_UTILS

#include "includes/lodepng.h"
#include <ArduinoJson.h>
#include <M5Core2.h>
#include <lvgl.h>

inline lv_obj_t* create_window() {
  lv_obj_t* obj = lv_obj_create(NULL);
  lv_obj_set_size(obj, LV_VER_RES_MAX, LV_HOR_RES_MAX);
  lv_obj_set_pos(obj, 0, 0);

  return obj;
}

inline static void anim_y_callback(void* img, int32_t value) {
  lv_obj_set_y((lv_obj_t*)img, value);
  Serial.printf("Move element to y: %d\r\n", value);
}

inline lv_obj_t* lv_menu_button_create(lv_obj_t* parent, const lv_img_dsc_t* img_src, const lv_img_dsc_t* img_pressed_src, const char* txt) {
  static lv_style_t style_def;
  lv_style_init(&style_def);
  lv_style_set_text_color(&style_def, lv_color_white());

  lv_obj_t* button = lv_imgbtn_create(parent);

  lv_obj_add_style(button, &style_def, 0);
  lv_obj_set_width(button, 150);

  lv_imgbtn_set_src(button, LV_IMGBTN_STATE_RELEASED, NULL, img_src, NULL);
  lv_imgbtn_set_src(button, LV_IMGBTN_STATE_PRESSED, NULL, img_pressed_src, NULL);

  lv_obj_t* label = lv_label_create(button);
  lv_label_set_text(label, txt);
  lv_obj_align(label, LV_ALIGN_CENTER, 10, 4);

  return button;
}

inline lv_obj_t* lv_game_bar_create(lv_obj_t* parent, const lv_palette_t color) {
  static lv_style_t style_bg;
  static lv_style_t style_indic;

  lv_style_init(&style_bg);
  lv_style_set_border_width(&style_bg, 2);
  lv_style_set_pad_all(&style_bg, 3);
  lv_style_set_radius(&style_bg, 6);
  lv_style_set_anim_time(&style_bg, 1000);

  lv_style_init(&style_indic);
  lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
  lv_style_set_radius(&style_indic, 3);

  lv_obj_t* bar = lv_bar_create(lv_scr_act());
  lv_obj_remove_style_all(bar);
  lv_obj_add_style(bar, &style_bg, 0);
  lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);

  lv_obj_set_style_border_color(bar, lv_palette_main(color), LV_PART_MAIN);
  lv_obj_set_style_bg_color(bar, lv_palette_main(color), LV_PART_INDICATOR);

  lv_obj_set_size(bar, 120, 20);

  return bar;
}

inline bool check_action_time(unsigned long& last_millis, unsigned long wait) {
  if (millis() - last_millis >= wait) {
    last_millis = millis();
    return true;
  }

  return false;
}
#endif
