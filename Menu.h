#ifndef POKEGOTCHI_MENU
#define POKEGOTCHI_MENU

#include <lvgl.h>

class Menu {
 public:
  void setup(lv_obj_t* screen);
  void toggle();

  static Menu* getInstance() {
    if (instance == nullptr) {
      instance = new Menu();
    }

    return instance;
  }

 private:
  Menu();

  static Menu* instance;

  bool _displayed = false;

  lv_obj_t* _background;
  lv_obj_t* _screen;
  lv_obj_t* _game_screen;
};
#endif
