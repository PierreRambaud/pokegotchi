#ifndef DRIVER_H
#define DRIVER_H

#include "lvgl.h"

void hal_setup(void);
void hal_loop(void);
void hal_delay(uint32_t ms);
lv_display_t *hal_create_display(void);

#endif /*DRIVER_H*/