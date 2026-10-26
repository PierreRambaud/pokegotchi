#include "lvgl.h"
#include "lv_i18n.h"
#include "Game.h"
#include "GameMenu.h"
#include "Utils.h"
#include "game_anim.h"
#include "storage_hal.h"

LV_IMG_DECLARE(game_pee)
LV_IMG_DECLARE(game_poo)
LV_IMG_DECLARE(game_clean)
LV_IMG_DECLARE(game_egg)

LV_IMG_DECLARE(emote_heart)
LV_IMG_DECLARE(emote_exclamation)
LV_IMG_DECLARE(emote_note)
LV_IMG_DECLARE(emote_anger)
LV_IMG_DECLARE(emote_sweat)
LV_IMG_DECLARE(emote_zzz)
LV_IMG_DECLARE(emote_question)
LV_IMG_DECLARE(emote_sick)

using namespace Pokegotchi;

// Vertical offset of the Pokemon from the screen center: it stands on the ground
#define POKEMON_GROUND_Y 80
#define POKEMON_MAX_X 110
#define EGG_GROUND_Y 70

static void end_game_msg_box_event_handler(lv_event_t* e);
static void drag_clean_event_handler(lv_event_t* e);
static bool check_object_intersect(lv_obj_t* a, lv_obj_t* b);
static void anim_rotation_callback(void* obj, int32_t value) { lv_image_set_rotation((lv_obj_t*)obj, value); }

Game* Game::_instance = nullptr;

Game::Game(poke_config_t* global_config, lv_obj_t* main_screen, Pokemon* p, poke_options_t* game_options) {
  _options = game_options;
  _initialize(global_config, main_screen, p);

  set_lcd_brightness((int32_t)_options->brightness);
}

Pokegotchi::Game::~Game() {
  serial_printf("Game", "Destructor called, cleaning up LVGL objects");

  if (_evolution_timer != nullptr) {
    lv_timer_delete(_evolution_timer);
    _evolution_timer = nullptr;
  }

  // Poos, pees, the Pokemon... are all children of the screen
  if (_screen != nullptr) {
    lv_obj_delete(_screen);
    _screen = nullptr;
  }
  _poos.clear();
  _pees.clear();

  // Their LVGL objects are deleted with the main screen by the runner
  delete ActionsMenu::getInstance();
  ActionsMenu::setInstance(nullptr);
  delete GameMenu::getInstance();
  GameMenu::setInstance(nullptr);
}

Game::Game(poke_config_t* global_config, lv_obj_t* main_screen, Pokemon* p) {
  _options = new poke_options_t{OPTIONS_BRIGHTNESS_DEFAULT, OPTIONS_BALL_DEFAULT, NULL};
  _initialize(global_config, main_screen, p);
}

