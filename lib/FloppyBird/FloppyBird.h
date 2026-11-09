#pragma once
#ifndef FLOPPYBIRD_RUNNER
#define FLOPPYBIRD_RUNNER

#include "lvgl.h"
#include "GameInterface.h"

#define FLOPPYBIRD_PIPES 3

namespace FloppyBird {
  enum State : uint8_t { STATE_READY, STATE_PLAY, STATE_FALLING, STATE_GAME_OVER };

  struct Pipe {
    float x;
    int32_t gap_y;
    int32_t gap;
    bool scored;
    bool has_berry;
    lv_obj_t* top;
    lv_obj_t* top_cap;
    lv_obj_t* bottom;
    lv_obj_t* bottom_cap;
    lv_obj_t* berry;
  };

  /**
   * Fly a little bird between the pipes: tap the screen or press B to flap.
   * Built with LVGL, so it runs on the device and on the emulator.
   */
  class Runner : public GameSwitcher::GameInterface {
   public:
    explicit Runner(void);

    void loop(void);
    void close(void);

   private:
    void create_scene(void);
    void create_pipe(Pipe& pipe);
    void reset(void);
    void place_pipe(Pipe& pipe, float x);
    void flap(void);
    void step(float dt);
    void crash(void);
    void show_game_over(void);
    void render(void);
    bool collides(const Pipe& pipe);

    static void pressed_cb(lv_event_t* e);

    lv_obj_t* _screen;
    lv_obj_t* _bird;
    lv_obj_t* _ground;
    lv_obj_t* _score_label;
    lv_obj_t* _hint_label;
    lv_obj_t* _flash;
    lv_obj_t* _panel = nullptr;
    Pipe _pipes[FLOPPYBIRD_PIPES];

    State _state = STATE_READY;
    bool _flap_requested = false;
    unsigned long _last_frame = 0;
    float _accumulator = 0;
    float _state_time = 0;
    float _wing_time = 0;
    bool _wing_up = false;

    float _bird_y = 0;
    float _velocity = 0;
    float _speed = 0;
    float _ground_offset = 0;

    int32_t _score = 0;
    int32_t _shown_score = -1;
    int32_t _best_score = 0;
    int32_t _session_best = 0;
  };
}  // namespace FloppyBird
#endif
