#include "lvgl.h"
#include "ArduinoJson.h"
#include "lv_i18n.h"
#include "Config.h"
#include "ActionsMenu.h"
#include "Utils.h"
#include "Pokemon.h"
#include "Game.h"

using namespace Pokegotchi;

LV_IMG_DECLARE(object_apple)
LV_IMG_DECLARE(object_candy_box)
LV_IMG_DECLARE(object_coconut_milk)
LV_IMG_DECLARE(object_honey)
LV_IMG_DECLARE(object_spices)
LV_IMG_DECLARE(object_beans)
LV_IMG_DECLARE(object_cheese)
LV_IMG_DECLARE(object_frozen_carrots)
LV_IMG_DECLARE(object_milk)
LV_IMG_DECLARE(object_sugar_star)
LV_IMG_DECLARE(object_berry)
LV_IMG_DECLARE(object_chicken)
LV_IMG_DECLARE(object_haricots)
LV_IMG_DECLARE(object_noodles)
LV_IMG_DECLARE(object_water)

LV_IMG_DECLARE(menu_bag)
LV_IMG_DECLARE(menu_bag_disabled)
LV_IMG_DECLARE(menu_bag_pressed)
LV_IMG_DECLARE(menu_clean)
LV_IMG_DECLARE(menu_clean_pressed)
LV_IMG_DECLARE(menu_flute)
LV_IMG_DECLARE(menu_flute_pressed)
LV_IMG_DECLARE(menu_heal)
LV_IMG_DECLARE(menu_heal_disabled)
LV_IMG_DECLARE(menu_heal_pressed)
LV_IMG_DECLARE(menu_play)
LV_IMG_DECLARE(menu_play_disabled)
LV_IMG_DECLARE(menu_play_pressed)
LV_IMG_DECLARE(menu_pokeball)
LV_IMG_DECLARE(menu_pokeball_pressed)
LV_IMG_DECLARE(menu_train)
LV_IMG_DECLARE(menu_train_disabled)
LV_IMG_DECLARE(menu_train_pressed)

static int options_bag_scroll_value = 0;

static lv_obj_t* create_row_item(lv_obj_t*, BagItem*);

static void clean_event_handler(lv_event_t*);
static void heal_event_handler(lv_event_t*);
static void display_bag_items_event_handler(lv_event_t*);
static void options_bag_scroll_value_event_cb(lv_event_t*);
static void play_event_handler(lv_event_t*);
static void toggle_sleep_event_handler(lv_event_t*);
static void train_event_handler(lv_event_t*);
static void use_item_event_handler(lv_event_t*);

ActionsMenu* ActionsMenu::_instance = nullptr;

void set_heal_menu_text(lv_obj_t* heal_label) { lv_label_set_text_fmt(heal_label, "%s (%d)", _("actions.menu.heal"), Pokemon::getInstance()->get_potions()); }

