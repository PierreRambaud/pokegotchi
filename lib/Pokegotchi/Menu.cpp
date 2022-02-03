#include <lvgl.h>
#include "lv_i18n.h"
#include "Menu.h"
#include "Utils.h"
#include "assets/menu/background.c"
#include "assets/menu/save.c"
#include "assets/menu/save_pressed.c"
#include "assets/menu/pokeball.c"
#include "assets/menu/pokeball_pressed.c"
#include "assets/menu/options.c"
#include "assets/menu/options_pressed.c"
#include "assets/menu/trainercard.c"
#include "assets/menu/trainercard_pressed.c"

static void trainercard_event_handler(lv_event_t* e);

Menu* Menu::instance = nullptr;

Menu::Menu() {}

void Menu::setup(lv_obj_t* screen) {
  _game_screen = screen;
  _screen = create_window();

  Serial.println("Menu Screen created");

  lv_obj_t* background_image = lv_img_create(_screen);
  lv_img_set_src(background_image, &background);
  lv_obj_set_pos(background_image, 0, 0);

  Serial.println("Menu background created");

  lv_obj_t* save_button = lv_menu_button_create(_screen, &save, &save_pressed, _("menu.save"));
  lv_obj_set_pos(save_button, 7, 45);

  lv_obj_t* options_button = lv_menu_button_create(_screen, &options, &options_pressed, _("menu.options"));
  lv_obj_set_pos(options_button, 7, 105);

  lv_obj_t* pokemon_button = lv_menu_button_create(_screen, &pokeball, &pokeball_pressed, "Pokémon");
  lv_obj_set_pos(pokemon_button, 165, 45);

  lv_obj_t* trainercard_button = lv_menu_button_create(_screen, &trainercard, &trainercard_pressed, _("menu.games"));
  lv_obj_set_pos(trainercard_button, 165, 105);
  lv_obj_add_event_cb(trainercard_button, trainercard_event_handler, LV_EVENT_CLICKED, NULL);

  Serial.println("Buttons for menu created");

  toggle();
}

void Menu::toggle() {
  if (lv_obj_has_flag(_screen, LV_OBJ_FLAG_HIDDEN)) {
    lv_scr_load(_screen);
    lv_obj_clear_flag(_screen, LV_OBJ_FLAG_HIDDEN);
    Serial.println("Show Menu");
  } else {
    lv_scr_load(_game_screen);
    lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
    Serial.println("Hide Menu");
  }
}

static void trainercard_event_handler(lv_event_t* e) {}
