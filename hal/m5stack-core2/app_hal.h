#ifndef DRIVER_H
#define DRIVER_H

#include "lvgl.h"

void hal_setup(void);
void hal_loop(void);
void hal_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);

#endif /*DRIVER_H*/