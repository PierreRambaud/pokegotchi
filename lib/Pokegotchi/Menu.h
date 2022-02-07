#ifndef POKEGOTCHI_MENU
#define POKEGOTCHI_MENU

#include <lvgl.h>
#include <M5Core2.h>
#include "Utils.h"
#include "assets/menu/background.c"
#include "assets/battery/battery_charging.c"
#include "assets/battery/battery_low.c"
#include "assets/battery/battery_middle.c"
#include "assets/battery/battery_full.c"

#define BAG_ITEMS_SIZE 15

struct bag_item_specifications {
  const int mood;
  const int hunger;
  const int life;
  const int sleepiness;
};

typedef struct bag_item_specifications ItemSpecifications;

struct bag_item {
  const lv_img_dsc_t* image;
  const char* name;
  const char* description;
  // ItemSpecifications* specs;
};

typedef struct bag_item Item;

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

  void refresh_battery_status() {
    if (M5.Axp.isCharging() == true) {
      lv_img_set_src(_battery_level_icon, &battery_charging);
    } else {
      float battery_level = M5.Axp.GetBatteryLevel();
      if (battery_level >= 80) {
        lv_img_set_src(_battery_level_icon, &battery_full);
      } else if (battery_level >= 40) {
        lv_img_set_src(_battery_level_icon, &battery_middle);
      } else {
        lv_img_set_src(_battery_level_icon, &battery_low);
      }

      Serial.printf("Battery status: %f\r\n", battery_level);
    }
  }

 protected:
  Menu();

  static Menu* instance;

  void init(lv_obj_t* main_screen) {
    _game_screen = main_screen;
    _screen = create_window();

    lv_obj_t* background_image = lv_img_create(_screen);
    lv_img_set_src(background_image, &background);
    lv_obj_set_pos(background_image, 0, 0);

    _battery_level_icon = lv_img_create(_screen);

    lv_obj_set_pos(_battery_level_icon, LV_HOR_RES_MAX - 30, 0);
    refresh_battery_status();

    Serial.println("Menu background created");

    _menu_screen = create_sub_window(_screen);
    Serial.println("Menu Screen created");
  }

  bool _displayed = false;

  lv_obj_t* _battery_level_icon;

  lv_obj_t* _screen;
  lv_obj_t* _game_screen;
  lv_obj_t* _menu_screen;
};

class ActionsMenu : public Menu {
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

 protected:
  ActionsMenu();

  static ActionsMenu* instance;

  lv_obj_t* _bag_screen;

  Item _items[BAG_ITEMS_SIZE];
};
#endif
