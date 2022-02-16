#ifndef POKEGOTCHI_HOME
#define POKEGOTCHI_HOME

#include <lvgl.h>

class Home {
 public:
  ~Home();
  void loop();
  void close();

  bool isClosed() { return _closed; }

  static Home* getInstance() {
    if (instance == nullptr) {
      instance = new Home();
    }

    return instance;
  }

 private:
  Home();

  static Home* instance;

  bool _has_save_file = false;
  bool _loaded = false;
  bool _closed = false;

  lv_obj_t* _screen;
  lv_obj_t* _title;
};
#endif
