#pragma once

#include <functional>
#include <lvgl.h>

class Home {
 public:
  static Home * getInstance();

  void loop();

  lv_obj_t * getScreen() { return _screen; }

 private:
  Home();

  static Home * instance;

  bool _loaded = false;

  int8_t _title_position = -55;

  lv_obj_t * _background;
  lv_obj_t * _screen;
  lv_obj_t * _title;
};
