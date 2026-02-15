#ifndef DRIVER_H
#define DRIVER_H

#include "lvgl.h"

void hal_setup(void);
void hal_loop(void);
lv_display_t *hal_create_display(void);

#endif /*DRIVER_H*/