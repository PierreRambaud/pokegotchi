#ifdef POKEGOTCHI_INCLUDE_GAMES
#include <math.h>
#include "lvgl.h"
#include "lv_i18n.h"
#include "Utils.h"
#include "SkyRace.h"

using namespace SkyRace;

#define SCREEN_W 320
#define SCREEN_H 240
#define CENTER_X 160
// Vanishing point / horizon height
#define HORIZON_Y 96
// Player plane center is this far below the horizon
#define PLAYER_PLANE_Y 44
// Ground is this far below the horizon on the player plane
#define GROUND_Y 150

#define FRAME_MS 33
#define COUNTDOWN_SECONDS 3.0f

// Depths, in the same unit as the player plane pixels
#define Z_PLAYER 100.0f
#define Z_FAR 1600.0f
#define Z_CULL 30.0f

#define PLAYER_MAX_X 130.0f
#define PLAYER_MAX_Y 80.0f
#define PLAYER_RADIUS 14.0f
#define PLAYER_ZOOM 1.5f
#define TITLE_ZOOM 2.0f
#define PLAYER_MAX_VELOCITY_X 260.0f
#define PLAYER_MAX_VELOCITY_Y 200.0f
#define MAX_BANK_DEGREES 30.0f

// Tilt needed (in degrees from the calibrated position) for full speed
#define ROLL_FULL_DEGREES 25.0f
#define PITCH_FULL_DEGREES 20.0f
#define TILT_DEAD_ZONE 3.0f
// Flip one of these if an axis goes the wrong way on the device
#define ROLL_SIGN -1.0f
#define PITCH_SIGN -1.0f

// The ring must be clearly bigger than the sprite when it reaches the player,
// and it counts as long as the player center is inside its hole
#define RING_RADIUS 46.0f
#define RING_HOLE_RADIUS (RING_RADIUS * 0.8f)
// Rings closer than this are highlighted when the player is lined up
#define RING_HINT_DISTANCE 400.0f
#define RING_SPACING 150.0f
#define STORM_RADIUS 26.0f
#define BERRY_RADIUS 12.0f

#define START_SPEED 320.0f
#define SPEED_GAIN 9.0f
#define MAX_SPEED 760.0f
#define MAX_LIVES 3
#define MAX_COMBO 5
#define INVULNERABLE_SECONDS 1.2f

#define SPRITE_W 32
#define SPRITE_H 19
#define TRANSPARENT_COLOR 0x0120

static const char* const SPRITE_ARTICUNO[SPRITE_H] = {
    "..............KKKK..............", ".............KAAAAK.............", ".............KBBBBK.............", "..............KBBK..............", "K............KBBBBK............K",
    "LK..........KBBBBBBK..........KL", "LLK........KBBBBBBBBK........KLL", "KLLK......KLBBBBBBBBLK......KLLK", ".KLLKK...KLLBBBBBBBBLLK...KKLLK.", ".KLLLLKKKLLLLBBBBBBLLLLKKKLLLLK.",
    "..KLLLLLLLLLLBBBBBBLLLLLLLLLLK..", "...KLLLLLLLLKBBBBBBKLLLLLLLLK...", "....KKLLLLKK.KBBBBK.KKLLLLKK....", "......KKKK....KBBK....KKKK......", "..............KAAK..............",
    "..............KAAK..............", ".............KAAAAK.............", "..............KAAK..............", "..............K..K..............",
};

// Latios and Latias share the same shape, only the palette changes
static const char* const SPRITE_LATI[SPRITE_H] = {
    "..............KKKK..............", ".............KBBBBK.............", ".............KABBAK.............", "..............KBBK..............", ".............KBBBBK.............",
    "K...........KBBBBBBK...........K", "KK.........KBBBLLBBBK.........KK", "KBK.......KBBBLLLLBBBK.......KBK", ".KBK....KKBBBLLLLLLBBBKK....KBK.", ".KBBKKKKBBBBLLLLLLLLBBBBKKKKBBK.",
    "..KBBBBBBBBBLLLLLLLLBBBBBBBBBK..", "...KKBBBBBBBBLLLLLLBBBBBBBBKK...", ".....KKKBBBBBBLLLLBBBBBBKKK.....", "........KKBBBBBBBBBBBBKK........", "..........KBBBBBBBBBBK..........",
    ".........KBBK.KBBK.KBBK.........", "........KBAK...KK...KABK........", "........KAK..........KAK........", ".........K............K.........",
};

