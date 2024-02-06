#include "Menu.h"
#include "utils_hal.h"

using namespace Pokegotchi;

LV_IMG_DECLARE(menu_background);

Menu::Menu(lv_obj_t* main_screen) {
  _screen = create_screen(main_screen);

  lv_obj_t* background_image = lv_image_create(_screen);
  lv_image_set_src(background_image, &menu_background);
  lv_obj_set_pos(background_image, 0, 0);

#ifdef POKEGOTCHI_BATTERY
  _battery_level_icon = lv_image_create(_screen);
  lv_obj_set_pos(_battery_level_icon, LV_HOR_RES_MAX - 30, 0);

  refresh_battery_status();
#endif

  _menu_screen = create_child_screen(_screen);

  static lv_style_t flex_style;
  lv_style_set_flex_flow(&flex_style, LV_FLEX_FLOW_ROW_WRAP);
  lv_style_set_flex_main_place(&flex_style, LV_FLEX_ALIGN_SPACE_AROUND);
  lv_style_set_layout(&flex_style, LV_LAYOUT_FLEX);

  lv_obj_add_style(_menu_screen, &flex_style, 0);
}

void Menu::close() {
  _is_open = false;
  lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);
}

void Menu::open() {
  _is_open = true;
  refresh_battery_status();

  lv_obj_remove_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  lv_obj_remove_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);
}

void Menu::refresh_battery_status() {
#ifndef POKEGOTCHI_BATTERY
  return;
#else
  if (_is_open == false) {
    return;
  }

  const char* battery_image = "";
  if (hal_battery_is_charging() == true) {
    serial_printf("Menu", "Battery is charging");
    battery_image = "L:/menu/battery/charging.bin";
  } else {
    float battery_level = hal_battery_level();
    if (battery_level >= 80) {
      battery_image = "L:/menu/battery/full.bin";
    } else if (battery_level >= 40) {
      battery_image = "L:/menu/battery/middle.bin";
    } else {
      battery_image = "L:/menu/battery/low.bin";
    }

    serial_printf("Menu", "Battery status: %f", battery_level);
    serial_printf("Menu", "Image: %s", battery_image);
  }

  if (_previous_battery_image != battery_image) {
    lv_image_set_src(_battery_level_icon, battery_image);
    _previous_battery_image = battery_image;
  }
#endif
}
