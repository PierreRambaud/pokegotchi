#include "keyboard_hal.h"
#include "M5Unified.h"

bool hal_button_a_pressed(void) { return M5.BtnA.wasPressed(); }

bool hal_button_b_pressed(void) { return M5.BtnB.wasPressed(); }

bool hal_button_c_pressed(void) { return M5.BtnC.wasPressed(); }

bool hal_button_c_clicked(void) { return M5.BtnC.wasClicked(); }

bool hal_button_c_held(void) { return M5.BtnC.wasHold(); }
