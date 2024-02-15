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
  class Game {
   public:
    Game(poke_config_t*, lv_obj_t*, Pokemon* p);
    Game(poke_config_t*, lv_obj_t*, Pokemon* p, poke_options_t*);

    void loop(void);
    void switch_to_day(void);
    void switch_to_night(void);

    static Game* getInstance(void) { return _instance; }
    static void setInstance(Game* instance) { _instance = instance; }

    void action_eat(BagItem* item);
    void action_clean(void);
    void action_heal(void);
    void action_play(void);
    void action_train(void);
    void action_sleep(void);
    void action_wake_up(void);

    void create_poo(void);
    void create_pee(void);

    void abort_actions(void);
    void try_to_clean(void);
    void put_in_pokeball(void);

    poke_options_t* get_options(void) { return _options; }
    poke_config_t* get_config(void) { return _config; }

   private:
    static Game* _instance;
    void _initialize(poke_config_t*, lv_obj_t*, Pokemon* p);

    poke_config_t* _config;
    poke_options_t* _options;

    lv_obj_t* _main_screen;
    lv_obj_t* _screen;
    lv_anim_t _anim;

    lv_obj_t* _pokemon_image;
    lv_obj_t* _pokemon_ball;
    lv_obj_t* _level_indic;
    lv_obj_t* _mood_bar;
    lv_obj_t* _sleepiness_bar;
    lv_obj_t* _hunger_bar;
    lv_obj_t* _life_bar;

    lv_obj_t* _clean;

    bool game_over = false;

    std::vector<lv_obj_t*> _poos;
    std::vector<lv_obj_t*> _pees;
  };
}  // namespace Pokegotchi
#endif
