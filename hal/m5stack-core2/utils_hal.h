#pragma once
#ifndef UTILS_HAL_H
#define UTILS_HAL_H

#include "lvgl.h"

void hal_printf(const char* context, char* buffer);
void hal_set_brightness(int32_t value);
unsigned long hal_millis(void);

bool hal_battery_is_charging(void);
float hal_battery_level(void);

void hal_restart(void);

int hal_random(int min, int max);

// Local wall clock time, in seconds since 1970 (the RTC holds local time)
uint32_t hal_now(void);
void hal_set_now(uint32_t now);
void hal_init_clock(void);

void hal_vibrate(uint16_t duration_ms);
void hal_beep(uint16_t frequency, uint16_t duration_ms);
// Sound effects can be turned off in the options
void hal_set_sound(bool enabled);
bool hal_sound_enabled(void);
void hal_update_feedback(void);

// Motion from the accelerometer, read regularly by hal_update_motion
void hal_update_motion(void);
bool hal_shake_detected(void);
// Steps walked since the last call
uint16_t hal_take_steps(void);
bool hal_user_activity(void);

#endif /*UTILS_HAL_H*/
