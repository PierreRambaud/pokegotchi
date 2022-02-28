#ifndef POKEGOTCHI_MENU
#define POKEGOTCHI_MENU

#include <lvgl.h>
#include <M5Core2.h>
#include "Utils.h"

#define BAG_ITEMS_SIZE 15

LV_IMG_DECLARE(background);

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
  ItemSpecifications* specs;
};

typedef struct bag_item Item;

class Menu {
 public:
  virtual void setup(lv_obj_t* screen);
  virtual void open();
  void close();
  void toggle();
  void display_options();
  void display_pokemon();

  static Menu* getInstance() {
    if (instance == nullptr) {
      instance = new Menu();
    }

    return instance;
  }

  void refresh_battery_status() {
    const char* battery_image = "";
    if (M5.Axp.isCharging() == true) {
      Serial.println("Battery is charging");
      battery_image = "L:/menu/battery/charging.bin";
    } else {
      float battery_level = M5.Axp.GetBatteryLevel();
      if (battery_level >= 80) {
        battery_image = "L:/menu/battery/full.bin";
      } else if (battery_level >= 40) {
        battery_image = "L:/menu/battery/middle.bin";
      } else {
        battery_image = "L:/menu/battery/low.bin";
      }

      Serial.printf("Battery status: %f\r\n", battery_level);
    }

    if (_previous_battery_image != battery_image) {
      lv_img_set_src(_battery_level_icon, battery_image);
      _previous_battery_image = battery_image;
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

    static lv_style_t flex_style;
    lv_style_set_flex_flow(&flex_style, LV_FLEX_FLOW_ROW_WRAP);
    lv_style_set_flex_main_place(&flex_style, LV_FLEX_ALIGN_SPACE_AROUND);
    lv_style_set_layout(&flex_style, LV_LAYOUT_FLEX);

    _menu_screen = create_sub_window(_screen);

    lv_obj_add_style(_menu_screen, &flex_style, 0);
    Serial.println("Menu Screen created");
  }

  bool _displayed = false;

  lv_obj_t* _battery_level_icon;

  lv_obj_t* _screen;
  lv_obj_t* _game_screen;
  lv_obj_t* _menu_screen;
  lv_obj_t* _sub_menu_screen;

  const char* _previous_battery_image = "";
};

class ActionsMenu : public Menu {
 public:
  virtual void setup(lv_obj_t* screen);
  virtual void open();
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

  Item _items[BAG_ITEMS_SIZE];

 private:
  lv_obj_t* _bag_button;
  lv_obj_t* _sleep_button;
  lv_obj_t* _train_button;
  lv_obj_t* _play_button;
};
#endif
