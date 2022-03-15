#include "Menu.h"

using namespace Pokegotchi;

LV_IMG_DECLARE(menu_background);

Menu::Menu(lv_obj_t* main_screen) {
  _screen = create_screen(main_screen);

  lv_obj_t* background_image = lv_img_create(_screen);
  lv_img_set_src(background_image, &menu_background);
  lv_obj_set_pos(background_image, 0, 0);

  _battery_level_icon = lv_img_create(_screen);
  lv_obj_set_pos(_battery_level_icon, LV_HOR_RES_MAX - 30, 0);

  refresh_battery_status();

  _menu_screen = create_child_screen(_screen);

  static lv_style_t flex_style;
  lv_style_set_flex_flow(&flex_style, LV_FLEX_FLOW_ROW_WRAP);
  lv_style_set_flex_main_place(&flex_style, LV_FLEX_ALIGN_SPACE_AROUND);
  lv_style_set_layout(&flex_style, LV_LAYOUT_FLEX);

  lv_obj_add_style(_menu_screen, &flex_style, 0);
}

void Menu::close() {
  lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);
}
void Menu::open() {
  refresh_battery_status();
  lv_obj_clear_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  lv_obj_clear_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);
}
