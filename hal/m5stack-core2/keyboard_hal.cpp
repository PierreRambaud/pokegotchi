#include "keyboard_hal.h"
#include "M5Core2.h"

bool hal_button_a_pressed() { return M5.BtnA.wasPressed(); }

bool hal_button_b_pressed() { return M5.BtnB.wasPressed(); }

bool hal_button_c_pressed() { return M5.BtnC.wasPressed(); }
