#pragma once
#ifndef KEYBOARD_HAL_H
#define KEYBOARD_HAL_H

bool hal_button_a_pressed(void);
bool hal_button_b_pressed(void);
bool hal_button_c_pressed(void);
// Short press, released before the hold time, and long press of C
bool hal_button_c_clicked(void);
bool hal_button_c_held(void);

#endif /*STORAGE_HAL_H*/