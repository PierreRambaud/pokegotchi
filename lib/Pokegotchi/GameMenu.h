#pragma once
#ifndef POKEGOTCHI_GAMEMENU
#define POKEGOTCHI_GAMEMENU

#include <lvgl.h>
#include "Menu.h"
#include "Options.h"

#define BAG_ITEMS_SIZE 15

namespace Pokegotchi {
  class GameMenu {
   public:
    explicit GameMenu(Menu*);
    void display_pokemon();
    void display_options();
    void display_games();
    void change_ball(uint16_t);

    void close() {
      if (lv_obj_is_valid(_menu_child_screen)) {
        // Remove sub menu anyway
        lv_obj_del(_menu_child_screen);
      }

      _menu->close();
      Serial.println("Hide GameMenu");
    }
    void toggle() {
      if (lv_obj_has_flag(_menu->get_screen(), LV_OBJ_FLAG_HIDDEN)) {
        _menu->open();
      } else {
        close();
      }
    }

    static GameMenu* getInstance() { return _instance; }
    static void setInstance(GameMenu* instance) { _instance = instance; }

    Menu* get_menu() { return _menu; }

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
