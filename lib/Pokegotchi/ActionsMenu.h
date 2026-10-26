#pragma once
#ifndef POKEGOTCHI_ACTIONSMENU
#define POKEGOTCHI_ACTIONSMENU

#include "lvgl.h"
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
    // Sweets: too many of them make the Pokemon sick
    int8_t snack;
  };

  typedef struct bag_item_specifications BagItemSpecifications;

  struct bag_item {
    const lv_image_dsc_t* image;
    const char* name;
    const char* description;
    BagItemSpecifications* specs;
  };

  typedef struct bag_item BagItem;

  class ActionsMenu {
   public:
    explicit ActionsMenu(Menu* menu);
    ~ActionsMenu(void);
    void display_bag(void);
    void invalidate_bag(void);
    void open(void);
    void close(void) {
      if (lv_obj_is_valid(_menu_child_screen)) {
        // Bag screen is built once and reused; just hide it.
        lv_obj_add_flag(_menu_child_screen, LV_OBJ_FLAG_HIDDEN);
      }

      serial_printf("ActionsMenu", "Hide ActionsMenu");
      _menu->close();
    }
    void toggle(void) {
      if (lv_obj_has_flag(_menu->get_screen(), LV_OBJ_FLAG_HIDDEN)) {
        open();
      } else {
        close();
      }
    }

    static ActionsMenu* getInstance(void) { return _instance; }
    static void setInstance(ActionsMenu* instance) { _instance = instance; }

    Menu* get_menu(void) { return _menu; }

   private:
    static ActionsMenu* _instance;

    BagItem* _items[BAG_ITEMS_SIZE];

    Menu* _menu;
    lv_obj_t* _menu_child_screen = nullptr;
    bool _bag_initialized = false;

    lv_obj_t* _bag_button;
    lv_obj_t* _clean_button;
    lv_obj_t* _heal_button;
    lv_obj_t* _play_button;
    lv_obj_t* _sleep_button;
    lv_obj_t* _train_button;
  };
}  // namespace Pokegotchi
#endif
