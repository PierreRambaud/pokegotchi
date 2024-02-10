#pragma once
#ifndef POKEGOTCHI_GAMEMENU
#define POKEGOTCHI_GAMEMENU

#include "lvgl.h"
#include "Menu.h"
#include "Options.h"

#define BAG_ITEMS_SIZE 15

LV_IMG_DECLARE(ball_dream)
LV_IMG_DECLARE(ball_fast)
LV_IMG_DECLARE(ball_hyper)
LV_IMG_DECLARE(ball_love)
LV_IMG_DECLARE(ball_master)
LV_IMG_DECLARE(ball_memory)
LV_IMG_DECLARE(ball_moon)
LV_IMG_DECLARE(ball_poke)
LV_IMG_DECLARE(ball_super)

static const lv_image_dsc_t* balls_choice_images[9] = {
    &ball_poke, &ball_super, &ball_hyper, &ball_master, &ball_love, &ball_fast, &ball_memory, &ball_moon, &ball_dream,
};

namespace Pokegotchi {
  class GameMenu {
   public:
    explicit GameMenu(Menu*);
    void display_games(void);
    void display_options(void);
    void display_pokemon(void);
    void display_saves(void);
    void change_ball(uint16_t);

    void close(void) {
      if (lv_obj_is_valid(_menu_child_screen)) {
        // Remove sub menu anyway
        lv_obj_delete(_menu_child_screen);
      }

      _menu->close();
      serial_printf("GameMenu", "Hide GameMenu");
    }
    void toggle(void) {
      if (lv_obj_has_flag(_menu->get_screen(), LV_OBJ_FLAG_HIDDEN)) {
        _menu->open();
      } else {
        close();
      }
    }

    static GameMenu* getInstance(void) { return _instance; }
    static void setInstance(GameMenu* instance) { _instance = instance; }

    Menu* get_menu(void) { return _menu; }

   private:
    static GameMenu* _instance;

    Menu* _menu;
    poke_options_t* _options;

    lv_obj_t* _menu_screen;
    lv_obj_t* _menu_child_screen;

    lv_obj_t* _ball_image;
  };
}  // namespace Pokegotchi
#endif
