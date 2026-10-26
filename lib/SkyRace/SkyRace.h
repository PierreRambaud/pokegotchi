#pragma once
#ifndef SKYRACE_RUNNER
#define SKYRACE_RUNNER

#include "M5Unified.h"
#include "Preferences.h"
#include "GameInterface.h"

#define SKYRACE_MAX_OBJECTS 24
#define SKYRACE_FLYERS 3
#define SKYRACE_CLOUDS 5

namespace SkyRace {
  enum State : uint8_t { STATE_TITLE, STATE_COUNTDOWN, STATE_PLAY, STATE_GAME_OVER };

  enum ObjectType : uint8_t { OBJECT_NONE, OBJECT_RING, OBJECT_STORM, OBJECT_BERRY };

  enum Flyer : uint8_t { FLYER_ARTICUNO, FLYER_LATIOS, FLYER_LATIAS };

  struct SkyObject {
    float x;
    float y;
    float z;
    ObjectType type;
    bool collected;
  };

  struct Theme {
    uint16_t sky_top;
    uint16_t sky_horizon;
    uint16_t ground_a;
    uint16_t ground_b;
  };

  /**
   * Pseudo-3D flying game: tilt the Core2 to fly a legendary Pokemon through
   * rings, dodge storm clouds and catch Oran berries.
   */
  class Runner : public GameSwitcher::GameInterface {
   public:
    explicit Runner(void);
    ~Runner(void);

    void loop(void);
    void close(void);

   private:
    void create_flyer_sprites(void);
    void select_flyer(Flyer flyer);
    void start_countdown(void);
    void start_play(void);
    void end_game(void);

    void read_tilt(float* roll, float* pitch);
    void update_controls(float dt);
    void update_play(float dt);
    void update_spawner(float dt);
    void spawn_ring_chain(void);
    void spawn_object(ObjectType type, float x, float y, float z);
    void check_crossing(SkyObject& object);
    float distance_to_player(const SkyObject& object) const;

    bool project(float x, float y, float z, float* sx, float* sy, float* scale);

    void draw_title(void);
    void draw_countdown(void);
    void draw_play(void);
    void draw_game_over(void);
    void draw_background(void);
    void draw_clouds(void);
    void draw_object(const SkyObject& object);
    void draw_player(void);
    void draw_hud(void);
    void draw_heart(int32_t x, int32_t y, uint16_t color);
    void draw_centered(const char* text, int32_t y, const lgfx::IFont* font, uint16_t color);

    M5Canvas _canvas;
    M5Canvas _flyer_sprites[SKYRACE_FLYERS];
    Preferences _preferences;

    State _state = STATE_TITLE;
    Flyer _flyer = FLYER_LATIOS;
    const Theme* _theme;

    SkyObject _objects[SKYRACE_MAX_OBJECTS];
    float _clouds_x[SKYRACE_CLOUDS];

    uint32_t _last_frame = 0;
    float _state_time = 0;
    bool _first_loop = true;
    bool _needs_redraw = true;

    // Calibration: the neutral position is the one held during the countdown
    float _roll_zero = 0;
    float _pitch_zero = 0;
    float _calibration_roll = 0;
    float _calibration_pitch = 0;
    uint16_t _calibration_samples = 0;
    bool _invert_pitch = false;

    // Player, in pixels on the player plane (0, 0 is the center)
    float _player_x = 0;
    float _player_y = 0;
    float _velocity_x = 0;
    float _velocity_y = 0;

    float _speed = 0;
    float _distance = 0;
    float _spawn_timer = 0;
    float _invulnerable = 0;
    float _shake = 0;

    int32_t _score = 0;
    int32_t _best_score = 0;
    int32_t _session_best = 0;
    bool _new_best = false;
    uint8_t _combo = 0;
    uint8_t _lives = 0;
  };
}  // namespace SkyRace
#endif
