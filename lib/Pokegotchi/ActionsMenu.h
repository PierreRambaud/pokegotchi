#pragma once
#ifndef POKEGOTCHI_ACTIONSMENU
#define POKEGOTCHI_ACTIONSMENU

#include <lvgl.h>
#include "Menu.h"

#define BAG_ITEMS_SIZE 15

namespace Pokegotchi {

  struct bag_item_specifications {
    int8_t mood;
    int8_t hunger;
    int8_t life;
    int8_t sleepiness;
    int8_t poo;
    int8_t pee;
  };

  typedef struct bag_item_specifications BagItemSpecifications;

  struct bag_item {
    const lv_img_dsc_t* image;
    const char* name;
    const char* description;
    BagItemSpecifications* specs;
  };

  typedef struct bag_item BagItem;

  class ActionsMenu {
   public:
    explicit ActionsMenu(Menu* menu);
    void display_bag();
    void open();
    void close() {
      if (lv_obj_is_valid(_menu_child_screen)) {
        // Remove sub menu anyway
        lv_obj_del(_menu_child_screen);
      }

      Serial.println("Hide ActionsMenu");
      _menu->close();
    }
    void toggle() {
      if (lv_obj_has_flag(_menu->get_screen(), LV_OBJ_FLAG_HIDDEN)) {
        open();
      } else {
        close();
      }
    }

    static ActionsMenu* getInstance() { return _instance; }
    static void setInstance(ActionsMenu* instance) { _instance = instance; }

    Menu* get_menu() { return _menu; }

   private:
    static ActionsMenu* _instance;

    BagItem* _items[BAG_ITEMS_SIZE];

    Menu* _menu;
    lv_obj_t* _menu_child_screen;

    lv_obj_t* _bag_button;
    lv_obj_t* _clean_button;
    lv_obj_t* _heal_button;
    lv_obj_t* _play_button;
    lv_obj_t* _sleep_button;
    lv_obj_t* _train_button;
  };
}  // namespace Pokegotchi
#endif
