#include <lvgl.h>
#include "lv_i18n.h"
#include "ActionsMenu.h"
#include "Utils.h"
#include "Pokemon.h"
#include "Game.h"
#include "assets/menu/background.c"
#include "assets/menu/bag.c"
#include "assets/menu/bag_pressed.c"
#include "assets/menu/flute.c"
#include "assets/menu/flute_pressed.c"
#include "assets/objects/bag/apple.c"
#include "assets/objects/bag/beans.c"
#include "assets/objects/bag/berry.c"
#include "assets/objects/bag/candy_box.c"
#include "assets/objects/bag/cheese.c"
#include "assets/objects/bag/chicken.c"
#include "assets/objects/bag/coconut_milk.c"
#include "assets/objects/bag/frozen_carrots.c"
#include "assets/objects/bag/haricots.c"
#include "assets/objects/bag/honey.c"
#include "assets/objects/bag/milk.c"
#include "assets/objects/bag/noodles.c"
#include "assets/objects/bag/spices.c"
#include "assets/objects/bag/sugar_star.c"
#include "assets/objects/bag/water.c"

static void use_item_event_handler(lv_event_t* e);
static void display_bag_items_event_handler(lv_event_t* e);
static void train_event_handler(lv_event_t* e);
static void toggle_sleep_event_handler(lv_event_t* e);
static lv_obj_t* create_row_item(lv_obj_t* parent, Item* item);

ActionsMenu* ActionsMenu::instance = nullptr;

ActionsMenu::ActionsMenu() {
  _items[0] = Item{&apple, _("bag.apple.name"), _("bag.apple.description")};
  _items[1] = Item{&beans, _("bag.beans.name"), _("bag.beans.description")};
  _items[2] = Item{&berry, _("bag.berry.name"), _("bag.berry.description")};
  _items[3] = Item{&candy_box, _("bag.candy.name"), _("bag.candy.description")};
  _items[4] = Item{&cheese, _("bag.cheese.name"), _("bag.cheese.description")};
  _items[5] = Item{&chicken, _("bag.chicken.name"), _("bag.chicken.description")};
  _items[6] = Item{&coconut_milk, _("bag.coconut_milk.name"), _("bag.coconut_milk.description")};
  _items[7] = Item{&frozen_carrots, _("bag.frozen_carrots.name"), _("bag.frozen_carrots.description")};
  _items[8] = Item{&haricots, _("bag.haricots.name"), _("bag.haricots.description")};
  _items[9] = Item{&honey, _("bag.honey.name"), _("bag.honey.description")};
  _items[10] = Item{&milk, _("bag.milk.name"), _("bag.milk.description")};
  _items[11] = Item{&noodles, _("bag.noodles.name"), _("bag.noodles.description")};
  _items[12] = Item{&spices, _("bag.spices.name"), _("bag.spices.description")};
  _items[13] = Item{&sugar_star, _("bag.sugar_star.name"), _("bag.sugar_star.description")};
  _items[14] = Item{&water, _("bag.water.name"), _("bag.water.description")};
}