static const char* const* const FLYER_SPRITES[SKYRACE_FLYERS] = {SPRITE_ARTICUNO, SPRITE_LATI, SPRITE_LATI};

// Palette: outline, body, light, accent
static const uint8_t FLYER_PALETTES[SKYRACE_FLYERS][4][3] = {
    {{20, 30, 70}, {70, 140, 230}, {170, 225, 255}, {40, 80, 200}},
    {{20, 20, 40}, {70, 90, 200}, {235, 235, 245}, {220, 40, 50}},
    {{40, 20, 20}, {220, 70, 70}, {240, 235, 240}, {60, 100, 220}},
};

// Articuno flies over a snowfield, Latios and Latias over the sea
static const Theme THEME_SNOW = {M5.Display.color565(60, 110, 190), M5.Display.color565(200, 225, 245), M5.Display.color565(235, 245, 255), M5.Display.color565(190, 215, 240)};
static const Theme THEME_SEA = {M5.Display.color565(40, 100, 200), M5.Display.color565(170, 215, 245), M5.Display.color565(30, 120, 190), M5.Display.color565(20, 95, 165)};

static const uint16_t COLOR_RING = M5.Display.color565(250, 200, 40);
static const uint16_t COLOR_RING_LIGHT = M5.Display.color565(255, 240, 150);
static const uint16_t COLOR_RING_ALIGNED = M5.Display.color565(120, 240, 90);
static const uint16_t COLOR_STORM = M5.Display.color565(70, 70, 85);
static const uint16_t COLOR_STORM_LIGHT = M5.Display.color565(110, 110, 125);
static const uint16_t COLOR_BOLT = M5.Display.color565(255, 230, 60);
static const uint16_t COLOR_BERRY = M5.Display.color565(60, 110, 230);
static const uint16_t COLOR_LEAF = M5.Display.color565(60, 170, 70);
static const uint16_t COLOR_HEART = M5.Display.color565(230, 50, 60);
static const uint16_t COLOR_HEART_EMPTY = M5.Display.color565(90, 90, 100);
static const uint16_t COLOR_TEXT_SHADOW = M5.Display.color565(20, 30, 60);

static float clampf(float value, float min, float max) { return value < min ? min : (value > max ? max : value); }

static float random_float(float min, float max) { return min + (max - min) * (random(0, 10001) / 10000.0f); }

static float wrap_degrees(float angle) {
  while (angle > 180.0f) angle -= 360.0f;
  while (angle < -180.0f) angle += 360.0f;
  return angle;
}

/**
 * Map a tilt angle to [-1, 1] with a small dead zone around the neutral position
 */
static float tilt_to_axis(float degrees, float full_degrees) {
  if (fabsf(degrees) < TILT_DEAD_ZONE) {
    return 0;
  }

  float sign = degrees > 0 ? 1.0f : -1.0f;
  return clampf((fabsf(degrees) - TILT_DEAD_ZONE) / (full_degrees - TILT_DEAD_ZONE), 0, 1) * sign;
}

static uint16_t blend565(uint16_t from, uint16_t to, float amount) {
  uint8_t r1 = (from >> 11) & 0x1F, g1 = (from >> 5) & 0x3F, b1 = from & 0x1F;
  uint8_t r2 = (to >> 11) & 0x1F, g2 = (to >> 5) & 0x3F, b2 = to & 0x1F;

  uint8_t r = r1 + (r2 - r1) * amount;
  uint8_t g = g1 + (g2 - g1) * amount;
  uint8_t b = b1 + (b2 - b1) * amount;

  return (r << 11) | (g << 5) | b;
}