ActionsMenu::ActionsMenu(Menu* menu) {
  _menu = menu;

  _items[0] = new BagItem{&object_apple, _("bag.apple.name"), _("bag.apple.description"), new BagItemSpecifications{5, 3, 0, 0, 1, 1}};
  _items[1] = new BagItem{&object_beans, _("bag.beans.name"), _("bag.beans.description"), new BagItemSpecifications{2, 5, 0, 0, 1, 0}};
  _items[2] = new BagItem{&object_berry, _("bag.berry.name"), _("bag.berry.description"), new BagItemSpecifications{5, 3, 0, 0, 1, 0}};
  _items[3] = new BagItem{&object_candy_box, _("bag.candy.name"), _("bag.candy.description"), new BagItemSpecifications{20, -5, 0, 0, 1, 0}};
  _items[4] = new BagItem{&object_cheese, _("bag.cheese.name"), _("bag.cheese.description"), new BagItemSpecifications{10, 5, 0, -2, 1, 0}};
  _items[5] = new BagItem{&object_chicken, _("bag.chicken.name"), _("bag.chicken.description"), new BagItemSpecifications{7, 10, 0, -5, 1, 0}};
  _items[6] = new BagItem{&object_coconut_milk, _("bag.coconut_milk.name"), _("bag.coconut_milk.description"), new BagItemSpecifications{0, 5, 0, 0, 1, 3}};
  _items[7] = new BagItem{&object_frozen_carrots, _("bag.frozen_carrots.name"), _("bag.frozen_carrots.description"), new BagItemSpecifications{3, 4, 0, 0, 1, 0}};
  _items[8] = new BagItem{&object_haricots, _("bag.haricots.name"), _("bag.haricots.description"), new BagItemSpecifications{3, 5, 0, -3, 0, 0}};
  _items[9] = new BagItem{&object_honey, _("bag.honey.name"), _("bag.honey.description"), new BagItemSpecifications{10, 1, 0, 0, 0, 1}};
  _items[10] = new BagItem{&object_milk, _("bag.milk.name"), _("bag.milk.description"), new BagItemSpecifications{15, 3, 0, 0, 0, 3}};
  _items[11] = new BagItem{&object_noodles, _("bag.noodles.name"), _("bag.noodles.description"), new BagItemSpecifications{10, 10, 0, -10, 1, 2}};
  _items[12] = new BagItem{&object_spices, _("bag.spices.name"), _("bag.spices.description"), new BagItemSpecifications{5, 5, 0, -5, 0, 0}};
  _items[13] = new BagItem{&object_sugar_star, _("bag.sugar_star.name"), _("bag.sugar_star.description"), new BagItemSpecifications{2, 2, 0, -2, 1, 0}};
  _items[14] = new BagItem{&object_water, _("bag.water.name"), _("bag.water.description"), new BagItemSpecifications{15, 0, 0, 0, 0, 4}};

  _bag_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_bag, &menu_bag_pressed, _("actions.menu.bag"));
  lv_imagebutton_set_src(_bag_button, LV_IMAGEBUTTON_STATE_DISABLED, NULL, &menu_bag_disabled, NULL);
  lv_obj_add_event_cb(_bag_button, display_bag_items_event_handler, LV_EVENT_CLICKED, NULL);

  _sleep_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_flute, &menu_flute_pressed, Pokemon::getInstance()->is_sleeping() ? _("actions.menu.wake_up") : _("actions.menu.sleep"));
  lv_obj_t* sleep_label = lv_obj_get_child(_sleep_button, -1);
  lv_obj_add_event_cb(_sleep_button, toggle_sleep_event_handler, LV_EVENT_CLICKED, sleep_label);

  _train_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_train, &menu_train_pressed, _("menu.train"));
  lv_imagebutton_set_src(_train_button, LV_IMAGEBUTTON_STATE_DISABLED, NULL, &menu_train_disabled, NULL);
  lv_obj_add_event_cb(_train_button, train_event_handler, LV_EVENT_CLICKED, NULL);

  _play_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_play, &menu_play_pressed, _("menu.play"));
  lv_imagebutton_set_src(_play_button, LV_IMAGEBUTTON_STATE_DISABLED, NULL, &menu_play_disabled, NULL);
  lv_obj_add_event_cb(_play_button, play_event_handler, LV_EVENT_CLICKED, NULL);

  _clean_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_clean, &menu_clean_pressed, _("actions.menu.clean"));
  lv_obj_add_event_cb(_clean_button, clean_event_handler, LV_EVENT_CLICKED, NULL);

  _heal_button = lv_menu_button_create(_menu->get_menu_screen(), &menu_heal, &menu_heal_pressed, _("actions.menu.heal"));
  set_heal_menu_text(lv_obj_get_child(_heal_button, -1));
  lv_imagebutton_set_src(_heal_button, LV_IMAGEBUTTON_STATE_DISABLED, NULL, &menu_heal_disabled, NULL);
  lv_obj_add_event_cb(_heal_button, heal_event_handler, LV_EVENT_CLICKED, NULL);

  serial_printf("ActionsMenu", "Buttons for actions menu created");

  toggle();
}

/**
 * Change the state of buttons depending on pokemon status
 */
void ActionsMenu::open() {
  Pokemon* p = Pokemon::getInstance();
  if (p->is_sleeping()) {
    lv_imagebutton_set_state(_bag_button, LV_IMAGEBUTTON_STATE_DISABLED);
    lv_imagebutton_set_state(_train_button, LV_IMAGEBUTTON_STATE_DISABLED);
    lv_imagebutton_set_state(_play_button, LV_IMAGEBUTTON_STATE_DISABLED);
  } else {
    lv_obj_remove_state(_bag_button, LV_STATE_DISABLED);
    lv_obj_remove_state(_train_button, LV_STATE_DISABLED);
    lv_obj_remove_state(_play_button, LV_STATE_DISABLED);
  }

  if (p->get_potions() == 0 or p->is_sleeping()) {
    lv_imagebutton_set_state(_heal_button, LV_IMAGEBUTTON_STATE_DISABLED);
  } else {
    lv_obj_remove_state(_heal_button, LV_STATE_DISABLED);
  }

  set_heal_menu_text(lv_obj_get_child(_heal_button, -1));

  _menu->open();
}

