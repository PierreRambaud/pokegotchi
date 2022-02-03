#ifndef POKEGOTCHI_ACTIONS_MENU
#define POKEGOTCHI_ACTIONS_MENU

#include <lvgl.h>

#define BAG_ITEMS_SIZE 15

struct item {
  const lv_img_dsc_t* image;
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
  void create_bag();

  bool _displayed = false;

  lv_obj_t* _screen;
  lv_obj_t* _game_screen;
  lv_obj_t* _bag_screen;
  lv_obj_t* _actions_screen;

  Item _items[BAG_ITEMS_SIZE];
};
#endif
