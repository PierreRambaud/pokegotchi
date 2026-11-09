#include <math.h>
#include "lv_i18n.h"
#include "Utils.h"
#include "keyboard_hal.h"
#include "game_anim.h"
#include "GameSwitcher.h"
#include "PetClock.h"
#include "FloppyBird.h"

using namespace FloppyBird;

LV_IMG_DECLARE(bird_wing_up)
LV_IMG_DECLARE(bird_wing_down)
LV_IMG_DECLARE(bird_ground)
LV_IMG_DECLARE(object_berry)

#define SCREEN_W 320
#define SCREEN_H 240
#define GROUND_Y 216
#define GROUND_TILE 16

#define STEP_SECONDS (1.0f / 60.0f)

#define BIRD_X 80
#define BIRD_RADIUS 9.0f
#define GRAVITY 1100.0f
#define FLAP_VELOCITY -300.0f
#define MAX_FALL_VELOCITY 480.0f

#define PIPE_WIDTH 40
#define PIPE_CAP_HEIGHT 14
#define PIPE_CAP_OVERHANG 3
#define PIPE_SPACING 170
#define PIPE_MARGIN 40

// Narrower gaps and faster pipes as the score goes up
#define GAP_START 92
#define GAP_MIN 66
#define SPEED_START 95.0f
#define SPEED_GAIN 2.0f
#define SPEED_MAX 155.0f

#define BERRY_CHANCE 30
#define BERRY_RADIUS 8.0f
#define BERRY_POINTS 2

#define MEDAL_BRONZE 10
#define MEDAL_SILVER 25
#define MEDAL_GOLD 50

#define GAME_OVER_DELAY 0.6f

static const char* const BEST_SCORE_KEY = "bird_best";

static lv_style_t style_pipe;
static lv_style_t style_pipe_cap;
static bool styles_ready = false;

static void init_styles(void) {
  if (styles_ready) {
    return;
  }
  styles_ready = true;

  // Green pipes, lit from the left
  lv_style_init(&style_pipe);
  lv_style_set_radius(&style_pipe, 0);
  lv_style_set_bg_opa(&style_pipe, LV_OPA_COVER);
  lv_style_set_bg_color(&style_pipe, lv_color_make(150, 230, 100));
  lv_style_set_bg_grad_color(&style_pipe, lv_color_make(60, 150, 40));
  lv_style_set_bg_grad_dir(&style_pipe, LV_GRAD_DIR_HOR);
  lv_style_set_border_width(&style_pipe, 2);
  lv_style_set_border_color(&style_pipe, lv_color_make(30, 80, 20));
  lv_style_set_pad_all(&style_pipe, 0);

  lv_style_init(&style_pipe_cap);
  lv_style_set_radius(&style_pipe_cap, 3);
}

static lv_obj_t* create_box(lv_obj_t* parent) {
  lv_obj_t* obj = lv_obj_create(parent);
  lv_obj_remove_style_all(obj);
  lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
  return obj;
}

static lv_obj_t* create_label(lv_obj_t* parent, const lv_font_t* font) {
  lv_obj_t* label = lv_label_create(parent);
  lv_obj_set_style_text_font(label, font, 0);
  lv_obj_set_style_text_color(label, lv_color_white(), 0);
  lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
  return label;
}

static void flash_opa_cb(void* obj, int32_t value) { lv_obj_set_style_bg_opa((lv_obj_t*)obj, value, 0); }

Runner::Runner(void) {
  init_styles();
  _best_score = hal_settings_get(BEST_SCORE_KEY, 0);
  create_scene();
  reset();

  serial_printf("FloppyBird", "Ready, best score: %d", (int)_best_score);
}

void Runner::close(void) {
  // The screen and its objects are deleted when the next game loads its own
}

