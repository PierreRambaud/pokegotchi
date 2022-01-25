#ifndef POKEGOTCHI_POKEMON
#define POKEGOTCHI_POKEMON

#include <lvgl.h>

struct pokemon_data {
  char name[20];

  int8_t level = 1;
  int8_t life = 100;
  int8_t mood = 10;
  int8_t hungry = 0;
};

class Pokemon {
 public:
  static Pokemon* getInstance() {
    if (instance == nullptr) {
      instance = new Pokemon();
    }

    return instance;
  }

 private:
  Pokemon();
  static Pokemon* instance;

  pokemon_data* _data;

  lv_obj_t* _image;
};
#endif