Runner::Runner(void) : _canvas(&M5.Display) {
  _canvas.setPsram(true);
  _canvas.setColorDepth(16);
  if (_canvas.createSprite(SCREEN_W, SCREEN_H) == nullptr) {
    serial_printf("SkyRace", "Unable to allocate the screen buffer");
  }

  create_flyer_sprites();

  _preferences.begin("skyrace", false);
  _best_score = _preferences.getInt("best", 0);
  _invert_pitch = _preferences.getBool("invert", false);

  for (uint8_t i = 0; i < SKYRACE_CLOUDS; i++) {
    _clouds_x[i] = i * (SCREEN_W / SKYRACE_CLOUDS) + random(0, 40);
  }

  _theme = &THEME_SEA;

  serial_printf("SkyRace", "Ready, best score: %d", _best_score);
}

Runner::~Runner(void) { close(); }

void Runner::close(void) {
  _canvas.deleteSprite();
  for (uint8_t i = 0; i < SKYRACE_FLYERS; i++) {
    _flyer_sprites[i].deleteSprite();
  }

  _preferences.end();
}

void Runner::create_flyer_sprites(void) {
  for (uint8_t f = 0; f < SKYRACE_FLYERS; f++) {
    M5Canvas& sprite = _flyer_sprites[f];
    sprite.setColorDepth(16);
    sprite.createSprite(SPRITE_W, SPRITE_H);
    sprite.fillSprite(TRANSPARENT_COLOR);
    sprite.setPivot(SPRITE_W / 2.0f, SPRITE_H / 2.0f);

    uint16_t palette[4];
    for (uint8_t c = 0; c < 4; c++) {
      palette[c] = M5.Display.color565(FLYER_PALETTES[f][c][0], FLYER_PALETTES[f][c][1], FLYER_PALETTES[f][c][2]);
    }

    for (uint8_t y = 0; y < SPRITE_H; y++) {
      for (uint8_t x = 0; x < SPRITE_W; x++) {
        switch (FLYER_SPRITES[f][y][x]) {
          case 'K':
            sprite.drawPixel(x, y, palette[0]);
            break;
          case 'B':
            sprite.drawPixel(x, y, palette[1]);
            break;
          case 'L':
            sprite.drawPixel(x, y, palette[2]);
            break;
          case 'A':
            sprite.drawPixel(x, y, palette[3]);
            break;
        }
      }
    }
  }
}

void Runner::loop(void) {
  if (_first_loop) {
    // Flush what LVGL still has to draw from the previous screen before
    // taking over the display
    lv_refr_now(NULL);
    _first_loop = false;
  }

  uint32_t now = millis();
  if (_last_frame != 0 && now - _last_frame < FRAME_MS) {
    return;
  }

  float dt = _last_frame == 0 ? FRAME_MS / 1000.0f : min(now - _last_frame, (uint32_t)100) / 1000.0f;
  _last_frame = now;
  _state_time += dt;

  switch (_state) {
    case STATE_TITLE: {
      if (M5.BtnA.wasPressed()) {
        select_flyer(FLYER_ARTICUNO);
      } else if (M5.BtnB.wasPressed()) {
        select_flyer(FLYER_LATIOS);
      } else if (M5.BtnC.wasPressed()) {
        select_flyer(FLYER_LATIAS);
      } else {
        // Ignore the touch release of the menu button that opened the game
        auto touch = M5.Touch.getDetail();
        if (_state_time > 0.3f && touch.wasClicked() && touch.y < SCREEN_H) {
          _invert_pitch = !_invert_pitch;
          _preferences.putBool("invert", _invert_pitch);
        }
        draw_title();
      }
      break;
    }

    case STATE_COUNTDOWN: {
      // Average the tilt over the end of the countdown: that's the neutral position
      if (_state_time > 1.0f) {
        float roll, pitch;
        read_tilt(&roll, &pitch);
        _calibration_roll += roll;
        _calibration_pitch += pitch;
        _calibration_samples++;
      }

      _distance += START_SPEED * 0.5f * dt;

      if (_state_time >= COUNTDOWN_SECONDS) {
        start_play();
      } else {
        draw_countdown();
      }
      break;
    }

    case STATE_PLAY:
      update_play(dt);
      if (_state == STATE_PLAY) {
        draw_play();
      }
      break;

    case STATE_GAME_OVER:
      if (M5.BtnB.wasPressed()) {
        start_countdown();
      } else if (M5.BtnA.wasPressed()) {
        _state = STATE_TITLE;
        _state_time = 0;
      } else if (_needs_redraw) {
        draw_game_over();
        _needs_redraw = false;
      }
      break;
  }
}

