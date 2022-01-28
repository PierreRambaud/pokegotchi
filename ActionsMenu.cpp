#include <lvgl.h>
#include "ActionsMenu.h"
#include "Utils.h"
#include "Pokemon.h"
#include "Game.h"
#include "assets/menu/background.c"
#include "assets/menu/bag.c"
#include "assets/menu/bag_pressed.c"
#include "assets/menu/flute.c"
#include "assets/menu/flute_pressed.c"
#include "assets/objects/bag/noodles.c"

LV_IMG_DECLARE(noodles);

ActionsMenu* ActionsMenu::instance = nullptr;

ActionsMenu::ActionsMenu() { _items[0] = Item{noodles, "Noodles", "Hum noodles"}; }

static void use_item_event_handler(lv_event_t* e) { lv_obj_t* item = (lv_obj_t*)lv_event_get_user_data(e); }

static void display_bag_items_event_handler(lv_event_t* e) { ActionsMenu::getInstance()->display_bag(); }

static void create_object_row(lv_obj_t* tile, Item item) {
  lv_obj_t* image = lv_img_create(tile);
  lv_img_set_src(image, &item.image);
}

static void toggle_sleep_event_handler(lv_event_t* e) {
  Pokemon* p = Pokemon::getInstance();
  Game* g = Game::getInstance();
  lv_obj_t* label = (lv_obj_t*)lv_event_get_user_data(e);

  ActionsMenu::getInstance()->toggle();
  if (p->is_sleeping() == true) {
    g->action_wake_up();
    lv_label_set_text(label, "Sleep");
  } else {
    g->action_sleep();
    lv_label_set_text(label, "Wake up");
  }
}

void ActionsMenu::setup(lv_obj_t* screen) {
  _game_screen = screen;
  _screen = create_window();
  _bag_screen = create_window(_screen);
  lv_obj_add_flag(_bag_screen, LV_OBJ_FLAG_HIDDEN);

  // lv_obj_t* tv = lv_tileview_create(_bag_screen);
  // lv_obj_t* tile = lv_tileview_add_tile(tv, 0, 0, LV_DIR_BOTTOM);
  // for (int index = 0; index < sizeof(_items); index++) {
  //   create_object_row(tile, _items[index]);
  // }

  Serial.println("ActionsMenu Screen created");
  LV_IMG_DECLARE(background);
  _background = lv_img_create(_screen);
  lv_img_set_src(_background, &background);
  lv_obj_set_pos(_background, 0, 0);

  Serial.println("ActionsMenu background created");
  LV_IMG_DECLARE(bag);
  LV_IMG_DECLARE(bag_pressed);

  lv_obj_t* bag_button = lv_menu_button_create(_screen, &bag, &bag_pressed, "Bag");
  lv_obj_set_pos(bag_button, 7, 45);
  lv_obj_add_event_cb(bag_button, display_bag_items_event_handler, LV_EVENT_CLICKED, NULL);

  LV_IMG_DECLARE(flute);
  LV_IMG_DECLARE(flute_pressed);
  lv_obj_t* sleep_button = lv_menu_button_create(_screen, &flute, &flute_pressed, "Sleep");
  lv_obj_t* sleep_label = lv_obj_get_child(sleep_button, -1);
  lv_obj_set_pos(sleep_button, 7, 105);
  lv_obj_add_event_cb(sleep_button, toggle_sleep_event_handler, LV_EVENT_CLICKED, sleep_label);

  Serial.println("Buttons for actions menu created");

  toggle();
}

void ActionsMenu::display_bag() {
  lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  lv_scr_load(_bag_screen);
  lv_obj_clear_flag(_screen, LV_OBJ_FLAG_HIDDEN);
}

void ActionsMenu::toggle() {
  if (lv_obj_has_flag(_screen, LV_OBJ_FLAG_HIDDEN)) {
    lv_scr_load(_screen);
    lv_obj_clear_flag(_screen, LV_OBJ_FLAG_HIDDEN);
    Serial.println("Show ActionsMenu");
  } else {
    lv_scr_load(_game_screen);
    lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
    Serial.println("Hide menu");
  }
}
