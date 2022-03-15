#pragma once
#ifndef POKEGOTCHI_GAME
#define POKEGOTCHI_GAME

#include <vector>
#include <lvgl.h>
#include "ActionsMenu.h"
#include "Config.h"
#include "Options.h"
#include "Pokemon.h"

namespace Pokegotchi {
  class Game {
   public:
    Game(poke_config_t*, lv_obj_t*, Pokemon* p);
    Game(poke_config_t*, lv_obj_t*, Pokemon* p, poke_options_t*);

    void loop();
    void switch_to_day();
    void switch_to_night();

    static Game* getInstance() { return _instance; }
    static void setInstance(Game* instance) { _instance = instance; }

    void action_eat(BagItem* item);
    void action_clean();
    void action_heal();
    void action_play();
    void action_train();
    void action_sleep();
    void action_wake_up();

    void create_poo();
    void create_pee();

    void abort_actions();
    void try_to_clean();

    poke_options_t* get_options() { return _options; }
    poke_config_t* get_config() { return _config; }

   private:
    static Game* _instance;

    poke_config_t* _config;
    poke_options_t* _options = new poke_options_t{OPTIONS_BRIGHTNESS_DEFAULT};

    lv_obj_t* _main_screen;
    lv_obj_t* _screen;
    lv_anim_t _anim;

    lv_obj_t* _pokemon_image;
    lv_obj_t* _level_indic;
    lv_obj_t* _mood_bar;
    lv_obj_t* _sleepiness_bar;
    lv_obj_t* _hunger_bar;
    lv_obj_t* _life_bar;

    lv_obj_t* _clean;

    std::vector<lv_obj_t*> _poos;
    std::vector<lv_obj_t*> _pees;
  };
}  // namespace Pokegotchi
#endif