void Runner::select_flyer(Flyer flyer) {
  _flyer = flyer;
  _theme = flyer == FLYER_ARTICUNO ? &THEME_SNOW : &THEME_SEA;
  start_countdown();
}

void Runner::start_countdown(void) {
  _state = STATE_COUNTDOWN;
  _state_time = 0;
  _calibration_roll = 0;
  _calibration_pitch = 0;
  _calibration_samples = 0;

  _player_x = 0;
  _player_y = 0;
  _velocity_x = 0;
  _velocity_y = 0;

  for (uint8_t i = 0; i < SKYRACE_MAX_OBJECTS; i++) {
    _objects[i].type = OBJECT_NONE;
  }
}

void Runner::start_play(void) {
  if (_calibration_samples > 0) {
    _roll_zero = _calibration_roll / _calibration_samples;
    _pitch_zero = _calibration_pitch / _calibration_samples;
  }

  serial_printf("SkyRace", "Calibrated roll: %.1f, pitch: %.1f", _roll_zero, _pitch_zero);

  _state = STATE_PLAY;
  _state_time = 0;
  _speed = START_SPEED;
  _spawn_timer = 0.3f;
  _invulnerable = 0;
  _shake = 0;
  _score = 0;
  _combo = 0;
  _lives = MAX_LIVES;
  _new_best = false;
}

void Runner::end_game(void) {
  _state = STATE_GAME_OVER;
  _state_time = 0;
  _needs_redraw = true;

  if (_score > _best_score) {
    _best_score = _score;
    _new_best = true;
    _preferences.putInt("best", _best_score);
  }

  serial_printf("SkyRace", "Game over, score: %d, best: %d", _score, _best_score);
}

/**
 * Read the device tilt, in degrees
 */
void Runner::read_tilt(float* roll, float* pitch) {
  float ax, ay, az;
  M5.Imu.getAccel(&ax, &ay, &az);

  *roll = atan2f(ax, sqrtf(ay * ay + az * az)) * RAD_TO_DEG;
  *pitch = atan2f(ay, az) * RAD_TO_DEG;
}

void Runner::update_controls(float dt) {
  float roll, pitch;
  read_tilt(&roll, &pitch);

  float axis_x = tilt_to_axis(wrap_degrees(roll - _roll_zero) * ROLL_SIGN, ROLL_FULL_DEGREES);
  float axis_y = tilt_to_axis(wrap_degrees(pitch - _pitch_zero) * PITCH_SIGN, PITCH_FULL_DEGREES);
  if (_invert_pitch) {
    axis_y = -axis_y;
  }

  // Smooth the velocity so the flight feels like gliding, not twitching
  float smoothing = clampf(dt * 7.0f, 0, 1);
  _velocity_x += (axis_x * PLAYER_MAX_VELOCITY_X - _velocity_x) * smoothing;
  _velocity_y += (axis_y * PLAYER_MAX_VELOCITY_Y - _velocity_y) * smoothing;

  _player_x = clampf(_player_x + _velocity_x * dt, -PLAYER_MAX_X, PLAYER_MAX_X);
  _player_y = clampf(_player_y + _velocity_y * dt, -PLAYER_MAX_Y, PLAYER_MAX_Y);
}

void Runner::update_play(float dt) {
  update_controls(dt);

  _speed = min(START_SPEED + SPEED_GAIN * _state_time, MAX_SPEED);
  _distance += _speed * dt;
  _invulnerable = max(_invulnerable - dt, 0.0f);
  _shake = max(_shake - dt, 0.0f);

  for (uint8_t i = 0; i < SKYRACE_CLOUDS; i++) {
    _clouds_x[i] -= _velocity_x * 0.04f * dt + 6.0f * dt;
    if (_clouds_x[i] < -50) {
      _clouds_x[i] += SCREEN_W + 100;
    } else if (_clouds_x[i] > SCREEN_W + 50) {
      _clouds_x[i] -= SCREEN_W + 100;
    }
  }

  for (uint8_t i = 0; i < SKYRACE_MAX_OBJECTS; i++) {
    SkyObject& object = _objects[i];
    if (object.type == OBJECT_NONE) {
      continue;
    }

    float previous_z = object.z;
    object.z -= _speed * dt;

    if (previous_z > Z_PLAYER && object.z <= Z_PLAYER) {
      check_crossing(object);
      if (_state != STATE_PLAY) {
        return;
      }
    }

    if (object.z < Z_CULL) {
      object.type = OBJECT_NONE;
    }
  }

  update_spawner(dt);
}

