#ifndef POKEGOTCHI_HOME
#define POKEGOTCHI_HOME

#include "lvgl.h"
#include "SdConfig.h"
#include "Config.h"

namespace Pokegotchi {
  class Home {
   public:
    explicit Home(poke_config_t*, lv_obj_t*);
    ~Home();
    void load_buttons();
    void close();

    bool isClosed() { return _closed; }

    static Home* getInstance() { return _instance; }
    static void setInstance(Home* instance) { _instance = instance; }
    static void releaseInstance() {
      if (_instance != nullptr) {
        _instance->close();
        delete _instance;
        _instance = nullptr;
      }
    }

    poke_config_t* get_config() { return _config; }
    lv_obj_t* get_main_screen() { return _main_screen; }

   private:
    static Home* _instance;

    SdConfig* _sd_config;
    poke_config_t* _config;

    bool _loaded = false;
    bool _closed = false;

    lv_obj_t* _main_screen;
    lv_obj_t* _screen;
    lv_obj_t* _title;
  };
}  // namespace Pokegotchi
#endif
