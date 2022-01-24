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
#endif