float Runner::distance_to_player(const SkyObject& object) const {
  float dx = object.x - _player_x;
  float dy = object.y - _player_y;
  return sqrtf(dx * dx + dy * dy);
}

void Runner::check_crossing(SkyObject& object) {
  float distance = distance_to_player(object);

  switch (object.type) {
    case OBJECT_RING:
      if (distance < RING_HOLE_RADIUS) {
        object.collected = true;
        _combo = min(_combo + 1, MAX_COMBO);
        _score += _combo;
        // Higher pitch as the combo grows
        M5.Speaker.tone(1400 + _combo * 200, 60);
      } else {
        _combo = 0;
      }
      break;

    case OBJECT_STORM:
      if (distance < STORM_RADIUS + PLAYER_RADIUS - 6 && _invulnerable <= 0) {
        _lives--;
        _combo = 0;
        _invulnerable = INVULNERABLE_SECONDS;
        _shake = 0.35f;
        M5.Speaker.tone(180, 200);
        if (_lives == 0) {
          end_game();
        }
      }
      break;

    case OBJECT_BERRY:
      if (distance < BERRY_RADIUS + PLAYER_RADIUS) {
        object.type = OBJECT_NONE;
        _lives = min(_lives + 1, MAX_LIVES);
        _score += 2;
        M5.Speaker.tone(2600, 80);
      }
      break;

    default:
      break;
  }
}

void Runner::update_spawner(float dt) {
  _spawn_timer -= dt;
  if (_spawn_timer > 0) {
    return;
  }

  // Patterns get closer to each other as the speed increases
  float pace = START_SPEED / _speed;
  int roll = random(0, 100);

  if (roll < 55) {
    spawn_ring_chain();
  } else if (roll < 90 || _lives >= MAX_LIVES) {
    uint8_t count = _speed > 500 ? random(1, 4) : random(1, 3);
    for (uint8_t i = 0; i < count; i++) {
      spawn_object(OBJECT_STORM, random_float(-PLAYER_MAX_X, PLAYER_MAX_X), random_float(-PLAYER_MAX_Y, PLAYER_MAX_Y), Z_FAR + i * 60.0f);
    }
    _spawn_timer = random_float(0.7f, 1.2f) * pace;
  } else {
    spawn_object(OBJECT_BERRY, random_float(-PLAYER_MAX_X, PLAYER_MAX_X), random_float(-PLAYER_MAX_Y, PLAYER_MAX_Y), Z_FAR);
    _spawn_timer = 0.8f * pace;
  }
}

/**
 * Spawn rings following a smooth curve, so the player can chain them
 */
void Runner::spawn_ring_chain(void) {
  uint8_t count = random(3, 6);
  float x = random_float(-PLAYER_MAX_X + 20, PLAYER_MAX_X - 20);
  float y = random_float(-PLAYER_MAX_Y + 20, PLAYER_MAX_Y - 20);
  float step_x = random_float(-35, 35);
  float step_y = random_float(-25, 25);

  for (uint8_t i = 0; i < count; i++) {
    spawn_object(OBJECT_RING, x, y, Z_FAR + i * RING_SPACING);

    x += step_x;
    y += step_y;
    if (x < -PLAYER_MAX_X + 20 || x > PLAYER_MAX_X - 20) {
      step_x = -step_x;
      x = clampf(x, -PLAYER_MAX_X + 20, PLAYER_MAX_X - 20);
    }
    if (y < -PLAYER_MAX_Y + 20 || y > PLAYER_MAX_Y - 20) {
      step_y = -step_y;
      y = clampf(y, -PLAYER_MAX_Y + 20, PLAYER_MAX_Y - 20);
    }
  }

  // Wait for the last ring to be on its way before the next pattern
  _spawn_timer = (count * RING_SPACING) / _speed + 0.35f;
}

