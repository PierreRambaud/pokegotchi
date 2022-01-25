#include <lvgl.h>
#include "Pokemon.h"
#include "assets/pokemon/172.c"

Pokemon* Pokemon::instance = nullptr;

Pokemon::Pokemon() {
  LV_IMG_DECLARE(pokemon_172);

  _image = lv_gif_create(lv_scr_act());
  lv_gif_set_src(_image, &pokemon_172);
  lv_obj_align(_image, LV_ALIGN_CENTER, 0, 0);
};
