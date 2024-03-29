#pragma once
#ifndef POKEGOTCHI_UTILS
#define POKEGOTCHI_UTILS

#include "stdio.h"
#include "lvgl.h"
#include "utils_hal.h"

static lv_style_t style_default_title;
static lv_style_t style_default_text;
static lv_style_t style_game_bar_bg;
static lv_style_t style_game_bar_indic;
static lv_style_t style_game_label;

static const size_t MAX_SERIAL_BUFFER = 256;

typedef struct {
  lv_obj_t* box;
  lv_obj_t* close_button;
} poke_messagebox_t;

/**
 * Serial printf wrapper to add a context and line break
 * @param const char* context
 * @param const char* format
 * @param ...
 */
static inline void serial_printf(const char* context, const char* format, ...) {
  char buffer[MAX_SERIAL_BUFFER];

  va_list args;
  va_start(args, format);

  vsnprintf(buffer, sizeof(buffer), format, args);

  va_end(args);

  hal_printf(context, buffer);
}

/**
 * Create a new screen
 *
 * @param lv_obj_t* parent
 * @return lv_obj_t*
 */
static inline lv_obj_t* create_screen(lv_obj_t* parent = NULL) {
  lv_obj_t* obj = lv_obj_create(parent);
  lv_obj_remove_style_all(obj);
  lv_obj_set_size(obj, LV_HOR_RES_MAX, LV_VER_RES_MAX);
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);

  return obj;
}

/**
 * Create a child screen with padding
 *
 * @param lv_obj_t* parent
 * @return lv_obj_t*
 */
static inline lv_obj_t* create_child_screen(lv_obj_t* parent) {
  lv_obj_t* obj = lv_obj_create(parent);
  lv_obj_remove_style_all(obj);
  lv_obj_set_size(obj, LV_HOR_RES_MAX, LV_VER_RES_MAX - 40);
  lv_obj_align(obj, LV_ALIGN_CENTER, 0, 10);
  lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_ON);
  lv_obj_set_scroll_dir(obj, LV_DIR_VER);

  return obj;
}

static inline void anim_y_callback(void* obj, int32_t value) { lv_obj_set_y((lv_obj_t*)obj, value); }
static inline void anim_x_callback(void* obj, int32_t value) { lv_obj_set_x((lv_obj_t*)obj, value); }

/**
 * Create message box
 *
 * @param const char* title
 * @param const char* message
 * @return lv_obj_t*
 **/
static inline poke_messagebox_t* create_message_box(const char* title, const char* message) {
  lv_obj_t* msg_box = lv_msgbox_create(NULL);
  lv_msgbox_add_title(msg_box, title);
  lv_msgbox_add_text(msg_box, message);

  lv_obj_t* close_button = lv_msgbox_add_close_button(msg_box);
  lv_obj_set_size(close_button, 30, 30);

  return new poke_messagebox_t{msg_box, close_button};
}

/**
 * Check if an action should be executed
 *
 * @param unsigned long& last_millis
 * @param unsigned long wait
 *
 * return bool
 */
static inline bool check_action_time(long& last_millis, unsigned long wait) {
  if (hal_millis() - last_millis >= wait) {
    last_millis = hal_millis();
    return true;
  }

  return false;
}

/**
 * Create menu button
 *
 * @param lv_obj_t* parent
 * @param lv_image_dsc_t* img_src
 * @param lv_image_dsc_t* img_pressed_src
 * @param const char* title
 *
 * return lv_obj_t*
 */
static inline lv_obj_t* lv_menu_button_create(lv_obj_t* parent, const lv_image_dsc_t* img_src, const lv_image_dsc_t* img_pressed_src, const char* title) {
  lv_style_init(&style_default_text);
  lv_style_set_text_color(&style_default_text, lv_color_white());

  lv_obj_t* button = lv_imagebutton_create(parent);
  lv_obj_add_style(button, &style_default_text, 0);
  lv_obj_set_width(button, 150);

  lv_imagebutton_set_src(button, LV_IMAGEBUTTON_STATE_RELEASED, NULL, img_src, NULL);
  lv_imagebutton_set_src(button, LV_IMAGEBUTTON_STATE_PRESSED, NULL, img_pressed_src, NULL);

  lv_obj_t* label = lv_label_create(button);
  lv_label_set_text(label, title);
  lv_obj_align(label, LV_ALIGN_CENTER, 10, 4);

  return button;
}

/**
 * Create game bar indicator
 *
 * @param lv_obj_t* parent
 * @param lv_palette_t color
 * @param const char* title
 * @param int16_t x
 * @param int16_t y
 * @param int16_t max_range
 *
 * return lv_obj_t*
 */
static inline lv_obj_t* lv_game_bar_create(lv_obj_t* parent, const lv_palette_t color, const char* title, const int16_t x, const int16_t y, const int16_t max_range) {
  lv_style_init(&style_game_label);
  lv_style_set_text_color(&style_game_label, lv_color_black());

  lv_style_init(&style_game_bar_bg);
  lv_style_set_border_width(&style_game_bar_bg, 2);
  lv_style_set_pad_all(&style_game_bar_bg, 3);
  lv_style_set_radius(&style_game_bar_bg, 6);
  lv_style_set_anim_time(&style_game_bar_bg, 1000);

  lv_style_init(&style_game_bar_indic);
  lv_style_set_bg_opa(&style_game_bar_indic, LV_OPA_COVER);
  lv_style_set_radius(&style_game_bar_indic, 3);

  lv_obj_t* bar = lv_bar_create(lv_screen_active());
  lv_obj_remove_style_all(bar);
  lv_obj_add_style(bar, &style_game_bar_bg, 0);
  lv_obj_add_style(bar, &style_game_bar_indic, LV_PART_INDICATOR);

  lv_obj_set_style_border_color(bar, lv_palette_main(color), LV_PART_MAIN);
  lv_obj_set_style_bg_color(bar, lv_palette_main(color), LV_PART_INDICATOR);

  lv_obj_set_size(bar, 120, 20);
  lv_bar_set_range(bar, 0, max_range);

  lv_obj_set_pos(bar, x, y);

  lv_obj_t* label = lv_label_create(lv_screen_active());
  lv_label_set_text(label, title);
  lv_obj_add_style(label, &style_game_label, 0);
  lv_obj_align_to(label, bar, LV_ALIGN_OUT_TOP_MID, 0, -5);

  return bar;
}

/**
 * Change the brightness value of the screen
 * @param int32_t value
 */
static inline void set_lcd_brightness(int32_t value) {
  serial_printf("Options", "Brightness new value: %d", value);
  hal_set_brightness(value);
}

#endif
