#define ANALOG_PIN 35

#include "m5stack_core2.h"

M5Display *tft;

// Initialize driver
void driver_init() {
  randomSeed(analogRead(ANALOG_PIN));
  M5.begin(true, false);

  lv_port_littlefs_init();

  tft = &M5.Lcd;
}

// driver loop behavior
void driver_loop() { M5.update(); }

// Initialize the touch screen
void init_touch_driver() {
  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, touchpad_read_cb);
}

/**
 * @param lv_indev_t *indev
 * @param lv_indev_data_t *data
 *
 * @return void
 */
void touchpad_read_cb(lv_indev_t *indev, lv_indev_data_t *data) {
  TouchPoint_t pos = M5.Touch.getPressPoint();

  bool touched = (pos.x <= 0 || pos.y <= 0 || pos.x >= LV_HOR_RES_MAX || pos.y >= LV_VER_RES_MAX) ? false : true;
  if (!touched) {
    data->state = LV_INDEV_STATE_RELEASED;
  } else {
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = pos.x;
    data->point.y = pos.y;
  }
}

/**
 * @param lv_display_t *disp
 * @param const lv_area_t *area
 * @param const uint8_t *px_map
 *
 * @return void
 */
void display_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft->startWrite();
  tft->setAddrWindow(area->x1, area->y1, w, h);
  tft->pushColors((uint16_t *)px_map, w * h, true);
  tft->endWrite();

  lv_display_flush_ready(disp);
}