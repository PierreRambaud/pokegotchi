#ifndef POKEGOTCHI_UTILS
#define POKEGOTCHI_UTILS

#include <M5Core2.h>
#include <lvgl.h>

static lv_style_t style_game_bar_bg;
static lv_style_t style_game_bar_indic;
static lv_style_t style_game_bar_label;

static inline lv_obj_t* create_window(lv_obj_t*);
static inline lv_obj_t* create_sub_window(lv_obj_t*);
static inline void anim_y_callback(void*, int32_t);

static inline lv_obj_t* create_window(lv_obj_t* parent = NULL) {
  lv_obj_t* obj = lv_obj_create(parent);
  lv_obj_remove_style_all(obj);
  lv_obj_set_size(obj, LV_HOR_RES_MAX, LV_VER_RES_MAX);
  lv_obj_set_pos(obj, 0, 0);

  return obj;
}

static inline lv_obj_t* create_sub_window(lv_obj_t* parent) {
  lv_obj_t* obj = lv_obj_create(parent);
  lv_obj_remove_style_all(obj);
  lv_obj_set_size(obj, LV_HOR_RES_MAX, LV_VER_RES_MAX - 40);
  lv_obj_align(obj, LV_ALIGN_CENTER, 0, 10);
  lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_ON);
  lv_obj_set_scroll_dir(obj, LV_DIR_VER);

  return obj;
}

static inline void anim_y_callback(void* img, int32_t value) {
  lv_obj_set_y((lv_obj_t*)img, value);
  Serial.printf("Move element to y: %d\r\n", value);
}

static inline lv_obj_t* lv_menu_button_create(lv_obj_t* parent, const lv_img_dsc_t* img_src, const lv_img_dsc_t* img_pressed_src, const char* title) {
  static lv_style_t style_def;
  lv_style_init(&style_def);
  lv_style_set_text_color(&style_def, lv_color_white());

  lv_obj_t* button = lv_imgbtn_create(parent);

  lv_obj_add_style(button, &style_def, 0);
  lv_obj_set_width(button, 150);

  lv_imgbtn_set_src(button, LV_IMGBTN_STATE_RELEASED, NULL, img_src, NULL);
  lv_imgbtn_set_src(button, LV_IMGBTN_STATE_PRESSED, NULL, img_pressed_src, NULL);

  lv_obj_t* label = lv_label_create(button);
  lv_label_set_text(label, title);
  lv_obj_align(label, LV_ALIGN_CENTER, 10, 4);

  return button;
}

static inline lv_obj_t* lv_game_bar_create(lv_obj_t* parent, const lv_palette_t color, const char* title, const int16_t x, const int16_t y, const int16_t max_range) {
  lv_style_init(&style_game_bar_label);
  lv_style_set_text_color(&style_game_bar_label, lv_color_black());

  lv_style_init(&style_game_bar_bg);
  lv_style_set_border_width(&style_game_bar_bg, 2);
  lv_style_set_pad_all(&style_game_bar_bg, 3);
  lv_style_set_radius(&style_game_bar_bg, 6);
  lv_style_set_anim_time(&style_game_bar_bg, 1000);

  lv_style_init(&style_game_bar_indic);
  lv_style_set_bg_opa(&style_game_bar_indic, LV_OPA_COVER);
  lv_style_set_radius(&style_game_bar_indic, 3);

  lv_obj_t* bar = lv_bar_create(lv_scr_act());
  lv_obj_remove_style_all(bar);
  lv_obj_add_style(bar, &style_game_bar_bg, 0);
  lv_obj_add_style(bar, &style_game_bar_indic, LV_PART_INDICATOR);

  lv_obj_set_style_border_color(bar, lv_palette_main(color), LV_PART_MAIN);
  lv_obj_set_style_bg_color(bar, lv_palette_main(color), LV_PART_INDICATOR);

  lv_obj_set_size(bar, 120, 20);
  lv_bar_set_range(bar, 0, max_range);

  lv_obj_set_pos(bar, x, y);

  lv_obj_t* label = lv_label_create(lv_scr_act());
  lv_label_set_text(label, title);
  lv_obj_add_style(label, &style_game_bar_label, 0);
  lv_obj_align_to(label, bar, LV_ALIGN_OUT_TOP_MID, 0, -5);

  return bar;
}

static inline bool check_action_time(unsigned long& last_millis, unsigned long wait) {
  if (millis() - last_millis >= wait) {
    last_millis = millis();
    return true;
  }

  return false;
}

#endif
