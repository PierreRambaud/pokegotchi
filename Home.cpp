#include "includes/lodepng.h"
#include <lvgl.h>
#include "assets/homescreen.c"
#include "assets/pokegotchi_title.c"
#include "Home.h"
#include "Utils.h"


Home::Home() {
  _screen = create_window();
  lv_scr_load(_screen);

  LV_IMG_DECLARE(homescreen);
  _background = lv_img_create(_screen);
  lv_img_set_src(_background, &homescreen);
  lv_obj_set_pos(_background, 0, 0);

  LV_IMG_DECLARE(pokegotchi_title);
  _title = lv_img_create(_screen);
  lv_img_set_src(_title, &pokegotchi_title);
  lv_obj_align(_title, LV_ALIGN_TOP_MID, 0, -50);
}

void Home::loop() {
  if (_title_position < 50) {
    _title_position += 5;
    lv_obj_align(_title, LV_ALIGN_TOP_MID, 0, _title_position);
  } else {
    startButton();
  }
}

void Home::startButton() {
  lv_obj_t * label;
  lv_obj_t * start_button = lv_btn_create(_screen);
  lv_obj_align(start_button, LV_ALIGN_CENTER, 0, 40);
  lv_obj_add_flag(start_button, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_height(start_button, LV_SIZE_CONTENT);

  label = lv_label_create(start_button);
  lv_label_set_text(label, "Start");
  lv_obj_center(label);
}


void Home::destroy() {
  lv_obj_del(_screen);
}
