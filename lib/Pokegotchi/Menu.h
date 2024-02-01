#pragma once
#ifndef POKEGOTCHI_MENU
#define POKEGOTCHI_MENU

#include "lvgl.h"
#include "Utils.h"

#define BAG_ITEMS_SIZE 15

namespace Pokegotchi {
  class Menu {
   public:
    explicit Menu(lv_obj_t* main_screen);
    void open();
    void close();

    void refresh_battery_status();

    lv_obj_t* get_screen() { return _screen; }
    lv_obj_t* get_menu_screen() { return _menu_screen; }

   protected:
    bool _is_open = false;

    lv_obj_t* _battery_level_icon;

    lv_obj_t* _screen;
    lv_obj_t* _menu_screen;

    const char* _previous_battery_image = "";
  };
}  // namespace Pokegotchi
#endif