void ActionsMenu::setup(lv_obj_t* screen) {
  _game_screen = screen;
  _screen = create_window();

  Serial.println("ActionsMenu Screen created");

  lv_obj_t* background_image = lv_img_create(_screen);
  lv_img_set_src(background_image, &background);
  lv_obj_set_pos(background_image, 0, 0);
  Serial.println("ActionsMenu background created");

  _actions_screen = create_window(_screen);

  lv_obj_t* bag_button = lv_menu_button_create(_actions_screen, &bag, &bag_pressed, _("actions.menu.bag"));
  lv_obj_set_pos(bag_button, 7, 45);
  lv_obj_add_event_cb(bag_button, display_bag_items_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* sleep_button = lv_menu_button_create(_actions_screen, &flute, &flute_pressed, _("actions.menu.sleep"));
  lv_obj_t* sleep_label = lv_obj_get_child(sleep_button, -1);
  lv_obj_set_pos(sleep_button, 165, 45);
  lv_obj_add_event_cb(sleep_button, toggle_sleep_event_handler, LV_EVENT_CLICKED, sleep_label);

  Serial.println("Buttons for actions menu created");

  create_bag();

  toggle();
}

void ActionsMenu::create_bag() {
  _bag_screen = lv_obj_create(_screen);
  lv_obj_remove_style_all(_bag_screen);
  lv_obj_set_size(_bag_screen, LV_HOR_RES_MAX - 30, LV_VER_RES_MAX - 40);
  lv_obj_align(_bag_screen, LV_ALIGN_CENTER, 0, 10);
  lv_obj_set_scrollbar_mode(_bag_screen, LV_SCROLLBAR_MODE_ON);
  lv_obj_set_scroll_dir(_bag_screen, LV_DIR_VER);

  lv_obj_set_flex_flow(_bag_screen, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_grow(_bag_screen, 1);
  lv_obj_add_flag(_bag_screen, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);

  for (Item item : _items) {
    create_row_item(_bag_screen, &item);
  }
}

void ActionsMenu::display_bag() {
  lv_obj_scroll_to_y(_bag_screen, 0, LV_ANIM_OFF);
  lv_obj_clear_flag(_bag_screen, LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(_actions_screen, LV_OBJ_FLAG_HIDDEN);
}

void ActionsMenu::toggle() {
  if (lv_obj_has_flag(_screen, LV_OBJ_FLAG_HIDDEN)) {
    lv_scr_load(_screen);
    lv_obj_clear_flag(_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(_actions_screen, LV_OBJ_FLAG_HIDDEN);
    Serial.println("Show ActionsMenu");
  } else {
    lv_scr_load(_game_screen);
    lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(_actions_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(_bag_screen, LV_OBJ_FLAG_HIDDEN);
    Serial.println("Hide ActionsMenu");
  }
}
static void use_item_event_handler(lv_event_t* e) {
  Item* item = (Item*)lv_event_get_user_data(e);

  ActionsMenu::getInstance()->toggle();
  Game* g = Game::getInstance();
  g->action_eat();
}

static void display_bag_items_event_handler(lv_event_t* e) { ActionsMenu::getInstance()->display_bag(); }

static void train_event_handler(lv_event_t* e) {
  Game* g = Game::getInstance();

  ActionsMenu::getInstance()->toggle();
  g->action_train();
}

static void toggle_sleep_event_handler(lv_event_t* e) {
  Pokemon* p = Pokemon::getInstance();
  Game* g = Game::getInstance();
  lv_obj_t* label = (lv_obj_t*)lv_event_get_user_data(e);

  ActionsMenu::getInstance()->toggle();
  if (p->is_sleeping() == true) {
    g->action_wake_up();
    lv_label_set_text(label, _("actions.menu.sleep"));
  } else {
    g->action_sleep();
    lv_label_set_text(label, _("actions.menu.wake_up"));
  }
}

static lv_obj_t* create_row_item(lv_obj_t* parent, Item* item) {
  static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

  static lv_style_t style_label_color;
  lv_style_set_text_color(&style_label_color, lv_color_white());

  lv_obj_t* cont = lv_obj_create(parent);
  lv_obj_remove_style_all(cont);
  lv_obj_set_size(cont, LV_PCT(100), LV_SIZE_CONTENT);
  lv_obj_set_grid_dsc_array(cont, grid_col_dsc, grid_row_dsc);

  lv_obj_t* img = lv_img_create(cont);
  lv_img_set_src(img, item->image);
  lv_obj_set_grid_cell(img, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 2);

  lv_obj_t* label;
  label = lv_label_create(cont);
  lv_label_set_text(label, item->name);
  lv_obj_add_style(label, &style_label_color, 0);
  lv_obj_set_grid_cell(label, LV_GRID_ALIGN_START, 2, 1, LV_GRID_ALIGN_END, 0, 1);

  lv_obj_t* desc_label = lv_label_create(cont);
  lv_label_set_text(desc_label, item->description);
  lv_label_set_long_mode(desc_label, LV_LABEL_LONG_WRAP);
  lv_obj_add_style(desc_label, &style_label_color, 0);
  lv_obj_set_width(label, 100);
  lv_obj_set_grid_cell(desc_label, LV_GRID_ALIGN_START, 2, 1, LV_GRID_ALIGN_END, 1, 1);

  lv_obj_t* btn = lv_btn_create(cont);
  lv_obj_set_grid_cell(btn, LV_GRID_ALIGN_CENTER, 3, 1, LV_GRID_ALIGN_CENTER, 0, 1);
  lv_obj_add_event_cb(btn, use_item_event_handler, LV_EVENT_CLICKED, item);

  lv_obj_t* btn_label = lv_label_create(btn);
  lv_label_set_text(btn_label, _("actions.menu.use"));

  Serial.printf("Create bag item: %s\r\n", item->name);

  return cont;
}
