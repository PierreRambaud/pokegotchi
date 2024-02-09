#pragma once
#ifndef UTILS_HAL_H
#define UTILS_HAL_H

#include "lvgl.h"

void hal_printf(const char* context, char* buffer);
void hal_set_brightness(int32_t value);
unsigned long hal_millis(void);

bool hal_battery_is_charging(void);
float hal_battery_level();

#endif /*UTILS_HAL_H*/