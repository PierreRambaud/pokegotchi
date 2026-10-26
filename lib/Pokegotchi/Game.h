#pragma once
#ifndef POKEGOTCHI_GAME
#define POKEGOTCHI_GAME

#include <vector>
#include "lvgl.h"
#include "ActionsMenu.h"
#include "Config.h"
#include "Options.h"
#include "Pokemon.h"

namespace Pokegotchi {
  const unsigned long AUTOSAVE_PERIOD = 5 * 60 * 1000UL;
  const unsigned long CALL_REMINDER_PERIOD = 5 * 60 * 1000UL;
  const unsigned long EMOTE_DURATION = 1800;
  const unsigned long BACKGROUND_FRAME_DURATION = 120;

  enum Emote : uint8_t { EMOTE_NONE, EMOTE_HEART, EMOTE_EXCLAMATION, EMOTE_NOTE, EMOTE_ANGER, EMOTE_SWEAT, EMOTE_ZZZ, EMOTE_QUESTION, EMOTE_SICK };

  class Game {
   public:
    Game(poke_config_t*, lv_obj_t*, Pokemon* p);
    Game(poke_config_t*, lv_obj_t*, Pokemon* p, poke_options_t*);
    ~Game();

    void loop(void);

    static Game* getInstance(void) { return _instance; }
    static void destroyInstance(void) {
      if (_instance != nullptr) {
        delete _instance;
        _instance = nullptr;
      }
    }
    static void setInstance(Game* instance) { _instance = instance; }

    void action_eat(BagItem* item);
    void action_use_stone(Stone stone);
    void action_clean(void);
    void action_heal(void);
    void action_play(void);
    void action_train(void);
    void action_sleep(void);
    void action_wake_up(void);
    void action_pet(void);
    void apply_minigame_reward(int32_t score);

    void create_poo(void);
    void create_pee(void);

    void abort_actions(void);
    void try_to_clean(void);
    void put_in_pokeball(void);
    void release_from_pokeball(void);

    bool save(const char* path);
    void autosave(void);

    // True once when the Pokemon needs the player, to wake the screen up
    bool take_attention_request(void) {
      bool request = _attention_request;
      _attention_request = false;
      return request;
    }

    poke_options_t* get_options(void) { return _options; }
    poke_config_t* get_config(void) { return _config; }

   private:
    static Game* _instance;
    void _initialize(poke_config_t*, lv_obj_t*, Pokemon* p);

    void _handle_events(uint16_t events);
    void _update_background(void);
    void _show_background_frame(uint8_t frame);
    void _update_clock(void);
    void _update_bars(void);
    void _update_wandering(void);
    void _update_egg(void);
    void _update_steps(void);
    void _update_emote(void);
    void _show_emote(Emote emote);
    void _bounce(void);
    void _shake_head(void);
    void _show_pokemon(void);
    void _start_evolution(int from, int to);
    void _evolution_tick(void);
    lv_obj_t* _active_sprite(void);

    static void _evolution_timer_cb(lv_timer_t* timer);
    static void _pokemon_clicked_cb(lv_event_t* e);

    poke_config_t* _config;
    poke_options_t* _options;

    lv_obj_t* _main_screen;
    lv_obj_t* _screen;
    lv_obj_t* _background;

    lv_obj_t* _pokemon_image;
    lv_obj_t* _pokemon_ball;
    lv_obj_t* _egg_image;
    lv_obj_t* _steps_label;
    lv_obj_t* _emote;
    lv_obj_t* _clock_label;
    lv_obj_t* _level_indic;
    lv_obj_t* _mood_bar;
    lv_obj_t* _sleepiness_bar;
    lv_obj_t* _hunger_bar;
    lv_obj_t* _life_bar;

    lv_obj_t* _clean = nullptr;

    bool game_over = false;
    bool _attention_request = false;

    int16_t _last_mood = -1;
    int16_t _last_life = -1;
    int16_t _last_sleepiness = -1;
    int16_t _last_hunger = -1;
    int16_t _last_level = -1;
    // Background frame shown, and when to show the next one of a transition
    int8_t _background_frame = -1;
    unsigned long _next_background_frame = 0;
    int16_t _last_minute = -1;
    bool _shown_sick = false;
    int32_t _last_egg_steps = -1;
    int32_t _last_steps_today = -1;

    int32_t _pokemon_x = 0;
    unsigned long _next_move = 0;
    unsigned long _busy_until = 0;
    unsigned long _next_egg_wobble = 0;
    unsigned long _emote_until = 0;
    Emote _emote_shown = EMOTE_NONE;
    unsigned long _last_autosave = 0;
    unsigned long _last_call_reminder = 0;

    lv_timer_t* _evolution_timer = nullptr;
    uint8_t _evolution_step = 0;
    int _evolution_from = 0;
    int _evolution_to = 0;
    bool _evolution_showing_new = false;

    std::vector<lv_obj_t*> _poos;
    std::vector<lv_obj_t*> _pees;
  };
}  // namespace Pokegotchi
#endif