void Runner::spawn_object(ObjectType type, float x, float y, float z) {
  for (uint8_t i = 0; i < SKYRACE_MAX_OBJECTS; i++) {
    if (_objects[i].type == OBJECT_NONE) {
      _objects[i] = SkyObject{x, y, z, type, false};
      return;
    }
  }
}

/**
 * Project a point of the world on the screen
 *
 * @return false if the point is too far to be drawn
 */
bool Runner::project(float x, float y, float z, float* sx, float* sy, float* scale) {
  if (z > Z_FAR || z < Z_CULL) {
    return false;
  }

  float shake_x = _shake > 0 ? random(-4, 5) : 0;
  float shake_y = _shake > 0 ? random(-3, 4) : 0;

  *scale = Z_PLAYER / z;
  *sx = CENTER_X + x * *scale + shake_x;
  *sy = HORIZON_Y + (PLAYER_PLANE_Y + y) * *scale + shake_y;

  return true;
}

void Runner::draw_background(void) {
  for (int32_t y = 0; y < HORIZON_Y; y++) {
    _canvas.drawFastHLine(0, y, SCREEN_W, blend565(_theme->sky_top, _theme->sky_horizon, (float)y / HORIZON_Y));
  }

  // Each ground line is a depth: alternate the stripes with the distance
  // travelled, and fade them into the horizon
  for (int32_t y = HORIZON_Y; y < SCREEN_H; y++) {
    float z = Z_PLAYER * GROUND_Y / (float)(y - HORIZON_Y + 1);
    uint16_t color = ((int32_t)((z + _distance) / 90.0f) & 1) ? _theme->ground_a : _theme->ground_b;
    _canvas.drawFastHLine(0, y, SCREEN_W, blend565(color, _theme->sky_horizon, clampf(z / (Z_FAR * 1.5f), 0, 1)));
  }
}

void Runner::draw_clouds(void) {
  for (uint8_t i = 0; i < SKYRACE_CLOUDS; i++) {
    int32_t x = _clouds_x[i];
    int32_t y = 18 + (i * 17) % 55;
    int32_t size = 10 + (i * 7) % 12;

    _canvas.fillEllipse(x, y, size * 2, size, TFT_WHITE);
    _canvas.fillEllipse(x + size, y + 3, size * 1.5, size * 0.8, TFT_WHITE);
  }
}

void Runner::draw_object(const SkyObject& object) {
  float sx, sy, scale;
  if (project(object.x, object.y, object.z, &sx, &sy, &scale) == false) {
    return;
  }

  switch (object.type) {
    case OBJECT_RING: {
      int32_t radius = max(RING_RADIUS * scale, 2.0f);
      int32_t thickness = max(radius / 5, (int32_t)1);
      uint16_t color = COLOR_RING;
      if (object.collected) {
        color = TFT_WHITE;
      } else if (object.z < Z_PLAYER + RING_HINT_DISTANCE && object.z > Z_PLAYER && distance_to_player(object) < RING_HOLE_RADIUS) {
        // Tell the player this ring will count if they keep the line
        color = COLOR_RING_ALIGNED;
      }
      _canvas.fillArc(sx, sy, radius - thickness, radius, 0, 360, color);
      if (thickness > 2) {
        _canvas.drawArc(sx, sy, radius - thickness / 2, radius - thickness / 2, 200, 340, COLOR_RING_LIGHT);
      }
      break;
    }

    case OBJECT_STORM: {
      int32_t radius = max(STORM_RADIUS * scale, 2.0f);
      _canvas.fillCircle(sx - radius * 0.55f, sy + radius * 0.15f, radius * 0.6f, COLOR_STORM);
      _canvas.fillCircle(sx + radius * 0.55f, sy + radius * 0.15f, radius * 0.6f, COLOR_STORM);
      _canvas.fillCircle(sx, sy - radius * 0.2f, radius * 0.75f, COLOR_STORM_LIGHT);

      if (radius > 8) {
        // Lightning bolt
        _canvas.fillTriangle(sx + radius * 0.1f, sy, sx - radius * 0.35f, sy + radius * 0.55f, sx + radius * 0.05f, sy + radius * 0.5f, COLOR_BOLT);
        _canvas.fillTriangle(sx + radius * 0.05f, sy + radius * 0.4f, sx + radius * 0.3f, sy + radius * 0.4f, sx - radius * 0.2f, sy + radius * 1.0f, COLOR_BOLT);
      }
      break;
    }

    case OBJECT_BERRY: {
      int32_t radius = max(BERRY_RADIUS * scale, 2.0f);
      _canvas.fillCircle(sx, sy, radius, COLOR_BERRY);
      _canvas.fillTriangle(sx, sy - radius, sx + radius * 0.8f, sy - radius * 1.4f, sx + radius * 0.3f, sy - radius * 0.6f, COLOR_LEAF);
      if (radius > 4) {
        _canvas.fillCircle(sx - radius * 0.35f, sy - radius * 0.35f, radius / 4, TFT_WHITE);
      }
      break;
    }

    default:
      break;
  }
}

