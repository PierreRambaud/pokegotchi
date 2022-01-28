#ifndef POKEGOTCHI_ACTIONS_MENU
#define POKEGOTCHI_ACTIONS_MENU

#include <lvgl.h>

struct item {
  lv_img_dsc_t image;
  const char* name;
  const char* description;
};

typedef struct item Item;

class ActionsMenu {
 public:
  void setup(lv_obj_t* screen);
  void toggle();
  void display_bag();

  static ActionsMenu* getInstance() {
    if (instance == nullptr) {
      instance = new ActionsMenu();
    }

    return instance;
  }

 private:
  ActionsMenu();

  static ActionsMenu* instance;

  bool _displayed = false;

  lv_obj_t* _background;
  lv_obj_t* _screen;
  lv_obj_t* _game_screen;
  lv_obj_t* _bag_screen;

  Item _items[1];
};
#endif
