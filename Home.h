#pragma once

#include <lvgl.h>

class Home {
 public:
  Home();
  void loop();
  void destroy();

 private:
  void startButton();

 protected:
  bool _loaded = false;

  int8_t _title_position = -55;

  lv_obj_t * _title;
  lv_obj_t * _background;
  lv_obj_t * _screen;
};