void Runner::draw_player(void) {
  // Blink while invulnerable
  if (_invulnerable > 0 && ((int32_t)(_invulnerable * 10) & 1)) {
    return;
  }

  float sx, sy, scale;
  project(_player_x, _player_y, Z_PLAYER, &sx, &sy, &scale);

  float bank = _velocity_x / PLAYER_MAX_VELOCITY_X * MAX_BANK_DEGREES;
  // Flatten the sprite a bit when diving or climbing
  float pitch_zoom = PLAYER_ZOOM * (1.0f - fabsf(_velocity_y) / PLAYER_MAX_VELOCITY_Y * 0.2f);

  _flyer_sprites[_flyer].pushRotateZoom(&_canvas, sx, sy, bank, PLAYER_ZOOM, pitch_zoom, TRANSPARENT_COLOR);
}

void Runner::draw_heart(int32_t x, int32_t y, uint16_t color) {
  _canvas.fillCircle(x - 4, y, 4, color);
  _canvas.fillCircle(x + 4, y, 4, color);
  _canvas.fillTriangle(x - 8, y + 1, x + 8, y + 1, x, y + 10, color);
}

void Runner::draw_hud(void) {
  char buffer[32];

  _canvas.setFont(&fonts::DejaVu18);
  _canvas.setTextDatum(top_left);
  snprintf(buffer, sizeof(buffer), _("game.sky.score"), _score);
  _canvas.setTextColor(COLOR_TEXT_SHADOW);
  _canvas.drawString(buffer, 7, 5);
  _canvas.setTextColor(TFT_WHITE);
  _canvas.drawString(buffer, 6, 4);

  if (_combo > 1) {
    snprintf(buffer, sizeof(buffer), "x%d", _combo);
    _canvas.setTextColor(COLOR_RING);
    _canvas.drawString(buffer, 6, 26);
  }

  for (uint8_t i = 0; i < MAX_LIVES; i++) {
    draw_heart(SCREEN_W - 16 - i * 22, 10, i < _lives ? COLOR_HEART : COLOR_HEART_EMPTY);
  }
}

void Runner::draw_centered(const char* text, int32_t y, const lgfx::IFont* font, uint16_t color) {
  _canvas.setFont(font);
  _canvas.setTextDatum(middle_center);
  _canvas.setTextColor(COLOR_TEXT_SHADOW);
  _canvas.drawString(text, CENTER_X + 1, y + 1);
  _canvas.setTextColor(color);
  _canvas.drawString(text, CENTER_X, y);
}

