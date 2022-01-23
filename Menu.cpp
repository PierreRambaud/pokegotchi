#include <lvgl.h>
#include "Menu.h"
#include "Utils.h"
#include "assets/menu/background.c"
#include "assets/menu/save.c"
#include "assets/menu/save_pressed.c"
#include "assets/menu/pokeball.c"
#include "assets/menu/pokeball_pressed.c"
#include "assets/menu/options.c"
#include "assets/menu/options_pressed.c"

Menu* Menu::instance = nullptr;

Menu::Menu() {}

void Menu::setup() {
  _screen = create_window();
  lv_scr_load(_screen);

  LV_IMG_DECLARE(background);
  _background = lv_img_create(_screen);
  lv_img_set_src(_background, &background);
  lv_obj_set_pos(_background, 0, 0);

  toggle();

  LV_IMG_DECLARE(save);
  LV_IMG_DECLARE(save_pressed);

  lv_obj_t* save_button = lv_menu_button_create(_screen, &save, &save_pressed, "Save");
  lv_obj_set_pos(save_button, 10, 55);

  lv_obj_t* options_button = lv_menu_button_create(_screen, &options, &options_pressed, "Options");
  lv_obj_set_pos(options_button, 10, 105);

  lv_obj_t* pokemon_button = lv_menu_button_create(_screen, &pokeball, &pokeball_pressed, "Pokemon");
  lv_obj_set_pos(pokemon_button, 165, 55);
}

void Menu::toggle() {
  if (lv_obj_has_flag(_screen, LV_OBJ_FLAG_HIDDEN)) {
    lv_obj_clear_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  }
}
