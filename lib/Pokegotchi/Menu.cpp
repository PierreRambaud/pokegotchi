#include <lvgl.h>
#include <ArduinoJson.h>
#include "lv_i18n.h"
#include "Config.h"
#include "Menu.h"
#include "Utils.h"
#include "Pokemon.h"
#include "Game.h"

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

LV_IMG_DECLARE(bag)
LV_IMG_DECLARE(bag_disabled)
LV_IMG_DECLARE(bag_pressed)
LV_IMG_DECLARE(clean)
LV_IMG_DECLARE(clean_pressed)
LV_IMG_DECLARE(flute)
LV_IMG_DECLARE(flute_pressed)
LV_IMG_DECLARE(options)
LV_IMG_DECLARE(options_pressed)
LV_IMG_DECLARE(play)
LV_IMG_DECLARE(play_disabled)
LV_IMG_DECLARE(play_pressed)
LV_IMG_DECLARE(pokeball)
LV_IMG_DECLARE(pokeball_pressed)
LV_IMG_DECLARE(save)
LV_IMG_DECLARE(save_pressed)
LV_IMG_DECLARE(train)
LV_IMG_DECLARE(train_disabled)
LV_IMG_DECLARE(train_pressed)
LV_IMG_DECLARE(trainercard)
LV_IMG_DECLARE(trainercard_pressed)

static int options_bag_scroll_value = 0;

static lv_obj_t* create_row_item(lv_obj_t* parent, Item* item);