void ActionsMenu::display_bag() {
  lv_obj_add_flag(_menu->get_menu_screen(), LV_OBJ_FLAG_HIDDEN);

  _menu_child_screen = create_child_screen(_menu->get_screen());

  lv_obj_set_flex_flow(_menu_child_screen, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_grow(_menu_child_screen, 1);
  lv_obj_add_flag(_menu_child_screen, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
  lv_obj_set_scroll_dir(_menu_child_screen, LV_DIR_VER);
  lv_obj_set_scroll_snap_y(_menu_child_screen, LV_SCROLL_SNAP_START);
  lv_obj_add_flag(_menu_child_screen, LV_OBJ_FLAG_SCROLL_ONE);
  lv_obj_add_event_cb(_menu_child_screen, options_bag_scroll_value_event_cb, LV_EVENT_SCROLL, NULL);

  for (BagItem* item : _items) {
    create_row_item(_menu_child_screen, item);
  }

  lv_obj_scroll_to_y(_menu_child_screen, options_bag_scroll_value, LV_ANIM_OFF);
}

static void options_bag_scroll_value_event_cb(lv_event_t* e) {
  lv_obj_t* screen = lv_event_get_target_obj(e);
  options_bag_scroll_value = lv_obj_get_scroll_y(screen);
}

/**
 * Clean up screen
 *
 * @param lv_event_t* e
 */
static void clean_event_handler(lv_event_t* e) {
  LV_UNUSED(e);
  ActionsMenu::getInstance()->toggle();
  Game* g = Game::getInstance();
  g->action_clean();
}

/**
 * Clean up screen
 *
 * @param lv_event_t* e
 */
static void heal_event_handler(lv_event_t* e) {
  LV_UNUSED(e);
  ActionsMenu::getInstance()->toggle();
  Game* g = Game::getInstance();
  g->action_heal();
}

/**
 * Use bag item
 *
 * @param lv_event_t* e
 */
static void use_item_event_handler(lv_event_t* e) {
  BagItem* item = (BagItem*)lv_event_get_user_data(e);

  ActionsMenu::getInstance()->toggle();
  Game* g = Game::getInstance();
  g->action_eat(item);
}

/**
 * Display bag items
 *
 * @param lv_event_t* e
 */
static void display_bag_items_event_handler(lv_event_t* e) {
  LV_UNUSED(e);
  ActionsMenu::getInstance()->display_bag();
}

/**
 * Train pokemeon
 *
 * @param lv_event_t* e
 */
static void train_event_handler(lv_event_t* e) {
  LV_UNUSED(e);
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
  LV_UNUSED(e);
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
 * @param BagItem* item The item to display
 *
 * @return lv_obj_t* the row line
 */
static lv_obj_t* create_row_item(lv_obj_t* parent, BagItem* item) {
  static int32_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
  static int32_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

  lv_style_init(&style_default_text);
  lv_style_set_text_color(&style_default_text, lv_color_white());

  lv_obj_t* cont = lv_obj_create(parent);
  lv_obj_set_size(cont, LV_PCT(100), LV_SIZE_CONTENT);
  lv_obj_set_style_bg_opa(cont, LV_OPA_TRANSP, 0);
  lv_obj_set_style_border_side(cont, LV_BORDER_SIDE_BOTTOM, 0);
  lv_obj_set_style_radius(cont, 0, 0);
  lv_obj_set_grid_dsc_array(cont, grid_col_dsc, grid_row_dsc);

  lv_obj_t* img = lv_image_create(cont);
  lv_image_set_src(img, item->image);
  lv_obj_set_grid_cell(img, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 2);

  lv_obj_t* label;
  label = lv_label_create(cont);
  lv_label_set_text(label, item->name);
  lv_obj_add_style(label, &style_default_text, 0);
  lv_obj_set_grid_cell(label, LV_GRID_ALIGN_START, 2, 1, LV_GRID_ALIGN_END, 0, 1);

  lv_obj_t* desc_label = lv_label_create(cont);
  lv_label_set_text(desc_label, item->description);
  lv_obj_add_style(desc_label, &style_default_text, 0);
  lv_obj_set_grid_cell(desc_label, LV_GRID_ALIGN_STRETCH, 2, 1, LV_GRID_ALIGN_END, 1, 1);

  lv_obj_t* btn = lv_btn_create(cont);
  lv_obj_set_grid_cell(btn, LV_GRID_ALIGN_CENTER, 3, 1, LV_GRID_ALIGN_CENTER, 0, 2);
  lv_obj_add_event_cb(btn, use_item_event_handler, LV_EVENT_CLICKED, item);

  lv_obj_t* btn_label = lv_label_create(btn);
  lv_label_set_text(btn_label, _("actions.menu.use"));

  serial_printf("ActionsMenu", "Create bag item: %s", item->name);

  return cont;
}