void Runner::create_scene(void) {
  _screen = lv_obj_create(NULL);
  lv_obj_remove_style_all(_screen);
  lv_obj_set_size(_screen, SCREEN_W, SCREEN_H);
  lv_obj_set_style_bg_color(_screen, lv_color_make(120, 190, 240), 0);
  lv_obj_set_style_bg_opa(_screen, LV_OPA_COVER, 0);
  lv_obj_remove_flag(_screen, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_add_flag(_screen, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(_screen, pressed_cb, LV_EVENT_PRESSED, this);

  // Same sky as the Pokemon, at the same hour of its day
  lv_obj_t* background = lv_image_create(_screen);
  lv_image_set_src(background, game_background_frames[game_background_hours[Pokegotchi::pet_hour()]]);
  lv_obj_set_pos(background, 0, 0);

  for (uint8_t i = 0; i < FLOPPYBIRD_PIPES; i++) {
    create_pipe(_pipes[i]);
  }

  // The ground scrolls by moving a tiled strip one tile wider than the screen
  _ground = create_box(_screen);
  lv_obj_set_size(_ground, SCREEN_W + GROUND_TILE, SCREEN_H - GROUND_Y);
  lv_obj_set_pos(_ground, 0, GROUND_Y);
  lv_obj_set_style_bg_image_src(_ground, &bird_ground, 0);
  lv_obj_set_style_bg_image_tiled(_ground, true, 0);

  _bird = lv_image_create(_screen);
  lv_image_set_src(_bird, &bird_wing_up);
  lv_image_set_pivot(_bird, bird_wing_up.header.w / 2, bird_wing_up.header.h / 2);

  // The score is the most important text: twice bigger, the pixel font
  // stays sharp at an integer scale
  _score_label = create_label(_screen, &pokemon_font_14);
  lv_obj_set_style_bg_color(_score_label, lv_color_black(), 0);
  lv_obj_set_style_bg_opa(_score_label, LV_OPA_40, 0);
  lv_obj_set_style_pad_hor(_score_label, 6, 0);
  lv_obj_set_style_pad_ver(_score_label, 1, 0);
  lv_obj_set_style_radius(_score_label, 4, 0);
  lv_obj_set_style_transform_scale(_score_label, 512, 0);
  lv_obj_set_style_transform_pivot_x(_score_label, LV_PCT(50), 0);
  lv_obj_set_style_transform_pivot_y(_score_label, 0, 0);
  lv_obj_align(_score_label, LV_ALIGN_TOP_MID, 0, 6);

  _hint_label = create_label(_screen, &pokemon_font_12);
  lv_obj_set_style_bg_color(_hint_label, lv_color_black(), 0);
  lv_obj_set_style_bg_opa(_hint_label, LV_OPA_50, 0);
  lv_obj_set_style_pad_all(_hint_label, 6, 0);
  lv_obj_set_style_radius(_hint_label, 8, 0);
  lv_obj_set_width(_hint_label, SCREEN_W - 40);
  lv_label_set_long_mode(_hint_label, LV_LABEL_LONG_WRAP);
  lv_label_set_text_fmt(_hint_label, "%s\n%s", _("game.bird.ready"), _("game.minigame.back"));
  lv_obj_align(_hint_label, LV_ALIGN_CENTER, 0, 40);

  // White flash when the bird crashes
  _flash = create_box(_screen);
  lv_obj_set_size(_flash, SCREEN_W, SCREEN_H);
  lv_obj_set_style_bg_color(_flash, lv_color_white(), 0);
  lv_obj_set_style_bg_opa(_flash, LV_OPA_TRANSP, 0);

  // Load it and delete the screen of the Pokemon, already emptied
  lv_screen_load_anim(_screen, LV_SCREEN_LOAD_ANIM_NONE, 0, 0, true);
}

void Runner::create_pipe(Pipe& pipe) {
  pipe.top = create_box(_screen);
  pipe.bottom = create_box(_screen);
  pipe.top_cap = create_box(_screen);
  pipe.bottom_cap = create_box(_screen);

  lv_obj_add_style(pipe.top, &style_pipe, 0);
  lv_obj_add_style(pipe.bottom, &style_pipe, 0);
  lv_obj_add_style(pipe.top_cap, &style_pipe, 0);
  lv_obj_add_style(pipe.top_cap, &style_pipe_cap, 0);
  lv_obj_add_style(pipe.bottom_cap, &style_pipe, 0);
  lv_obj_add_style(pipe.bottom_cap, &style_pipe_cap, 0);

  // An Oran berry floats in some gaps
  pipe.berry = lv_image_create(_screen);
  lv_image_set_src(pipe.berry, &object_berry);
  lv_image_set_scale(pipe.berry, 160);
}

/**
 * Put a pipe at this position with a new gap, smaller as the score grows
 */
void Runner::place_pipe(Pipe& pipe, float x) {
  pipe.x = x;
  pipe.gap = LV_MAX(GAP_START - _score, GAP_MIN);
  pipe.gap_y = hal_random(PIPE_MARGIN + pipe.gap / 2, GROUND_Y - PIPE_MARGIN - pipe.gap / 2 + 1);
  pipe.scored = false;
  pipe.has_berry = _state != STATE_READY && hal_random(0, 100) < BERRY_CHANCE;

  int32_t gap_top = pipe.gap_y - pipe.gap / 2;
  int32_t gap_bottom = pipe.gap_y + pipe.gap / 2;

  lv_obj_set_size(pipe.top, PIPE_WIDTH, LV_MAX(gap_top - PIPE_CAP_HEIGHT, 0) + 2);
  lv_obj_set_size(pipe.top_cap, PIPE_WIDTH + 2 * PIPE_CAP_OVERHANG, PIPE_CAP_HEIGHT);
  lv_obj_set_size(pipe.bottom_cap, PIPE_WIDTH + 2 * PIPE_CAP_OVERHANG, PIPE_CAP_HEIGHT);
  lv_obj_set_size(pipe.bottom, PIPE_WIDTH, GROUND_Y - gap_bottom - PIPE_CAP_HEIGHT + 2);

  if (pipe.has_berry) {
    lv_obj_remove_flag(pipe.berry, LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_add_flag(pipe.berry, LV_OBJ_FLAG_HIDDEN);
  }
}

void Runner::reset(void) {
  _state = STATE_READY;
  _state_time = 0;
  _score = 0;
  _speed = SPEED_START;
  _bird_y = SCREEN_H / 2 - 20;
  _velocity = 0;
  _flap_requested = false;

  for (uint8_t i = 0; i < FLOPPYBIRD_PIPES; i++) {
    place_pipe(_pipes[i], SCREEN_W + 60 + i * PIPE_SPACING);
  }

  if (_panel != nullptr) {
    lv_obj_delete(_panel);
    _panel = nullptr;
  }
  lv_obj_remove_flag(_hint_label, LV_OBJ_FLAG_HIDDEN);

  render();
}

void Runner::pressed_cb(lv_event_t* e) { ((Runner*)lv_event_get_user_data(e))->_flap_requested = true; }

void Runner::flap(void) {
  _velocity = FLAP_VELOCITY;
  hal_beep(900, 20);
}

void Runner::loop(void) {
  unsigned long now = hal_millis();
  float elapsed = _last_frame == 0 ? 0 : LV_MIN(now - _last_frame, 100UL) / 1000.0f;
  _last_frame = now;

  bool flap_input = _flap_requested || hal_button_b_pressed();
  _flap_requested = false;

  if (hal_button_c_pressed()) {
    // Back to the Pokemon, with the best score of the session as a reward
    GameSwitcher::Runner::getInstance()->finish_minigame(_session_best);
    return;
  }

  switch (_state) {
    case STATE_READY:
      if (flap_input) {
        _state = STATE_PLAY;
        _state_time = 0;
        lv_obj_add_flag(_hint_label, LV_OBJ_FLAG_HIDDEN);
        flap();
      }
      break;

    case STATE_PLAY:
      if (flap_input) {
        flap();
      }
      break;

    case STATE_GAME_OVER:
      // A short delay, so a tap of the crash does not restart right away
      if (flap_input && _state_time > GAME_OVER_DELAY) {
        reset();
        return;
      }
      break;

    default:
      break;
  }

  // Fixed steps: the same physics whatever the frame rate
  _accumulator += elapsed;
  while (_accumulator >= STEP_SECONDS) {
    step(STEP_SECONDS);
    _accumulator -= STEP_SECONDS;
  }

  render();
}

void Runner::step(float dt) {
  _state_time += dt;
  _wing_time += dt;

  if (_state == STATE_GAME_OVER) {
    return;
  }

  // Flap the wings, faster when going up
  float wing_period = _velocity < 0 ? 0.08f : 0.16f;
  if (_wing_time >= wing_period) {
    _wing_time = 0;
    _wing_up = !_wing_up;
  }

  if (_state == STATE_READY) {
    // Hover while waiting for the first flap
    _bird_y = SCREEN_H / 2 - 20 + sinf(_state_time * 5.0f) * 5.0f;
    _ground_offset += SPEED_START * dt;
    return;
  }

  _velocity = LV_MIN(_velocity + GRAVITY * dt, MAX_FALL_VELOCITY);
  _bird_y += _velocity * dt;
  if (_bird_y < BIRD_RADIUS) {
    _bird_y = BIRD_RADIUS;
    _velocity = 0;
  }

  if (_bird_y + BIRD_RADIUS >= GROUND_Y) {
    _bird_y = GROUND_Y - BIRD_RADIUS;
    if (_state == STATE_PLAY) {
      crash();
    }
    show_game_over();
    return;
  }

  if (_state != STATE_PLAY) {
    return;
  }

  _ground_offset += _speed * dt;

  for (uint8_t i = 0; i < FLOPPYBIRD_PIPES; i++) {
    Pipe& pipe = _pipes[i];
    pipe.x -= _speed * dt;

    if (collides(pipe)) {
      crash();
      return;
    }

    // Catch the berry in the middle of the gap
    if (pipe.has_berry) {
      float dx = pipe.x + PIPE_WIDTH / 2 - BIRD_X;
      float dy = pipe.gap_y - _bird_y;
      if (dx * dx + dy * dy < (BIRD_RADIUS + BERRY_RADIUS) * (BIRD_RADIUS + BERRY_RADIUS)) {
        pipe.has_berry = false;
        lv_obj_add_flag(pipe.berry, LV_OBJ_FLAG_HIDDEN);
        _score += BERRY_POINTS;
        hal_beep(2600, 60);
      }
    }

    if (!pipe.scored && pipe.x + PIPE_WIDTH < BIRD_X - BIRD_RADIUS) {
      pipe.scored = true;
      _score++;
      _speed = LV_MIN(SPEED_START + _score * SPEED_GAIN, SPEED_MAX);
      hal_beep(1800, 40);
    }

    // Out of the screen: back after the last pipe
    if (pipe.x + PIPE_WIDTH + PIPE_CAP_OVERHANG < 0) {
      float last = pipe.x;
      for (uint8_t j = 0; j < FLOPPYBIRD_PIPES; j++) {
        last = LV_MAX(last, _pipes[j].x);
      }
      place_pipe(pipe, last + PIPE_SPACING);
    }
  }
}

/**
 * Circle of the bird against the two parts of a pipe, caps included
 */
bool Runner::collides(const Pipe& pipe) {
  float left = pipe.x - PIPE_CAP_OVERHANG;
  float right = pipe.x + PIPE_WIDTH + PIPE_CAP_OVERHANG;
  float nearest_x = BIRD_X < left ? left : (BIRD_X > right ? right : BIRD_X);
  float dx = BIRD_X - nearest_x;
  if (dx * dx >= BIRD_RADIUS * BIRD_RADIUS) {
    return false;
  }

  float gap_top = pipe.gap_y - pipe.gap / 2;
  float gap_bottom = pipe.gap_y + pipe.gap / 2;
  float radius_y = sqrtf(BIRD_RADIUS * BIRD_RADIUS - dx * dx);

  return _bird_y - radius_y < gap_top || _bird_y + radius_y > gap_bottom;
}

void Runner::crash(void) {
  _state = STATE_FALLING;
  _state_time = 0;
  _velocity = LV_MIN(_velocity, 0.0f);
  hal_beep(200, 250);
  hal_vibrate(150);

  lv_anim_t anim;
  lv_anim_init(&anim);
  lv_anim_set_var(&anim, _flash);
  lv_anim_set_values(&anim, LV_OPA_80, LV_OPA_TRANSP);
  lv_anim_set_duration(&anim, 350);
  lv_anim_set_exec_cb(&anim, flash_opa_cb);
  lv_anim_start(&anim);
}

void Runner::show_game_over(void) {
  if (_state == STATE_GAME_OVER) {
    return;
  }
  _state = STATE_GAME_OVER;
  _state_time = 0;

  bool new_best = _score > _best_score;
  if (new_best) {
    _best_score = _score;
    hal_settings_set(BEST_SCORE_KEY, _best_score);
  }
  _session_best = LV_MAX(_session_best, _score);

  _panel = lv_obj_create(_screen);
  lv_obj_set_size(_panel, 230, 150);
  lv_obj_center(_panel);
  lv_obj_remove_flag(_panel, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_remove_flag(_panel, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_style_bg_color(_panel, lv_color_make(20, 30, 60), 0);
  lv_obj_set_style_bg_opa(_panel, LV_OPA_90, 0);
  lv_obj_set_style_border_color(_panel, lv_color_white(), 0);
  lv_obj_set_style_border_width(_panel, 2, 0);
  lv_obj_set_style_radius(_panel, 10, 0);

  lv_obj_t* title = create_label(_panel, &pokemon_font_14);
  lv_label_set_text(title, _("game.bird.gameover"));
  lv_obj_align(title, LV_ALIGN_TOP_MID, 0, -4);

  lv_obj_t* scores = create_label(_panel, &pokemon_font_12);
  lv_label_set_text_fmt(scores, "%s %d\n%s %d", _("game.bird.score"), (int)_score, _("game.bird.maxscore"), (int)_best_score);
  lv_obj_set_style_text_align(scores, LV_TEXT_ALIGN_LEFT, 0);
  lv_obj_align(scores, LV_ALIGN_LEFT_MID, 0, -12);

  // A medal for the good scores, with its name
  if (_score >= MEDAL_BRONZE) {
    lv_color_t color = lv_color_make(205, 127, 50);
    const char* name = _("game.bird.medal.bronze");
    if (_score >= MEDAL_GOLD) {
      color = lv_color_make(255, 205, 50);
      name = _("game.bird.medal.gold");
    } else if (_score >= MEDAL_SILVER) {
      color = lv_color_make(205, 210, 220);
      name = _("game.bird.medal.silver");
    }

    lv_obj_t* medal = create_box(_panel);
    lv_obj_set_size(medal, 36, 36);
    lv_obj_align(medal, LV_ALIGN_RIGHT_MID, -8, -16);
    lv_obj_set_style_radius(medal, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(medal, color, 0);
    lv_obj_set_style_bg_grad_color(medal, lv_color_white(), 0);
    lv_obj_set_style_bg_grad_dir(medal, LV_GRAD_DIR_VER, 0);
    lv_obj_set_style_bg_opa(medal, LV_OPA_COVER, 0);
    lv_obj_set_style_border_color(medal, color, 0);
    lv_obj_set_style_border_width(medal, 3, 0);

    lv_obj_t* medal_label = create_label(_panel, &pokemon_font_10);
    lv_label_set_text(medal_label, name);
    lv_obj_set_style_text_color(medal_label, color, 0);
    lv_obj_align_to(medal_label, medal, LV_ALIGN_OUT_BOTTOM_MID, 0, 2);
  }

  if (new_best) {
    lv_obj_t* record = create_label(_panel, &pokemon_font_10);
    lv_label_set_text(record, _("game.bird.highscore"));
    lv_obj_set_style_text_color(record, lv_color_make(255, 205, 50), 0);
    lv_obj_align(record, LV_ALIGN_BOTTOM_MID, 0, -12);
  }

  lv_obj_t* hint = create_label(_panel, &pokemon_font_10);
  lv_label_set_text(hint, _("game.bird.retry"));
  lv_obj_align(hint, LV_ALIGN_BOTTOM_MID, 0, 4);

  if (new_best) {
    hal_beep(2400, 120);
  }

  serial_printf("FloppyBird", "Game over, score: %d, best: %d", (int)_score, (int)_best_score);
}

/**
 * Move the LVGL objects to the state of the game
 */
void Runner::render(void) {
  // Tilt with the speed: up when flapping, nose down when falling
  float angle = _state == STATE_READY ? 0 : LV_MAX(-25.0f, LV_MIN(_velocity / MAX_FALL_VELOCITY * 80.0f, 80.0f));
  const lv_image_dsc_t* frame = _wing_up && _state != STATE_GAME_OVER ? &bird_wing_up : &bird_wing_down;
  if (lv_image_get_src(_bird) != frame) {
    lv_image_set_src(_bird, frame);
  }
  lv_image_set_rotation(_bird, (int32_t)(angle * 10));
  lv_obj_set_pos(_bird, BIRD_X - frame->header.w / 2, (int32_t)_bird_y - frame->header.h / 2);

  lv_obj_set_x(_ground, -((int32_t)_ground_offset % GROUND_TILE));

  for (uint8_t i = 0; i < FLOPPYBIRD_PIPES; i++) {
    Pipe& pipe = _pipes[i];
    int32_t x = (int32_t)pipe.x;
    int32_t gap_top = pipe.gap_y - pipe.gap / 2;
    int32_t gap_bottom = pipe.gap_y + pipe.gap / 2;

    lv_obj_set_pos(pipe.top, x, -2);
    lv_obj_set_pos(pipe.top_cap, x - PIPE_CAP_OVERHANG, gap_top - PIPE_CAP_HEIGHT);
    lv_obj_set_pos(pipe.bottom_cap, x - PIPE_CAP_OVERHANG, gap_bottom);
    lv_obj_set_pos(pipe.bottom, x, gap_bottom + PIPE_CAP_HEIGHT - 2);
    lv_obj_set_pos(pipe.berry, x + PIPE_WIDTH / 2 - object_berry.header.w / 2, pipe.gap_y - object_berry.header.h / 2);
  }

  if (_score != _shown_score) {
    _shown_score = _score;
    lv_label_set_text_fmt(_score_label, "%d", (int)_score);
  }
}
