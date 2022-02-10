#include <lvgl.h>
#include "lv_i18n.h"
#include "Menu.h"
#include "Utils.h"
#include "Pokemon.h"
#include "Game.h"

LV_IMG_DECLARE(bag)
LV_IMG_DECLARE(bag_pressed)
LV_IMG_DECLARE(flute)
LV_IMG_DECLARE(flute_pressed)
LV_IMG_DECLARE(options)
LV_IMG_DECLARE(options_pressed)
LV_IMG_DECLARE(play)
LV_IMG_DECLARE(play_pressed)
LV_IMG_DECLARE(pokeball)
LV_IMG_DECLARE(pokeball_pressed)
LV_IMG_DECLARE(save)
LV_IMG_DECLARE(save_pressed)
LV_IMG_DECLARE(train)
LV_IMG_DECLARE(train_pressed)
LV_IMG_DECLARE(trainercard)
LV_IMG_DECLARE(trainercard_pressed)
LV_IMG_DECLARE(apple)
LV_IMG_DECLARE(beans)
LV_IMG_DECLARE(berry)
LV_IMG_DECLARE(candy_box)
LV_IMG_DECLARE(cheese)
LV_IMG_DECLARE(chicken)
LV_IMG_DECLARE(coconut_milk)
LV_IMG_DECLARE(frozen_carrots)
LV_IMG_DECLARE(haricots)
LV_IMG_DECLARE(honey)
LV_IMG_DECLARE(milk)
LV_IMG_DECLARE(noodles)
LV_IMG_DECLARE(spices)
LV_IMG_DECLARE(sugar_star)
LV_IMG_DECLARE(water)

static int options_brightness_slider_value = ((300 * 100) / 800);

static void trainercard_event_handler(lv_event_t* e);
static void use_item_event_handler(lv_event_t* e);
static void display_bag_items_event_handler(lv_event_t* e);
static void open_options_event_handler(lv_event_t* e);
static void play_event_handler(lv_event_t* e);
static void train_event_handler(lv_event_t* e);
static void toggle_sleep_event_handler(lv_event_t* e);
static void slider_set_brightness_event_cb(lv_event_t* e);
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
  lv_obj_add_event_cb(options_button, open_options_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* trainercard_button = lv_menu_button_create(_menu_screen, &trainercard, &trainercard_pressed, _("menu.games"));
  lv_obj_set_pos(trainercard_button, 165, 85);
  lv_obj_add_event_cb(trainercard_button, trainercard_event_handler, LV_EVENT_CLICKED, NULL);

  Serial.println("Buttons for menu created");

  toggle();
}

void Menu::close() {
  lv_scr_load(_game_screen);
  lv_obj_add_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);
  Serial.println("Hide Menu");
}
void Menu::open() {
  if (lv_obj_is_valid(_sub_menu_screen)) {
    // Remove sub menu anyway
    lv_obj_del(_sub_menu_screen);
  }

  lv_scr_load(_screen);
  lv_obj_clear_flag(_screen, LV_OBJ_FLAG_HIDDEN);
  lv_obj_clear_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);
  Serial.println("Show Menu");
}

void Menu::toggle() {
  if (lv_obj_has_flag(_screen, LV_OBJ_FLAG_HIDDEN)) {
    open();
  } else {
    close();
  }
}

void Menu::display_options() {
  lv_obj_add_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);

  _sub_menu_screen = create_sub_window(_screen);

  lv_style_init(&style_default_title);
  lv_style_set_text_font(&style_default_title, &pokemon_font_12);
  lv_style_set_text_color(&style_default_title, lv_color_white());

  lv_style_init(&style_default_text);
  lv_style_set_text_color(&style_default_text, lv_color_white());

  static lv_coord_t options_grid_col_dsc[] = {10, LV_GRID_FR(1), LV_GRID_FR(1), 10, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t options_grid_row_dsc[] = {LV_GRID_CONTENT, /*Title*/
                                              5,               /*Separator*/
                                              LV_GRID_CONTENT, /*Box title*/
                                              30,              /*Boxes*/
                                              5,               /*Separator*/
                                              LV_GRID_CONTENT, /*Box title*/
                                              30,              /*Boxes*/
                                              LV_GRID_TEMPLATE_LAST};

  lv_obj_set_grid_dsc_array(_sub_menu_screen, options_grid_col_dsc, options_grid_row_dsc);

  lv_obj_t* options_title = lv_label_create(_sub_menu_screen);
  lv_label_set_text(options_title, _("menu.options.title"));
  lv_obj_add_style(options_title, &style_default_title, 0);
  lv_obj_set_grid_cell(options_title, LV_GRID_ALIGN_START, 1, 2, LV_GRID_ALIGN_CENTER, 0, 1);

  lv_obj_t* brightness_label = lv_label_create(_sub_menu_screen);
  lv_label_set_text(brightness_label, _("menu.options.brightness"));
  lv_obj_set_grid_cell(brightness_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 2, 1);
  lv_obj_add_style(brightness_label, &style_default_text, 0);

  lv_obj_t* brightness_slider_label  = lv_label_create(_sub_menu_screen);
  lv_obj_t* brightness_slider = lv_slider_create(_sub_menu_screen);
  lv_obj_set_width(brightness_slider, LV_PCT(95));
  lv_slider_set_value(brightness_slider, options_brightness_slider_value, LV_ANIM_OFF);
  lv_obj_add_event_cb(brightness_slider, slider_set_brightness_event_cb, LV_EVENT_VALUE_CHANGED, brightness_slider_label);
  lv_obj_set_grid_cell(brightness_slider, LV_GRID_ALIGN_CENTER, 1, 2, LV_GRID_ALIGN_CENTER, 3, 1);

  char buf[8];
  lv_snprintf(buf, sizeof(buf), "%d%%", options_brightness_slider_value);
  lv_label_set_text(brightness_slider_label, buf);
  lv_obj_add_style(brightness_slider_label, &style_default_text, 0);
  lv_obj_set_grid_cell(brightness_slider_label, LV_GRID_ALIGN_CENTER, 1, 2, LV_GRID_ALIGN_CENTER, 4, 1);
}

static void slider_set_brightness_event_cb(lv_event_t* e) {
  lv_obj_t* slider = lv_event_get_target(e);
  char buf[8];
  lv_snprintf(buf, sizeof(buf), "%d%%", (int)lv_slider_get_value(slider));

  lv_obj_t* brightness_slider_label = (lv_obj_t*)lv_event_get_user_data(e);
  lv_label_set_text(brightness_slider_label, buf);
  lv_obj_align_to(brightness_slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

  options_brightness_slider_value = (int)lv_slider_get_value(slider);
  M5.Axp.SetLcdVoltage(2500 + ((options_brightness_slider_value * 800) / 100));
}
/**
 * Open options screen
 *
 * @param lv_event_t* e
 */
static void open_options_event_handler(lv_event_t* e) { Menu::getInstance()->display_options(); }

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

  toggle();
}

void ActionsMenu::display_bag() {
  lv_obj_add_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);

  _sub_menu_screen = create_sub_window(_screen);

  lv_obj_set_flex_flow(_sub_menu_screen, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_grow(_sub_menu_screen, 1);
  lv_obj_add_flag(_sub_menu_screen, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);

  for (Item item : _items) {
    create_row_item(_sub_menu_screen, &item);
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

  lv_style_init(&style_default_text);
  lv_style_set_text_color(&style_default_text, lv_color_white());

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

  Serial.printf("Create bag item: %s\r\n", item->name);

  return cont;
}
