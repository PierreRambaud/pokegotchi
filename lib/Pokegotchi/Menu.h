#pragma once
#ifndef POKEGOTCHI_MENU
#define POKEGOTCHI_MENU

#include <lvgl.h>
#include "Utils.h"

#define BAG_ITEMS_SIZE 15

namespace Pokegotchi {
  class Menu {
   public:
    Menu(lv_obj_t*);
    void open();
    void close();

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

        Serial.printf("Battery status: %f\n", battery_level);
      }

      if (_previous_battery_image != battery_image) {
        lv_img_set_src(_battery_level_icon, battery_image);
        _previous_battery_image = battery_image;
      }
    }

    lv_obj_t* get_screen() { return _screen; }
    lv_obj_t* get_menu_screen() { return _menu_screen; }

   protected:
    bool _displayed = false;

    lv_obj_t* _battery_level_icon;

    lv_obj_t* _screen;
    lv_obj_t* _menu_screen;

    const char* _previous_battery_image = "";
  };
}  // namespace Pokegotchi
#endif
