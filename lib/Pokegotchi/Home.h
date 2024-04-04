#ifndef POKEGOTCHI_HOME
#define POKEGOTCHI_HOME

#include "lvgl.h"
#include "Config.h"

namespace Pokegotchi {
  class Home {
   public:
    explicit Home(poke_config_t*, lv_obj_t*);
    ~Home(void);
    void load_buttons(void);
    void close(void);

    bool isClosed(void) { return _closed; }

    static Home* getInstance(void) { return _instance; }
    static void setInstance(Home* instance) { _instance = instance; }
    static void releaseInstance(void) {
      if (_instance != nullptr) {
        _instance->close();
        delete _instance;
        _instance = nullptr;
      }
    }

    poke_config_t* get_config(void) { return _config; }
    lv_obj_t* get_main_screen(void) { return _main_screen; }

   private:
    static Home* _instance;

    poke_config_t* _config;

    bool _loaded = false;
    bool _closed = false;

    lv_obj_t* _main_screen;
    lv_obj_t* _screen;
    lv_obj_t* _title;
  };
}  // namespace Pokegotchi
#endif
