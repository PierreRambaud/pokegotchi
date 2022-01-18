#pragma once

#include <ArduinoJson.h>
#include <M5Core2.h>
#include <lvgl.h>

lv_obj_t * create_window() {
  lv_obj_t * obj = lv_obj_create(NULL);
  lv_obj_set_size(obj, LV_VER_RES_MAX, LV_HOR_RES_MAX);
  lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);

  return obj;
}

void save_data() {

}

void read_data() {

}

void get_save_filename() {

}
