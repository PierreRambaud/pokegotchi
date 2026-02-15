#define ANALOG_PIN 35
#include "lvgl.h"
#include "Arduino.h"
#include "M5Unified.h"
#include "app_hal.h"

/**
 * @param lv_display_t *disp
 * @param const lv_area_t *area
 * @param const uint8_t *px_map
 *
 * @return void
 */
void flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  M5.Display.startWrite();
  M5.Display.setAddrWindow(area->x1, area->y1, w, h);
  M5.Display.pushPixels((uint16_t *)px_map, w * h, true);
  M5.Display.endWrite();

  lv_display_flush_ready(disp);
}

lv_display_t *hal_create_display(void) {
  lv_display_t *display = lv_display_create(LV_HOR_RES_MAX, LV_VER_RES_MAX);
  lv_display_set_flush_cb(display, flush_cb);

  return display;
}

/**
 * @param lv_indev_t *indev
 * @param lv_indev_data_t *data
 *
 * @return void
 */
void touchpad_read_cb(lv_indev_t *indev, lv_indev_data_t *data) {
  static int16_t last_x = 0;
  static int16_t last_y = 0;

  auto touch = M5.Touch.getDetail();

  if (touch.isPressed()) {
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = touch.x;
    data->point.y = touch.y;
    last_x = touch.x;
    last_y = touch.y;
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
    data->point.x = last_x;
    data->point.y = last_y;
  }
}

// Initialize the touch screen
void init_touch_driver(void) {
  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, touchpad_read_cb);
}

// Initialize hal
void hal_setup(void) {
  randomSeed(analogRead(ANALOG_PIN));

  auto cfg = M5.config();

  // Configure M5Unified - these are the correct settings
  cfg.clear_display = true;
  cfg.output_power = true;
  cfg.internal_imu = true;
  cfg.internal_rtc = true;
  cfg.internal_spk = true;
  cfg.internal_mic = true;

  M5.begin(cfg);

  // Initialize display
  M5.Display.begin();
  M5.Display.setRotation(1);
  M5.Display.fillScreen(TFT_BLACK);

  Serial.begin(115200);
  Serial.println("M5Stack Core2 initialized");

  // Debug: Check if touch is working
  Serial.printf("Touch available: %d\n", M5.Touch.isEnabled());

  init_touch_driver();
}

// hal loop behavior
void hal_loop(void) { M5.update(); }
