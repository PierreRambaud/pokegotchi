#include <lvgl.h>
#include "lv_i18n.h"
#include "Menu.h"
#include "Utils.h"
#include "Pokemon.h"
#include "Game.h"
#include "assets/menu/bag.c"
#include "assets/menu/bag_pressed.c"
#include "assets/menu/flute.c"
#include "assets/menu/flute_pressed.c"
#include "assets/menu/options.c"
#include "assets/menu/options_pressed.c"
#include "assets/menu/play.c"
#include "assets/menu/play_pressed.c"
#include "assets/menu/pokeball.c"
#include "assets/menu/pokeball_pressed.c"
#include "assets/menu/save.c"
#include "assets/menu/save_pressed.c"
#include "assets/menu/train.c"
#include "assets/menu/train_pressed.c"
#include "assets/menu/trainercard.c"
#include "assets/menu/trainercard_pressed.c"
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

static void trainercard_event_handler(lv_event_t* e);
static void use_item_event_handler(lv_event_t* e);
static void display_bag_items_event_handler(lv_event_t* e);
static void play_event_handler(lv_event_t* e);
static void train_event_handler(lv_event_t* e);
static void toggle_sleep_event_handler(lv_event_t* e);
static lv_obj_t* create_row_item(lv_obj_t* parent, Item* item);

ActionsMenu* ActionsMenu::instance = nullptr;
Menu* Menu::instance = nullptr;

Menu::Menu() {}

void Menu::setup(lv_obj_t* screen) {
  Menu::init(screen);

  lv_obj_t* save_button = lv_menu_button_create(_menu_screen, &save, &save_pressed, _("menu.save"));
  lv_obj_set_pos(save_button, 7, 25);

  lv_obj_t* pokemon_button = lv_menu_button_create(_menu_screen, &pokeball, &pokeball_pressed, "Pokémon");
  lv_obj_set_pos(pokemon_button, 165, 25);

  lv_obj_t* options_button = lv_menu_button_create(_menu_screen, &options, &options_pressed, _("menu.options"));
  lv_obj_set_pos(options_button, 7, 85);

  lv_obj_t* trainercard_button = lv_menu_button_create(_menu_screen, &trainercard, &trainercard_pressed, _("menu.games"));
  lv_obj_set_pos(trainercard_button, 165, 85);
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

/**
 * Display trainer card
 *
 * @param lv_event_t* e
 */
static void trainercard_event_handler(lv_event_t* e) {}

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
  Menu::init(screen);

  lv_obj_t* bag_button = lv_menu_button_create(_menu_screen, &bag, &bag_pressed, _("actions.menu.bag"));
  lv_obj_set_pos(bag_button, 7, 25);
  lv_obj_add_event_cb(bag_button, display_bag_items_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* sleep_button = lv_menu_button_create(_menu_screen, &flute, &flute_pressed, _("actions.menu.sleep"));
  lv_obj_set_pos(sleep_button, 165, 25);
  lv_obj_t* sleep_label = lv_obj_get_child(sleep_button, -1);
  lv_obj_add_event_cb(sleep_button, toggle_sleep_event_handler, LV_EVENT_CLICKED, sleep_label);

  lv_obj_t* train_button = lv_menu_button_create(_menu_screen, &train, &train_pressed, _("menu.train"));
  lv_obj_set_pos(train_button, 7, 85);
  lv_obj_add_event_cb(train_button, train_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* play_button = lv_menu_button_create(_menu_screen, &play, &play_pressed, _("menu.play"));
  lv_obj_set_pos(play_button, 165, 85);
  lv_obj_add_event_cb(play_button, play_event_handler, LV_EVENT_CLICKED, NULL);

  Serial.println("Buttons for actions menu created");

  _bag_screen = create_sub_window(_screen);

  lv_obj_set_flex_flow(_bag_screen, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_grow(_bag_screen, 1);
  lv_obj_add_flag(_bag_screen, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);

  for (Item item : _items) {
    create_row_item(_bag_screen, &item);
  }

  toggle();
}

void ActionsMenu::display_bag() {
  lv_obj_clear_flag(_bag_screen, LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);
}

void ActionsMenu::toggle() {
  if (lv_obj_has_flag(_screen, LV_OBJ_FLAG_HIDDEN)) {
    lv_scr_load(_screen);
    lv_obj_clear_flag(_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);
    Serial.println("Show ActionsMenu");
  } else {
    lv_scr_load(_game_screen);
    lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(_bag_screen, LV_OBJ_FLAG_HIDDEN);
    Serial.println("Hide ActionsMenu");
  }
}

/**
 * Use bag item
 *
 * @param lv_event_t* e
 */
static void use_item_event_handler(lv_event_t* e) {
  Item* item = (Item*)lv_event_get_user_data(e);

  ActionsMenu::getInstance()->toggle();
  Game* g = Game::getInstance();
  g->action_eat(item);
}

/**
 * Display bag items
 *
 * @param lv_event_t* e
 */
static void display_bag_items_event_handler(lv_event_t* e) { ActionsMenu::getInstance()->display_bag(); }

/**
 * Train pokemeon
 *
 * @param lv_event_t* e
 */
static void train_event_handler(lv_event_t* e) {
  Game* g = Game::getInstance();

  ActionsMenu::getInstance()->toggle();
  g->action_train();
}

/**
 * Play with pokemeon
 *
 * @param lv_event_t* e
 */
static void play_event_handler(lv_event_t* e) {
  Game* g = Game::getInstance();

  ActionsMenu::getInstance()->toggle();
  g->action_play();
}

/**
 * Toggle sleep event
 *
 * @param lv_event_t* e
 */
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

/**
 * Create bag item row
 *
 * @param lv_obj_t* parent The parent screen
 * @param Item* item The item to display
 *
 * @return lv_obj_t* the row line
 */
static lv_obj_t* create_row_item(lv_obj_t* parent, Item* item) {
  static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

  static lv_style_t style_label_color;
  lv_style_set_text_color(&style_label_color, lv_color_white());

  lv_obj_t* cont = lv_obj_create(parent);
  lv_obj_set_size(cont, LV_PCT(100), LV_SIZE_CONTENT);
  lv_obj_set_style_bg_opa(cont, LV_OPA_TRANSP, 0);
  lv_obj_set_style_border_side(cont, LV_BORDER_SIDE_BOTTOM, 0);
  lv_obj_set_style_radius(cont, 0, 0);
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
  lv_obj_add_style(desc_label, &style_label_color, 0);
  lv_obj_set_grid_cell(desc_label, LV_GRID_ALIGN_STRETCH, 2, 1, LV_GRID_ALIGN_END, 1, 1);

  lv_obj_t* btn = lv_btn_create(cont);
  lv_obj_set_grid_cell(btn, LV_GRID_ALIGN_CENTER, 3, 1, LV_GRID_ALIGN_CENTER, 0, 2);
  lv_obj_add_event_cb(btn, use_item_event_handler, LV_EVENT_CLICKED, item);

  lv_obj_t* btn_label = lv_label_create(btn);
  lv_label_set_text(btn_label, _("actions.menu.use"));

  Serial.printf("Create bag item: %s\r\n", item->name);

  return cont;
}