void Runner::draw_title(void) {
  _distance += 60.0f * FRAME_MS / 1000.0f;
  draw_background();
  draw_clouds();

  draw_centered("SKY RACE", 30, &fonts::DejaVu40, TFT_WHITE);
  draw_centered(_("game.sky.choose"), 68, &fonts::DejaVu12, TFT_WHITE);

  // Each Pokemon is above its physical button: A, B and C
  const char* const names[SKYRACE_FLYERS] = {_("game.sky.articuno"), _("game.sky.latios"), _("game.sky.latias")};
  const char* const buttons[SKYRACE_FLYERS] = {"A", "B", "C"};
  for (uint8_t i = 0; i < SKYRACE_FLYERS; i++) {
    int32_t x = 55 + i * 105;
    float bob = sinf(_state_time * 3.0f + i) * 4.0f;
    _flyer_sprites[i].pushRotateZoom(&_canvas, x, 125 + bob, sinf(_state_time * 2.0f + i) * 8.0f, TITLE_ZOOM, TITLE_ZOOM, TRANSPARENT_COLOR);

    _canvas.setFont(&fonts::DejaVu12);
    _canvas.setTextDatum(middle_center);
    _canvas.setTextColor(TFT_WHITE);
    _canvas.drawString(names[i], x, 162);
    _canvas.setFont(&fonts::DejaVu18);
    _canvas.drawString(buttons[i], x, 182);
  }

  char buffer[32];
  snprintf(buffer, sizeof(buffer), _("game.sky.best"), _best_score);
  draw_centered(buffer, 206, &fonts::DejaVu12, COLOR_RING);
  draw_centered(_invert_pitch ? _("game.sky.invert.on") : _("game.sky.invert.off"), 226, &fonts::DejaVu9, TFT_WHITE);

  _canvas.pushSprite(&M5.Display, 0, 0);
}

void Runner::draw_countdown(void) {
  draw_background();
  draw_clouds();
  draw_player();

  char buffer[4];
  snprintf(buffer, sizeof(buffer), "%d", (int)(COUNTDOWN_SECONDS - _state_time) + 1);
  draw_centered(buffer, 60, &fonts::DejaVu56, TFT_WHITE);
  draw_centered(_("game.sky.calibrate"), 200, &fonts::DejaVu18, TFT_WHITE);
  draw_centered(_("game.sky.help"), 222, &fonts::DejaVu12, TFT_WHITE);

  _canvas.pushSprite(&M5.Display, 0, 0);
}

void Runner::draw_play(void) {
  draw_background();
  draw_clouds();

  // Painter's algorithm: draw from the farthest object to the nearest one,
  // with the player in between
  uint8_t order[SKYRACE_MAX_OBJECTS];
  uint8_t count = 0;
  for (uint8_t i = 0; i < SKYRACE_MAX_OBJECTS; i++) {
    if (_objects[i].type == OBJECT_NONE) {
      continue;
    }

    uint8_t j = count++;
    while (j > 0 && _objects[order[j - 1]].z < _objects[i].z) {
      order[j] = order[j - 1];
      j--;
    }
    order[j] = i;
  }

  bool player_drawn = false;
  for (uint8_t i = 0; i < count; i++) {
    const SkyObject& object = _objects[order[i]];
    if (player_drawn == false && object.z <= Z_PLAYER) {
      draw_player();
      player_drawn = true;
    }
    draw_object(object);
  }

  if (player_drawn == false) {
    draw_player();
  }

  draw_hud();

  _canvas.pushSprite(&M5.Display, 0, 0);
}

void Runner::draw_game_over(void) {
  _canvas.fillRect(30, 50, SCREEN_W - 60, 150, COLOR_TEXT_SHADOW);
  _canvas.drawRect(30, 50, SCREEN_W - 60, 150, TFT_WHITE);

  char buffer[32];
  draw_centered(_("game.sky.gameover"), 76, &fonts::DejaVu24, TFT_WHITE);

  snprintf(buffer, sizeof(buffer), _("game.sky.score"), _score);
  draw_centered(buffer, 110, &fonts::DejaVu18, TFT_WHITE);

  if (_new_best) {
    draw_centered(_("game.sky.newbest"), 136, &fonts::DejaVu18, COLOR_RING);
  } else {
    snprintf(buffer, sizeof(buffer), _("game.sky.best"), _best_score);
    draw_centered(buffer, 136, &fonts::DejaVu18, COLOR_RING);
  }

  draw_centered(_("game.sky.retry"), 176, &fonts::DejaVu12, TFT_WHITE);

  _canvas.pushSprite(&M5.Display, 0, 0);
}

#endif