static void clean_event_handler(lv_event_t* e);
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

  lv_obj_t* save_button = lv_menu_button_create(_menu_screen, &save, &save_pressed, _("menu.save"));
  lv_obj_add_event_cb(save_button, save_game_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* pokemon_button = lv_menu_button_create(_menu_screen, &pokeball, &pokeball_pressed, "Pokémon");
  lv_obj_add_event_cb(pokemon_button, open_pokemon_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* options_button = lv_menu_button_create(_menu_screen, &options, &options_pressed, _("menu.options"));
  lv_obj_add_event_cb(options_button, open_options_event_handler, LV_EVENT_CLICKED, NULL);

  lv_obj_t* trainercard_button = lv_menu_button_create(_menu_screen, &trainercard, &trainercard_pressed, _("menu.games"));
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
  lv_obj_set_pos(img, 10, 20);

  lv_obj_t* name = lv_label_create(_sub_menu_screen);
  lv_obj_set_pos(name, 155, 20);
  lv_label_set_text(name, p->get_name());
  lv_obj_add_style(name, &style_default_title, 0);

  lv_obj_t* description = lv_label_create(_sub_menu_screen);
  lv_obj_set_pos(description, 155, 45);
  lv_obj_set_width(description, 155);
  lv_label_set_text(description, p->get_description());
  lv_obj_add_style(description, &style_default_text, 0);
  lv_obj_set_style_text_font(description, &pokemon_font_10, 0);
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
  lv_slider_set_value(brightness_slider, Options::getInstance()->get_brightness(), LV_ANIM_OFF);
  lv_obj_add_event_cb(brightness_slider, slider_set_brightness_event_cb, LV_EVENT_VALUE_CHANGED, brightness_slider_label);
  lv_obj_set_grid_cell(brightness_slider, LV_GRID_ALIGN_CENTER, 1, 2, LV_GRID_ALIGN_CENTER, 3, 1);

  char buf[8];
  lv_snprintf(buf, sizeof(buf), "%d%%", Options::getInstance()->get_brightness());
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

  set_lcd_brightness((int)lv_slider_get_value(slider));
}

/**
 * Save game information
 *
 * @param lv_event_t* e
 */
static void save_game_event_handler(lv_event_t* e) {
  Pokemon* p = Pokemon::getInstance();

  StaticJsonDocument<900> doc;
  doc["options"]["brightness"] = Options::getInstance()->get_brightness();

  JsonObject pokemon = doc.createNestedObject("pokemon");
  pokemon["number"] = p->get_number();
  pokemon["level"] = p->get_level();
  pokemon["life"] = p->get_life();
  pokemon["mood"] = p->get_mood();
  pokemon["hunger"] = p->get_hunger();
  pokemon["sleepiness"] = p->get_sleepiness();
  pokemon["is_sleeping"] = p->is_sleeping();
  pokemon["poos"] = p->get_poos();
  pokemon["pees"] = p->get_pees();

  JsonObject pokemon_time = pokemon.createNestedObject("time");
  pokemon_time["simple_check"] = p->get_last_simple_check_time();
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
  _items[0] = new Item{&object_apple, _("bag.apple.name"), _("bag.apple.description"), new ItemSpecifications{5, 3, 0, 0, 1, 1}};
  _items[1] = new Item{&object_beans, _("bag.beans.name"), _("bag.beans.description"), new ItemSpecifications{2, 5, 0, 0, 1, 0}};
  _items[2] = new Item{&object_berry, _("bag.berry.name"), _("bag.berry.description"), new ItemSpecifications{5, 3, 0, 0, 1, 0}};
  _items[3] = new Item{&object_candy_box, _("bag.candy.name"), _("bag.candy.description"), new ItemSpecifications{20, -5, 0, 0, 1, 0}};
  _items[4] = new Item{&object_cheese, _("bag.cheese.name"), _("bag.cheese.description"), new ItemSpecifications{10, 5, 0, -2, 1, 0}};
  _items[5] = new Item{&object_chicken, _("bag.chicken.name"), _("bag.chicken.description"), new ItemSpecifications{7, 10, 0, -5, 1, 0}};
  _items[6] = new Item{&object_coconut_milk, _("bag.coconut_milk.name"), _("bag.coconut_milk.description"), new ItemSpecifications{0, 5, 0, 0, 1, 3}};
  _items[7] = new Item{&object_frozen_carrots, _("bag.frozen_carrots.name"), _("bag.frozen_carrots.description"), new ItemSpecifications{3, 4, 0, 0, 1, 0}};
  _items[8] = new Item{&object_haricots, _("bag.haricots.name"), _("bag.haricots.description"), new ItemSpecifications{3, 5, 0, -3, 0, 0}};
  _items[9] = new Item{&object_honey, _("bag.honey.name"), _("bag.honey.description"), new ItemSpecifications{10, 1, 0, 0, 0, 1}};
  _items[10] = new Item{&object_milk, _("bag.milk.name"), _("bag.milk.description"), new ItemSpecifications{15, 3, 0, 0, 0, 3}};
  _items[11] = new Item{&object_noodles, _("bag.noodles.name"), _("bag.noodles.description"), new ItemSpecifications{10, 10, 0, -10, 1, 2}};
  _items[12] = new Item{&object_spices, _("bag.spices.name"), _("bag.spices.description"), new ItemSpecifications{5, 5, 0, -5, 0, 0}};
  _items[13] = new Item{&object_sugar_star, _("bag.sugar_star.name"), _("bag.sugar_star.description"), new ItemSpecifications{2, 2, 0, -2, 1, 0}};
  _items[14] = new Item{&object_water, _("bag.water.name"), _("bag.water.description"), new ItemSpecifications{15, 0, 0, 0, 0, 4}};
}

void ActionsMenu::setup(lv_obj_t* screen) {
  Menu::init(screen);

  _bag_button = lv_menu_button_create(_menu_screen, &bag, &bag_pressed, _("actions.menu.bag"));
  lv_imgbtn_set_src(_bag_button, LV_IMGBTN_STATE_DISABLED, NULL, &bag_disabled, NULL);
  lv_obj_add_event_cb(_bag_button, display_bag_items_event_handler, LV_EVENT_CLICKED, NULL);

  _sleep_button = lv_menu_button_create(_menu_screen, &flute, &flute_pressed, Pokemon::getInstance()->is_sleeping() ? _("actions.menu.wake_up") : _("actions.menu.sleep"));
  lv_obj_t* sleep_label = lv_obj_get_child(_sleep_button, -1);
  lv_obj_add_event_cb(_sleep_button, toggle_sleep_event_handler, LV_EVENT_CLICKED, sleep_label);

  _train_button = lv_menu_button_create(_menu_screen, &train, &train_pressed, _("menu.train"));
  lv_imgbtn_set_src(_train_button, LV_IMGBTN_STATE_DISABLED, NULL, &train_disabled, NULL);
  lv_obj_add_event_cb(_train_button, train_event_handler, LV_EVENT_CLICKED, NULL);

  _play_button = lv_menu_button_create(_menu_screen, &play, &play_pressed, _("menu.play"));
  lv_imgbtn_set_src(_play_button, LV_IMGBTN_STATE_DISABLED, NULL, &play_disabled, NULL);
  lv_obj_add_event_cb(_play_button, play_event_handler, LV_EVENT_CLICKED, NULL);

  _clean_button = lv_menu_button_create(_menu_screen, &clean, &clean_pressed, _("actions.menu.clean"));
  lv_obj_add_event_cb(_clean_button, clean_event_handler, LV_EVENT_CLICKED, NULL);

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

  for (Item* item : _items) {
    create_row_item(_sub_menu_screen, item);
  }

  lv_obj_scroll_to_y(_sub_menu_screen, options_bag_scroll_value, LV_ANIM_OFF);
}

static void options_bag_scroll_value_event_cb(lv_event_t* e) {
  lv_obj_t* screen = lv_event_get_target(e);
  options_bag_scroll_value = lv_obj_get_scroll_y(screen);
}

/**
 * Clean up screen
 *
 * @param lv_event_t* e
 */
static void clean_event_handler(lv_event_t* e) {
  ActionsMenu::getInstance()->toggle();
  Game* g = Game::getInstance();
  g->action_clean();
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

  Serial.printf("Create bag item: %s\n", item->name);

  return cont;
}