void Game::_initialize(poke_config_t* global_config, lv_obj_t* main_screen, Pokemon* p) {
  _config = global_config;
  _main_screen = main_screen;
  _screen = create_screen(_main_screen);

  _background = lv_image_create(_screen);
  lv_obj_set_pos(_background, 0, 0);

  _mood_bar = lv_game_bar_create(_screen, LV_PALETTE_GREEN, _("bar.mood"), 10, 25, MAX_MOOD);
  lv_bar_set_value(_mood_bar, 0, LV_ANIM_ON);

  _life_bar = lv_game_bar_create(_screen, LV_PALETTE_RED, _("bar.life"), 10, 70, MAX_LIFE);
  lv_bar_set_value(_life_bar, 0, LV_ANIM_ON);

  _sleepiness_bar = lv_game_bar_create(_screen, LV_PALETTE_BLUE, _("bar.sleepiness"), 185, 25, MAX_SLEEPINESS);
  lv_bar_set_value(_sleepiness_bar, 0, LV_ANIM_ON);

  _hunger_bar = lv_game_bar_create(_screen, LV_PALETTE_YELLOW, _("bar.hunger"), 185, 70, MAX_HUNGER);
  lv_bar_set_value(_hunger_bar, 0, LV_ANIM_ON);

  _clock_label = lv_label_create(_screen);
  lv_obj_add_style(_clock_label, &style_game_label, 0);
  lv_obj_align(_clock_label, LV_ALIGN_TOP_MID, 0, 6);
  lv_label_set_text(_clock_label, "");

  _level_indic = lv_label_create(_screen);
  lv_obj_add_style(_level_indic, &style_game_label, 0);
  lv_obj_align(_level_indic, LV_ALIGN_TOP_MID, 0, 24);
  lv_label_set_text(_level_indic, "");

  _pokemon_image = lv_gif_create(_screen);
  lv_gif_set_src(_pokemon_image, p->get_image());
  lv_obj_align(_pokemon_image, LV_ALIGN_CENTER, 0, POKEMON_GROUND_Y);
  lv_obj_add_flag(_pokemon_image, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(_pokemon_image, _pokemon_clicked_cb, LV_EVENT_CLICKED, NULL);
  _shown_sick = p->is_sick();

  _egg_image = lv_image_create(_screen);
  lv_image_set_src(_egg_image, &game_egg);
  lv_obj_align(_egg_image, LV_ALIGN_CENTER, 0, EGG_GROUND_Y);
  lv_image_set_pivot(_egg_image, game_egg.header.w / 2, game_egg.header.h);
  lv_obj_add_flag(_egg_image, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(_egg_image, _pokemon_clicked_cb, LV_EVENT_CLICKED, NULL);

  // Pedometer: steps to hatch the egg, then steps of the day
  _steps_label = lv_label_create(_screen);
  lv_obj_add_style(_steps_label, &style_game_label, 0);
  lv_obj_align(_steps_label, LV_ALIGN_BOTTOM_MID, 0, -4);

  _pokemon_ball = lv_image_create(_screen);
  serial_printf("Game", "Ball second init %d", _options->ball);
  lv_image_set_src(_pokemon_ball, balls_choice_images[_options->ball]);
  lv_obj_align(_pokemon_ball, LV_ALIGN_CENTER, 0, 90);
  lv_obj_add_flag(_pokemon_ball, LV_OBJ_FLAG_HIDDEN);

  _emote = lv_image_create(_screen);
  lv_obj_add_flag(_emote, LV_OBJ_FLAG_HIDDEN);

  if (p->is_egg()) {
    lv_obj_add_flag(_pokemon_image, LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_add_flag(_egg_image, LV_OBJ_FLAG_HIDDEN);

    lv_anim_t anim;
    lv_anim_init(&anim);
    lv_anim_set_var(&anim, _pokemon_image);
    lv_anim_set_values(&anim, 160, POKEMON_GROUND_Y);
    lv_anim_set_path_cb(&anim, lv_anim_path_overshoot);
    lv_anim_set_duration(&anim, 1500);
    lv_anim_set_exec_cb(&anim, anim_y_callback);
    lv_anim_start(&anim);

    if (p->is_sleeping()) {
      put_in_pokeball();
    }
  }

  _next_move = hal_millis() + 2500;
  _last_autosave = hal_millis();

  // Forget the motion of a mini-game: tilting the device is not walking
  hal_shake_detected();
  hal_take_steps();

  ActionsMenu* actions_menu = new ActionsMenu(new Menu(_main_screen));
  ActionsMenu::setInstance(actions_menu);

  GameMenu* game_menu = new GameMenu(new Menu(_main_screen));
  GameMenu::setInstance(game_menu);

  _update_background();
  _update_clock();
}

void Game::put_in_pokeball(void) {
  lv_anim_delete(_pokemon_image, NULL);
  lv_obj_add_flag(_pokemon_image, LV_OBJ_FLAG_HIDDEN);

  lv_image_set_src(_pokemon_ball, balls_choice_images[_options->ball]);
  lv_obj_remove_flag(_pokemon_ball, LV_OBJ_FLAG_HIDDEN);
}

void Game::release_from_pokeball(void) {
  lv_obj_add_flag(_pokemon_ball, LV_OBJ_FLAG_HIDDEN);
  lv_obj_remove_flag(_pokemon_image, LV_OBJ_FLAG_HIDDEN);
  lv_obj_set_y(_pokemon_image, POKEMON_GROUND_Y);
  _bounce();
}

void Game::loop(void) {
  if (game_over) {
    return;
  }

  Pokemon* p = Pokemon::getInstance();
  p->update(hal_now());
  _handle_events(p->take_events());

  if (p->is_ko()) {
    serial_printf("Game", "Pokemon is ko!");
    poke_messagebox_t* messagebox = create_message_box(_("pokemon.ko.title"), _("pokemon.ko.message"));
    lv_obj_add_event_cb(messagebox->close_button, end_game_msg_box_event_handler, LV_EVENT_PRESSED, NULL);

    game_over = true;
    return;
  }

  uint16_t steps = hal_take_steps();
  if (steps > 0) {
    p->add_steps(steps);
    _handle_events(p->take_events());
  }

  if (hal_shake_detected()) {
    bool was_sleeping = p->is_sleeping();
    p->shake();
    if (p->is_egg()) {
      _next_egg_wobble = 0;
    } else if (was_sleeping) {
      release_from_pokeball();
      _show_emote(EMOTE_ANGER);
    } else {
      _shake_head();
      _show_emote(EMOTE_SWEAT);
    }
  }

  // Remind the player of a call they did not answer yet
  if (p->get_call() != CALL_NONE && hal_millis() - _last_call_reminder > CALL_REMINDER_PERIOD) {
    _last_call_reminder = hal_millis();
    hal_beep(1800, 80);
    hal_vibrate(150);
    _attention_request = true;
  }

  _update_background();
  _update_clock();
  _update_bars();
  _update_egg();
  _update_steps();
  _update_wandering();
  _update_emote();

  if (p->get_poos() > _poos.size()) {
    create_poo();
  }

  if (p->get_pees() > _pees.size()) {
    create_pee();
  }

  if (hal_millis() - _last_autosave > AUTOSAVE_PERIOD) {
    autosave();
  }
}

void Game::_handle_events(uint16_t events) {
  if (events == 0) {
    return;
  }

  Pokemon* p = Pokemon::getInstance();
  char message[96];

  if (events & EVENT_HATCHED) {
    _show_pokemon();
    lv_snprintf(message, sizeof(message), _("game.hatch.message"), p->get_name());
    create_message_box(_("game.hatch.title"), message);
    hal_beep(2400, 120);
    autosave();
  }

  if (events & EVENT_CALL) {
    _last_call_reminder = hal_millis();
    hal_beep(1800, 80);
    hal_vibrate(150);
    _attention_request = true;
  }

  if (events & (EVENT_GOT_SICK | EVENT_CURED)) {
    if (_shown_sick != p->is_sick() && _evolution_timer == nullptr) {
      _shown_sick = p->is_sick();
      lv_gif_set_src(_pokemon_image, p->get_image());
    }
    _show_emote(p->is_sick() ? EMOTE_SICK : EMOTE_HEART);
  }

  if (events & EVENT_FELL_ASLEEP) {
    put_in_pokeball();
    autosave();
  }

  if (events & EVENT_WOKE_UP) {
    release_from_pokeball();
    _show_emote(EMOTE_NOTE);
    autosave();
  }

  if (events & EVENT_LEVEL_UP) {
    hal_beep(2200, 60);
    _show_emote(EMOTE_NOTE);
  }

  if (events & EVENT_CARE_MISTAKE) {
    _show_emote(EMOTE_ANGER);
  }

  if (events & EVENT_EVOLVE) {
    _start_evolution(p->get_evolution_from(), p->get_number());
  }
}

/**
 * The background follows the real time of the day, and goes to night when
 * the lights are off. Changes play the frames in between, like the sun
 * setting or rising.
 */
void Game::_update_background(void) {
  Pokemon* p = Pokemon::getInstance();
  uint8_t target = p->is_sleeping() ? BACKGROUND_FRAME_NIGHT : game_background_hours[Pokemon::hour_of(p->get_game_time())];

  if (_background_frame < 0) {
    // Start directly on the right frame
    _show_background_frame(target);
    return;
  }

  if (_background_frame == target || hal_millis() < _next_background_frame) {
    return;
  }

  // Always forward in the cycle: day, sunset, night, dawn
  _show_background_frame((_background_frame + 1) % NUMBER_BACKGROUND_FRAMES);
  _next_background_frame = hal_millis() + BACKGROUND_FRAME_DURATION;
}

void Game::_show_background_frame(uint8_t frame) {
  bool was_dark = _background_frame >= 0 && game_background_dark[_background_frame];
  _background_frame = frame;
  lv_image_set_src(_background, game_background_frames[frame]);

  bool dark = game_background_dark[frame];
  if (dark != was_dark) {
    lv_style_set_text_color(&style_game_label, dark ? lv_color_white() : lv_color_black());
    lv_obj_report_style_change(&style_game_label);
  }
}

/**
 * The clock of the Pokemon, faster than the real one
 */
void Game::_update_clock(void) {
  uint32_t now = Pokemon::getInstance()->get_game_time();
  int16_t minute = (now % 86400) / 60;
  if (minute == _last_minute) {
    return;
  }

  _last_minute = minute;
  lv_label_set_text_fmt(_clock_label, "%02d:%02d", minute / 60, minute % 60);
}

void Game::_update_bars(void) {
  Pokemon* p = Pokemon::getInstance();

  if (p->get_mood() != _last_mood) {
    _last_mood = p->get_mood();
    lv_bar_set_value(_mood_bar, _last_mood, LV_ANIM_ON);
  }

  if (p->get_life() != _last_life) {
    _last_life = p->get_life();
    lv_bar_set_value(_life_bar, _last_life, LV_ANIM_ON);
  }

  if (p->get_sleepiness() != _last_sleepiness) {
    _last_sleepiness = p->get_sleepiness();
    lv_bar_set_value(_sleepiness_bar, _last_sleepiness, LV_ANIM_ON);
  }

  if (p->get_hunger() != _last_hunger) {
    _last_hunger = p->get_hunger();
    lv_bar_set_value(_hunger_bar, _last_hunger, LV_ANIM_ON);
  }

  int16_t level = p->is_egg() ? 0 : p->get_level();
  if (level != _last_level) {
    _last_level = level;
    if (p->is_egg()) {
      lv_label_set_text(_level_indic, _("pokemon.egg.name"));
    } else {
      lv_label_set_text_fmt(_level_indic, "%s %d", _("game.level"), _last_level);
    }
  }
}

/**
 * The egg wobbles more and more often as it gets ready to hatch
 */
void Game::_update_egg(void) {
  Pokemon* p = Pokemon::getInstance();
  if (!p->is_egg()) {
    return;
  }

  int32_t steps = p->get_egg_steps();
  if (steps != _last_egg_steps) {
    // Each step brings the hatching closer: the egg reacts to the walk
    if (_last_egg_steps >= 0) {
      _next_egg_wobble = 0;
    }
    _last_egg_steps = steps;
    lv_label_set_text_fmt(_steps_label, _("game.egg.steps"), (int)steps, (int)EGG_HATCH_STEPS);
  }

  if (hal_millis() < _next_egg_wobble || lv_anim_get(_egg_image, anim_rotation_callback) != NULL) {
    return;
  }

  lv_anim_t anim;
  lv_anim_init(&anim);
  lv_anim_set_var(&anim, _egg_image);
  lv_anim_set_values(&anim, -120, 120);
  lv_anim_set_duration(&anim, 140);
  lv_anim_set_reverse_duration(&anim, 140);
  lv_anim_set_repeat_count(&anim, 2);
  lv_anim_set_exec_cb(&anim, anim_rotation_callback);
  lv_anim_set_completed_cb(&anim, [](lv_anim_t* a) { lv_image_set_rotation((lv_obj_t*)a->var, 0); });
  lv_anim_start(&anim);

  float progress = p->get_hatch_progress();
  _next_egg_wobble = hal_millis() + 1200 + (uint32_t)((1.0f - progress) * 6000) + hal_random(0, 1500);
}

/**
 * Once hatched, the label under the Pokemon counts the steps of the day
 */
void Game::_update_steps(void) {
  Pokemon* p = Pokemon::getInstance();
  if (p->is_egg()) {
    return;
  }

  int32_t steps = p->get_steps_today(hal_now());
  if (steps != _last_steps_today) {
    _last_steps_today = steps;
    lv_label_set_text_fmt(_steps_label, _("game.steps.today"), (unsigned long)steps);
  }
}

/**
 * The Pokemon walks around and hops when it is awake and has nothing to do
 */
void Game::_update_wandering(void) {
  Pokemon* p = Pokemon::getInstance();
  unsigned long now = hal_millis();
  if (p->is_egg() || p->is_sleeping() || _evolution_timer != nullptr || now < _busy_until || now < _next_move) {
    return;
  }

  // A sick or bored Pokemon does not move much
  bool lazy = p->is_sick() || p->get_mood() <= 2;
  if (hal_random(0, 100) < (lazy ? 70 : 25)) {
    if (!lazy) {
      _bounce();
    }
    _next_move = now + hal_random(3000, 7000);
    return;
  }

  int32_t target = hal_random(-POKEMON_MAX_X, POKEMON_MAX_X + 1);
  uint32_t distance = abs(target - _pokemon_x);
  uint32_t duration = distance * (lazy ? 40 : 18) + 200;

  lv_anim_delete(_pokemon_image, anim_x_callback);
  lv_anim_t walk;
  lv_anim_init(&walk);
  lv_anim_set_var(&walk, _pokemon_image);
  lv_anim_set_values(&walk, _pokemon_x, target);
  lv_anim_set_duration(&walk, duration);
  lv_anim_set_path_cb(&walk, lv_anim_path_ease_in_out);
  lv_anim_set_exec_cb(&walk, anim_x_callback);
  lv_anim_start(&walk);

  // Little hops while walking
  lv_anim_delete(_pokemon_image, anim_y_callback);
  lv_anim_t hop;
  lv_anim_init(&hop);
  lv_anim_set_var(&hop, _pokemon_image);
  lv_anim_set_values(&hop, POKEMON_GROUND_Y, POKEMON_GROUND_Y - 5);
  lv_anim_set_duration(&hop, 140);
  lv_anim_set_reverse_duration(&hop, 140);
  lv_anim_set_repeat_count(&hop, duration / 280);
  lv_anim_set_exec_cb(&hop, anim_y_callback);
  lv_anim_start(&hop);

  _pokemon_x = target;
  _next_move = now + duration + hal_random(2500, 7000);
}

void Game::_show_emote(Emote emote) {
  _emote_shown = emote;
  _emote_until = hal_millis() + EMOTE_DURATION;
}

/**
 * Show a reaction for a while, otherwise what the Pokemon needs
 */
void Game::_update_emote(void) {
  Pokemon* p = Pokemon::getInstance();
  Emote emote = EMOTE_NONE;

  if (_evolution_timer != nullptr) {
    emote = EMOTE_NONE;
  } else if (hal_millis() < _emote_until) {
    emote = _emote_shown;
  } else if (p->is_egg()) {
    emote = EMOTE_NONE;
  } else if (p->get_call() == CALL_SICK) {
    emote = EMOTE_SICK;
  } else if (p->get_call() != CALL_NONE) {
    emote = EMOTE_EXCLAMATION;
  } else if (p->is_sleeping()) {
    emote = EMOTE_ZZZ;
  }

  if (emote == EMOTE_NONE) {
    if (!lv_obj_has_flag(_emote, LV_OBJ_FLAG_HIDDEN)) {
      lv_obj_add_flag(_emote, LV_OBJ_FLAG_HIDDEN);
    }
    return;
  }

  static const lv_image_dsc_t* const images[] = {
      NULL, &emote_heart, &emote_exclamation, &emote_note, &emote_anger, &emote_sweat, &emote_zzz, &emote_question, &emote_sick,
  };

  if (lv_image_get_src(_emote) != images[emote]) {
    lv_image_set_src(_emote, images[emote]);
  }
  lv_obj_remove_flag(_emote, LV_OBJ_FLAG_HIDDEN);
  lv_obj_align_to(_emote, _active_sprite(), LV_ALIGN_OUT_TOP_RIGHT, 4, 6);
}

lv_obj_t* Game::_active_sprite(void) {
  Pokemon* p = Pokemon::getInstance();
  if (p->is_egg()) {
    return _egg_image;
  }

  return p->is_sleeping() ? _pokemon_ball : _pokemon_image;
}

void Game::_bounce(void) {
  lv_anim_delete(_pokemon_image, anim_y_callback);

  lv_anim_t anim;
  lv_anim_init(&anim);
  lv_anim_set_var(&anim, _pokemon_image);
  lv_anim_set_values(&anim, POKEMON_GROUND_Y, POKEMON_GROUND_Y - 18);
  lv_anim_set_duration(&anim, 180);
  lv_anim_set_reverse_duration(&anim, 220);
  lv_anim_set_path_cb(&anim, lv_anim_path_ease_out);
  lv_anim_set_exec_cb(&anim, anim_y_callback);
  lv_anim_start(&anim);
}

/**
 * Refuse something: stop walking and shake the head
 */
void Game::_shake_head(void) {
  lv_anim_delete(_pokemon_image, NULL);
  _pokemon_x = lv_obj_get_x_aligned(_pokemon_image);
  lv_obj_set_y(_pokemon_image, POKEMON_GROUND_Y);

  lv_anim_t anim;
  lv_anim_init(&anim);
  lv_anim_set_var(&anim, _pokemon_image);
  lv_anim_set_values(&anim, _pokemon_x - 6, _pokemon_x + 6);
  lv_anim_set_duration(&anim, 90);
  lv_anim_set_reverse_duration(&anim, 90);
  lv_anim_set_repeat_count(&anim, 3);
  lv_anim_set_exec_cb(&anim, anim_x_callback);
  lv_anim_set_completed_cb(&anim, [](lv_anim_t* a) { lv_obj_set_x((lv_obj_t*)a->var, Game::getInstance()->_pokemon_x); });
  lv_anim_start(&anim);

  _busy_until = hal_millis() + 1500;
}

void Game::_show_pokemon(void) {
  Pokemon* p = Pokemon::getInstance();

  lv_anim_delete(_egg_image, NULL);
  lv_obj_add_flag(_egg_image, LV_OBJ_FLAG_HIDDEN);
  _last_steps_today = -1;

  _shown_sick = p->is_sick();
  lv_gif_set_src(_pokemon_image, p->get_image());
  lv_obj_remove_flag(_pokemon_image, LV_OBJ_FLAG_HIDDEN);
  _pokemon_x = 0;
  lv_obj_set_x(_pokemon_image, 0);
  _bounce();
  _show_emote(EMOTE_HEART);
  _busy_until = hal_millis() + 2000;
}

/**
 * Classic evolution sequence: a white silhouette blinking between the two
 * forms, faster and faster
 */
void Game::_start_evolution(int from, int to) {
  if (_evolution_timer != nullptr) {
    return;
  }

  if (Pokemon::getInstance()->is_sleeping()) {
    Pokemon::getInstance()->wake_up();
  }

  lv_obj_add_flag(_pokemon_ball, LV_OBJ_FLAG_HIDDEN);
  lv_obj_remove_flag(_pokemon_image, LV_OBJ_FLAG_HIDDEN);
  lv_anim_delete(_pokemon_image, NULL);
  _pokemon_x = 0;
  lv_obj_set_pos(_pokemon_image, 0, POKEMON_GROUND_Y);

  _evolution_from = from;
  _evolution_to = to;
  _evolution_step = 0;
  _evolution_showing_new = false;

  lv_gif_set_src(_pokemon_image, Pokemon::get_image(from, false));
  lv_obj_set_style_image_recolor(_pokemon_image, lv_color_white(), 0);
  lv_obj_set_style_image_recolor_opa(_pokemon_image, LV_OPA_COVER, 0);

  _evolution_timer = lv_timer_create(_evolution_timer_cb, 90, this);
  hal_beep(1200, 150);
}

void Game::_evolution_timer_cb(lv_timer_t* timer) { ((Game*)lv_timer_get_user_data(timer))->_evolution_tick(); }

void Game::_evolution_tick(void) {
  _evolution_step++;

  if (_evolution_step < 40) {
    uint8_t period = _evolution_step < 12 ? 6 : (_evolution_step < 24 ? 4 : (_evolution_step < 34 ? 2 : 1));
    if (_evolution_step % period == 0) {
      _evolution_showing_new = !_evolution_showing_new;
      lv_gif_set_src(_pokemon_image, Pokemon::get_image(_evolution_showing_new ? _evolution_to : _evolution_from, false));
    }
    return;
  }

  if (_evolution_step == 40) {
    lv_gif_set_src(_pokemon_image, Pokemon::get_image(_evolution_to, false));
    hal_beep(2600, 200);
    return;
  }

  if (_evolution_step < 46) {
    return;
  }

  lv_timer_delete(_evolution_timer);
  _evolution_timer = nullptr;

  Pokemon* p = Pokemon::getInstance();
  lv_obj_set_style_image_recolor_opa(_pokemon_image, LV_OPA_TRANSP, 0);
  _shown_sick = p->is_sick();
  lv_gif_set_src(_pokemon_image, p->get_image());
  _bounce();
  _show_emote(EMOTE_HEART);
  _busy_until = hal_millis() + 2000;

  char message[96];
  lv_snprintf(message, sizeof(message), _("game.evolve.message"), Pokemon::get_name(_evolution_from), p->get_name());
  create_message_box(_("game.evolve.title"), message);

  ActionsMenu::getInstance()->invalidate_bag();
  autosave();
}

void Game::_pokemon_clicked_cb(lv_event_t* e) {
  LV_UNUSED(e);
  Game::getInstance()->action_pet();
}

void Game::action_pet(void) {
  Pokemon* p = Pokemon::getInstance();
  if (_evolution_timer != nullptr) {
    return;
  }

  if (p->is_egg()) {
    p->tap_egg();
    _next_egg_wobble = 0;
    return;
  }

  p->pet();
  _show_emote(EMOTE_HEART);
  _bounce();
  _busy_until = hal_millis() + 1200;
}

void Game::create_poo(void) {
  lv_obj_t* poo = lv_image_create(_screen);
  lv_image_set_src(poo, &game_poo);
  lv_obj_set_pos(poo, hal_random(1, LV_HOR_RES_MAX - game_poo.header.w), hal_random(LV_VER_RES_MAX / 2, LV_VER_RES_MAX - game_poo.header.h));
  _poos.push_back(poo);
}

void Game::create_pee(void) {
  lv_obj_t* pee = lv_image_create(_screen);
  lv_image_set_src(pee, &game_pee);
  lv_obj_set_pos(pee, hal_random(1, LV_HOR_RES_MAX - game_pee.header.w), hal_random(LV_VER_RES_MAX / 2, LV_VER_RES_MAX - game_pee.header.h));
  _pees.push_back(pee);
}

void Game::try_to_clean(void) {
  for (size_t i = 0; i < _poos.size();) {
    if (check_object_intersect(_clean, _poos[i])) {
      lv_obj_delete(_poos[i]);
      Pokemon::getInstance()->clean_poo();
      _poos.erase(_poos.begin() + i);
    } else {
      i++;
    }
  }

  for (size_t i = 0; i < _pees.size();) {
    if (check_object_intersect(_clean, _pees[i])) {
      lv_obj_delete(_pees[i]);
      Pokemon::getInstance()->clean_pee();
      _pees.erase(_pees.begin() + i);
    } else {
      i++;
    }
  }
}

static bool check_object_intersect(lv_obj_t* a, lv_obj_t* b) {
  int32_t x = lv_obj_get_x(a);
  int32_t y = lv_obj_get_y(a);

  int32_t d1x = lv_obj_get_x(b) - (x + lv_obj_get_height(a));
  int32_t d1y = lv_obj_get_y(b) - (y + lv_obj_get_width(a));
  int32_t d2x = x - (lv_obj_get_x(b) + lv_obj_get_width(b));
  int32_t d2y = y - (lv_obj_get_y(b) + lv_obj_get_height(b));

  if (d1x < 0 && d1y < 0 && d2x < 0 && d2y < 0) {
    return true;
  }

  return false;
}

void Game::action_clean(void) {
  if (lv_obj_is_valid(_clean)) {
    return;
  }

  _clean = lv_image_create(_screen);
  lv_image_set_src(_clean, &game_clean);
  lv_obj_set_pos(_clean, LV_HOR_RES_MAX / 2, LV_VER_RES_MAX / 2);
  lv_obj_add_flag(_clean, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(_clean, LV_OBJ_FLAG_CLICK_FOCUSABLE);
  lv_obj_add_event_cb(_clean, drag_clean_event_handler, LV_EVENT_PRESSING, NULL);
}

void Game::action_train(void) {
  switch (Pokemon::getInstance()->train()) {
    case ACTION_DONE:
      _bounce();
      _show_emote(EMOTE_SWEAT);
      break;
    case ACTION_REFUSED_SICK:
      _shake_head();
      _show_emote(EMOTE_SICK);
      break;
    default:
      _shake_head();
      _show_emote(EMOTE_SWEAT);
      break;
  }
}

void Game::action_play(void) {
  switch (Pokemon::getInstance()->play()) {
    case ACTION_DONE:
      _bounce();
      _show_emote(EMOTE_NOTE);
      _busy_until = hal_millis() + 1200;
      break;
    case ACTION_REFUSED_SICK:
      _shake_head();
      _show_emote(EMOTE_SICK);
      break;
    default:
      _shake_head();
      _show_emote(EMOTE_SWEAT);
      break;
  }
}

void Game::action_eat(BagItem* item) {
  switch (Pokemon::getInstance()->eat(item)) {
    case ACTION_DONE:
      _bounce();
      _show_emote(EMOTE_HEART);
      hal_beep(2000, 50);
      break;
    case ACTION_REFUSED_FULL:
      _shake_head();
      _show_emote(EMOTE_ANGER);
      break;
    default:
      _show_emote(EMOTE_QUESTION);
      break;
  }
}

void Game::action_use_stone(Stone stone) {
  if (Pokemon::getInstance()->use_stone(stone) == ACTION_DONE) {
    // The evolution sequence starts with the next update
    ActionsMenu::getInstance()->invalidate_bag();
    return;
  }

  _shake_head();
  _show_emote(EMOTE_QUESTION);
  create_message_box("", _("game.stone.no_effect"));
}

void Game::action_heal(void) {
  if (Pokemon::getInstance()->heal() == ACTION_DONE) {
    _show_emote(EMOTE_HEART);
  } else {
    _show_emote(EMOTE_QUESTION);
  }
}

void Game::action_sleep(void) {
  Pokemon* p = Pokemon::getInstance();
  if (p->is_sleeping() == false && p->is_egg() == false) {
    p->sleep();
    put_in_pokeball();
    autosave();
  }
}

void Game::action_wake_up(void) {
  Pokemon* p = Pokemon::getInstance();
  if (p->is_sleeping() == true) {
    p->wake_up();
    release_from_pokeball();
  }
}

/**
 * Back from a mini-game: the Pokemon had fun, and maybe found something
 */
void Game::apply_minigame_reward(int32_t score) {
  Pokemon* p = Pokemon::getInstance();
  if (p->is_egg()) {
    return;
  }

  int8_t stone = p->reward_minigame(score);
  char message[96];
  if (stone >= 0) {
    lv_snprintf(message, sizeof(message), _("game.reward.stone"), p->get_name(), Pokemon::get_stone_name((Stone)stone));
    ActionsMenu::getInstance()->invalidate_bag();
  } else {
    lv_snprintf(message, sizeof(message), _("game.reward.fun"), p->get_name());
  }

  create_message_box(_("game.reward.title"), message);
  _show_emote(EMOTE_NOTE);
}

void Game::abort_actions(void) {
  if (lv_obj_is_valid(_clean)) {
    lv_obj_delete(_clean);
  }
}

/**
 * Save the game options and the Pokemon to a file on the SD card
 */
bool Game::save(const char* path) {
  if (hal_start_storage() == false) {
    return false;
  }

  hal_file_t file = hal_open_file(path);
  if (!file) {
    hal_stop_storage();
    return false;
  }

  JsonDocument doc;
  doc["options"]["brightness"] = _options->brightness;
  doc["options"]["ball"] = _options->ball;
  Pokemon::getInstance()->save(doc["pokemon"].to<JsonObject>());

  serializeJson(doc, file);
  file.close();
  hal_stop_storage();

  serial_printf("Game", "Saved to \"%s\"", path);
  return true;
}

/**
 * Save regularly to the current save file, or to an autosave file for a
 * game that was never saved
 */
void Game::autosave(void) {
  _last_autosave = hal_millis();
  if (!_config->use_storage) {
    return;
  }

  if (_options->save_file_path == NULL) {
    char path[64];
    lv_snprintf(path, sizeof(path), "%s/autosave.json", _config->save_files_path);
    _options->save_file_path = strdup(path);
  }

  if (!save(_options->save_file_path)) {
    serial_printf("Game", "Autosave failed");
  }
}

/**
 * Drag event for clean up action
 *
 * @param lv_event_t* e
 */
static void drag_clean_event_handler(lv_event_t* e) {
  lv_obj_t* obj = lv_event_get_target_obj(e);

  lv_indev_t* indev = lv_indev_active();
  if (indev == NULL) return;

  lv_point_t vect;
  lv_indev_get_vect(indev, &vect);

  int32_t x = lv_obj_get_x_aligned(obj) + vect.x;
  int32_t y = lv_obj_get_y_aligned(obj) + vect.y;

  int32_t obj_width = lv_obj_get_width(obj);
  int32_t obj_height = lv_obj_get_height(obj);

  // Make sure the object could not go outside the screen
  if ((x + obj_width) > LV_HOR_RES_MAX) {
    x = LV_HOR_RES_MAX - obj_width;
  } else if (x < 0) {
    x = 0;
  }

  if ((y + obj_height) > LV_VER_RES_MAX) {
    y = LV_VER_RES_MAX - obj_height;
  } else if (y < 0) {
    y = 0;
  }

  lv_obj_set_pos(obj, x, y);

  Game::getInstance()->try_to_clean();
}

static void end_game_msg_box_event_handler(lv_event_t* e) {
  LV_UNUSED(e);
  serial_printf("Game", "Restart game");
  hal_restart();
}
