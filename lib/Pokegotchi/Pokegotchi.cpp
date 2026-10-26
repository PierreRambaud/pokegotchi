#include "Pokegotchi.h"
#include "Game.h"
#include "ActionsMenu.h"
#include "GameMenu.h"
#include "Utils.h"
#include "conf/poke_conf_hal.h"
#include "storage_hal.h"
#include "keyboard_hal.h"
#include "GameSwitcher.h"

using namespace Pokegotchi;

void prepare_storage_directory(poke_config_t*);

poke_options_t* Runner::_resume_options = nullptr;

Runner::Runner(bool resume) {
  _config = poke_config;
  _last_activity = hal_millis();

  lv_obj_t* main_screen = create_screen();
  // Delete the previous screen once this one is loaded
  lv_screen_load_anim(main_screen, LV_SCREEN_LOAD_ANIM_NONE, 0, 0, true);

  Pokemon* p = Pokemon::getInstance();
  if (resume && p != nullptr && _resume_options != nullptr) {
    serial_printf("Runner", "Back to the Pokemon");
    Game* g = new Game(_config, main_screen, p, _resume_options);
    Game::setInstance(g);

    int32_t score;
    if (GameSwitcher::Runner::getInstance()->take_minigame_result(&score)) {
      g->apply_minigame_reward(score);
    }
    return;
  }

  prepare_storage_directory(_config);
  Home::setInstance(new Home(_config, main_screen));
}

void Runner::close(void) {
  serial_printf("Runner", "Closing and cleaning up...");

  Home::releaseInstance();

  if (Game::getInstance() != nullptr) {
    _resume_options = Game::getInstance()->get_options();
    Game::destroyInstance();
  }

  lv_obj_clean(lv_screen_active());
}

void Runner::update_idle_dimming(void) {
  bool activity = hal_user_activity();
  if (Game::getInstance() != nullptr && Game::getInstance()->take_attention_request()) {
    activity = true;
  }

  if (activity) {
    _last_activity = hal_millis();
    if (_dimmed) {
      _dimmed = false;
      Game* g = Game::getInstance();
      set_lcd_brightness(g != nullptr ? g->get_options()->brightness : OPTIONS_BRIGHTNESS_DEFAULT);
    }
  } else if (!_dimmed && hal_millis() - _last_activity > IDLE_DIM_DELAY) {
    _dimmed = true;
    hal_set_brightness(IDLE_BRIGHTNESS);
  }
}

void Runner::loop(void) {
  update_idle_dimming();

  // Home deletes itself (releaseInstance) when a game starts, so never keep
  // a local copy of the pointer: always ask the singleton.
  Home* home = Home::getInstance();
  if (home != nullptr) {
    home->load_buttons();

    return;
  }

  Game::getInstance()->loop();
  if (check_action_time(_last_refresh_time, PERIOD_REFRESH)) {
    ActionsMenu::getInstance()->get_menu()->refresh_battery_status();
    GameMenu::getInstance()->get_menu()->refresh_battery_status();
  }

  if (hal_button_a_pressed()) {
    serial_printf("Runner", "Button A pressed");
    ActionsMenu::getInstance()->toggle();
    GameMenu::getInstance()->close();
  } else if (hal_button_b_pressed()) {
    serial_printf("Runner", "Button B pressed");
    Game::getInstance()->abort_actions();
  } else if (hal_button_c_pressed()) {
    serial_printf("Runner", "Button C pressed");
    ActionsMenu::getInstance()->close();
    GameMenu::getInstance()->toggle();
  }
}

void prepare_storage_directory(poke_config_t* global_config) {
  if (!global_config->use_storage) {
    return;
  }

  serial_printf("Runner", "Storage available");
  hal_prepare_storage(global_config);
}
