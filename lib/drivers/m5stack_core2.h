#include "lvgl.h"
#include <Arduino.h>
#include <M5Core2.h>
#include "lv_port_fs_littlefs.h"

void driver_init();
void driver_loop();
void init_touch_driver();

void touchpad_read_cb(lv_indev_t *indev, lv_indev_data_t *data);
void display_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);