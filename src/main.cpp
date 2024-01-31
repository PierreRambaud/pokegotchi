#ifdef ARDUINO_M5STACK_Core2
#define ANALOG_PIN 35
#endif

#include <Arduino.h>
#include "lv_port_fs_littlefs.h"
#include <M5Core2.h>
#include <lvgl.h>
#include "Utils.h"
#include "GameSwitcher.h"

static lv_display_t * display;
M5Display *tft;

// Display flushing
void my_display_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft->startWrite();
  tft->setAddrWindow(area->x1, area->y1, w, h);
  tft->pushColors((uint16_t *)px_map, w * h, true);
  tft->endWrite();

  lv_display_flush_ready(disp);
}

// Read the touchpad
void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data) {
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

// Initialize the touch screen
void init_touch_driver() {
  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);
  lv_indev_set_display(indev, display);
}

void custom_log_cb(lv_log_level_t level, const char *buf) {
  LV_UNUSED(level);
  Serial.println(buf);
  Serial.flush();
}

void tft_lv_initialization() {
  M5.begin(true, false);

  lv_init();

  static uint16_t buf1[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // Declare a buffer for 1/10 screen siz
  static uint16_t buf2[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // second buffer is optionnal

  lv_display_t * display = lv_display_create(LV_HOR_RES_MAX, LV_VER_RES_MAX);

  // Initialize `display_buf` display buffer with the buffer(s).
  lv_display_set_buffers(display, buf1, buf2, sizeof(buf1), LV_DISPLAY_RENDER_MODE_FULL);
  lv_display_set_flush_cb(display, my_display_flush);

  tft = &M5.Lcd;
}

void setup() {
  randomSeed(analogRead(ANALOG_PIN));

  tft_lv_initialization();

  init_touch_driver();

  lv_port_littlefs_init();

  lv_log_register_print_cb(custom_log_cb);

  GameSwitcher::Runner::setInstance(new GameSwitcher::Runner());
}

void loop() {
  M5.update();
  lv_task_handler();
  GameSwitcher::Runner::getInstance()->loop();
}
