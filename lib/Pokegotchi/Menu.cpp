#include <lvgl.h>
#include <ArduinoJson.h>
#include "lv_i18n.h"
#include "Config.h"
#include "Menu.h"
#include "Utils.h"
#include "Pokemon.h"
#include "Game.h"

static int options_brightness_slider_value = ((300 * 100) / 800);
static int options_bag_scroll_value = 0;

static lv_obj_t* create_row_item(lv_obj_t* parent, Item* item);

static void display_bag_items_event_handler(lv_event_t* e);
static void open_options_event_handler(lv_event_t* e);
static void open_pokemon_event_handler(lv_event_t* e);
static void options_bag_scroll_value_event_cb(lv_event_t* e);
static void play_event_handler(lv_event_t* e);
static void save_game_event_handler(lv_event_t* e);
static void slider_set_brightness_event_cb(lv_event_t* e);
static void toggle_sleep_event_handler(lv_event_t* e);
static void train_event_handler(lv_event_t* e);
static void trainercard_event_handler(lv_event_t* e);
static void use_item_event_handler(lv_event_t* e);

ActionsMenu* ActionsMenu::instance = nullptr;
Menu* Menu::instance = nullptr;

Menu::Menu() {}

void Menu::setup(lv_obj_t* screen) {
  Menu::init(screen);

  lv_obj_t* save_button = lv_menu_button_create(_menu_screen, "L:menu/save.png", "L:menu/save_pressed.png", _("menu.save"));
  lv_obj_add_event_cb(save_button, save_game_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* pokemon_button = lv_menu_button_create(_menu_screen, "L:menu/pokeball.png", "L:menu/pokeball_pressed.png", "Pokémon");
  lv_obj_add_event_cb(pokemon_button, open_pokemon_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* options_button = lv_menu_button_create(_menu_screen, "L:menu/options.png", "L:menu/options_pressed.png", _("menu.options"));
  lv_obj_add_event_cb(options_button, open_options_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* trainercard_button = lv_menu_button_create(_menu_screen, "L:menu/trainercard.png", "L:menu/trainercard_pressed.png", _("menu.games"));
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

void Menu::display_pokemon() {
  lv_obj_add_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);

  _sub_menu_screen = create_sub_window(_screen);
  Pokemon* p = Pokemon::getInstance();

  lv_style_init(&style_default_title);
  lv_style_set_text_font(&style_default_title, &pokemon_font_12);
  lv_style_set_text_color(&style_default_title, lv_color_white());

  lv_style_init(&style_default_text);
  lv_style_set_text_color(&style_default_text, lv_color_white());

  lv_obj_t* img = lv_img_create(_sub_menu_screen);
  lv_img_set_src(img, p->get_avatar());
  lv_obj_set_pos(img, 25, 25);

  lv_obj_t* name = lv_label_create(_sub_menu_screen);
  lv_obj_set_pos(name, 175, 25);
  lv_label_set_text(name, p->get_name());
  lv_obj_add_style(name, &style_default_title, 0);

  lv_obj_t* description = lv_label_create(_sub_menu_screen);
  lv_obj_set_pos(description, 175, 50);
  lv_obj_set_width(description, 125);
  lv_label_set_text(description, p->get_description());
  lv_obj_add_style(description, &style_default_text, 0);
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

  lv_obj_t* brightness_slider_label = lv_label_create(_sub_menu_screen);
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
  set_lcd_brightness(options_brightness_slider_value);
}

/**
 * Save game information
 *
 * @param lv_event_t* e
 */
static void save_game_event_handler(lv_event_t* e) {
  Pokemon* p = Pokemon::getInstance();

  StaticJsonDocument<900> doc;
  doc["options"]["brightness"] = options_brightness_slider_value;

  JsonObject pokemon = doc.createNestedObject("pokemon");
  pokemon["number"] = p->get_number();
  pokemon["level"] = p->get_level();
  pokemon["life"] = p->get_life();
  pokemon["mood"] = p->get_mood();
  pokemon["hunger"] = p->get_hunger();
  pokemon["sleepiness"] = p->get_sleepiness();
  pokemon["is_sleeping"] = p->is_sleeping();

  JsonObject pokemon_time = pokemon.createNestedObject("time");
  pokemon_time["boredom"] = p->get_last_boredom_time();
  pokemon_time["hunger"] = p->get_last_hunger_time();
  pokemon_time["sleep"] = p->get_last_sleep_time();
  pokemon_time["without_sleep"] = p->get_last_without_sleep_time();

  if (sd_begin() == false) {
    display_alert("", _("sd.card.not_found"));
    return;
  }

  File file = SD.open(Config::getInstance()->save_file_path, FILE_WRITE);
  if (!file) {
    display_alert("", _("game.save.failed"));
  } else {
    serializeJson(doc, Serial);
    serializeJson(doc, file);
    file.close();

    display_alert("", _("game.save.success"));
  }

  SD.end();
}

/**
 * Open options screen
 *
 * @param lv_event_t* e
 */
static void open_options_event_handler(lv_event_t* e) { Menu::getInstance()->display_options(); }

/**
 * Open pokemon screen
 *
 * @param lv_event_t* e
 */
static void open_pokemon_event_handler(lv_event_t* e) { Menu::getInstance()->display_pokemon(); }

/**
 * Display trainer card
 *
 * @param lv_event_t* e
 */
static void trainercard_event_handler(lv_event_t* e) {}

ActionsMenu::ActionsMenu() {
  _items[0] = Item{"L:menu/bag/apple.png", _("bag.apple.name"), _("bag.apple.description")};
  _items[1] = Item{"L:menu/bag/beans.png", _("bag.beans.name"), _("bag.beans.description")};
  _items[2] = Item{"L:menu/bag/berry.png", _("bag.berry.name"), _("bag.berry.description")};
  _items[3] = Item{"L:menu/bag/candy_box.png", _("bag.candy.name"), _("bag.candy.description")};
  _items[4] = Item{"L:menu/bag/cheese.png", _("bag.cheese.name"), _("bag.cheese.description")};
  _items[5] = Item{"L:menu/bag/chicken.png", _("bag.chicken.name"), _("bag.chicken.description")};
  _items[6] = Item{"L:menu/bag/coconut_milk.png", _("bag.coconut_milk.name"), _("bag.coconut_milk.description")};
  _items[7] = Item{"L:menu/bag/frozen_carrots.png", _("bag.frozen_carrots.name"), _("bag.frozen_carrots.description")};
  _items[8] = Item{"L:menu/bag/haricots.png", _("bag.haricots.name"), _("bag.haricots.description")};
  _items[9] = Item{"L:menu/bag/honey.png", _("bag.honey.name"), _("bag.honey.description")};
  _items[10] = Item{"L:menu/bag/milk.png", _("bag.milk.name"), _("bag.milk.description")};
  _items[11] = Item{"L:menu/bag/noodles.png", _("bag.noodles.name"), _("bag.noodles.description")};
  _items[12] = Item{"L:menu/bag/spices.png", _("bag.spices.name"), _("bag.spices.description")};
  _items[13] = Item{"L:menu/bag/sugar_star.png", _("bag.sugar_star.name"), _("bag.sugar_star.description")};
  _items[14] = Item{"L:menu/bag/water.png", _("bag.water.name"), _("bag.water.description")};
}

void ActionsMenu::setup(lv_obj_t* screen) {
  Menu::init(screen);

  _bag_button = lv_menu_button_create(_menu_screen, "L:menu/bag.png", "L:menu/bag_pressed.png", _("actions.menu.bag"));
  lv_imgbtn_set_src(_bag_button, LV_IMGBTN_STATE_DISABLED, NULL, "L:menu/bag_disabled.png", NULL);
  lv_obj_add_event_cb(_bag_button, display_bag_items_event_handler, LV_EVENT_CLICKED, NULL);

  _sleep_button = lv_menu_button_create(_menu_screen, "L:menu/flute.png", "L:menu/flute_pressed.png", _("actions.menu.sleep"));
  lv_obj_t* sleep_label = lv_obj_get_child(_sleep_button, -1);
  lv_obj_add_event_cb(_sleep_button, toggle_sleep_event_handler, LV_EVENT_CLICKED, sleep_label);

  _train_button = lv_menu_button_create(_menu_screen, "L:menu/train.png", "L:menu/train_pressed.png", _("menu.train"));
  lv_imgbtn_set_src(_train_button, LV_IMGBTN_STATE_DISABLED, NULL, "L:menu/train_disabled.png", NULL);
  lv_obj_add_event_cb(_train_button, train_event_handler, LV_EVENT_CLICKED, NULL);

  _play_button = lv_menu_button_create(_menu_screen, "L:menu/play.pgn", "L:menu/play_pressed.png", _("menu.play"));
  lv_imgbtn_set_src(_play_button, LV_IMGBTN_STATE_DISABLED, NULL, "L:menu/play_disabled.png", NULL);
  lv_obj_add_event_cb(_play_button, play_event_handler, LV_EVENT_CLICKED, NULL);

  Serial.println("Buttons for actions menu created");

  toggle();
}

/**
 * Change the state of buttons depending on pokemon status
 */
void ActionsMenu::open() {
  Pokemon* p = Pokemon::getInstance();
  Serial.println("disable buttons");
  if (p->is_sleeping()) {
    lv_imgbtn_set_state(_bag_button, LV_IMGBTN_STATE_DISABLED);
    lv_imgbtn_set_state(_train_button, LV_IMGBTN_STATE_DISABLED);
    lv_imgbtn_set_state(_play_button, LV_IMGBTN_STATE_DISABLED);
  } else {
    lv_obj_clear_state(_bag_button, LV_STATE_DISABLED);
    lv_obj_clear_state(_train_button, LV_STATE_DISABLED);
    lv_obj_clear_state(_play_button, LV_STATE_DISABLED);
  }

  Menu::open();
}

void ActionsMenu::display_bag() {
  lv_obj_add_flag(_menu_screen, LV_OBJ_FLAG_HIDDEN);

  _sub_menu_screen = create_sub_window(_screen);

  lv_obj_set_flex_flow(_sub_menu_screen, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_grow(_sub_menu_screen, 1);
  lv_obj_add_flag(_sub_menu_screen, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
  lv_obj_set_scroll_dir(_sub_menu_screen, LV_DIR_VER);
  lv_obj_set_scroll_snap_y(_sub_menu_screen, LV_SCROLL_SNAP_START);
  lv_obj_add_flag(_sub_menu_screen, LV_OBJ_FLAG_SCROLL_ONE);
  lv_obj_add_event_cb(_sub_menu_screen, options_bag_scroll_value_event_cb, LV_EVENT_SCROLL, NULL);

  for (Item item : _items) {
    create_row_item(_sub_menu_screen, &item);
  }

  lv_obj_scroll_to_y(_sub_menu_screen, options_bag_scroll_value, LV_ANIM_OFF);
}

static void options_bag_scroll_value_event_cb(lv_event_t* e) {
  lv_obj_t* screen = lv_event_get_target(e);
  options_bag_scroll_value = lv_obj_get_scroll_y(screen);
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
