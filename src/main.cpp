#ifdef ARDUINO_M5STACK_Core2
#define ANALOG_PIN 35
#endif

#define REFRESH_MS 50

#include <Arduino.h>
#include "lv_port_fs_littlefs.h"
#include <M5Core2.h>
#include <lvgl.h>
#include "Pokegotchi.h"
#include "Config.h"
#include "Utils.h"

static lv_disp_draw_buf_t draw_buf;
Pokegotchi *pokegotchi;
M5Display *tft;

void tft_lv_initialization() {
  M5.begin(true, false);

  lv_init();

  static lv_color_t buf1[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // Declare a buffer for 1/10 screen siz
  static lv_color_t buf2[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // second buffer is optionnal

  // Initialize `disp_buf` display buffer with the buffer(s).
  lv_disp_draw_buf_init(&draw_buf, buf1, buf2, (LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10);

  tft = &M5.Lcd;
}

// Display flushing
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft->startWrite();
  tft->setAddrWindow(area->x1, area->y1, w, h);
  tft->pushColors((uint16_t *)&color_p->full, w * h, true);
  tft->endWrite();

  lv_disp_flush_ready(disp);
}

// Read the touchpad
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
  TouchPoint_t pos = M5.Touch.getPressPoint();

  bool touched = (pos.x < 0 || pos.y < 0 || pos.x > LV_HOR_RES_MAX || pos.y > LV_VER_RES_MAX) ? false : true;
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
  static lv_indev_drv_t indev_drv;

  lv_indev_drv_init(&indev_drv);

  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;  // set touchpad callback

  lv_indev_drv_register(&indev_drv);  // Register the driver
}

// Initialize the display
void init_disp_driver() {
  static lv_disp_drv_t disp_drv;  // Descriptor of a display driver

  lv_disp_drv_init(&disp_drv);  // Basic initialization

  disp_drv.flush_cb = my_disp_flush;  // Set your driver function
  disp_drv.draw_buf = &draw_buf;      // Assign the buffer to the display
  disp_drv.hor_res = LV_HOR_RES_MAX;  // Set the horizontal resolution of the display
  disp_drv.ver_res = LV_VER_RES_MAX;  // Set the vertical resolution of the display

  lv_disp_drv_register(&disp_drv);  // Finally register the driver
}

void custom_log_cb(const char *buf) { Serial.println(buf); }

void setup() {
  randomSeed(analogRead(ANALOG_PIN));

  tft_lv_initialization();

  init_disp_driver();
  init_touch_driver();

  lv_port_littlefs_init();

  lv_log_register_print_cb(custom_log_cb);

  // Setup Pokegotchi
  pokegotchi = new Pokegotchi();
  pokegotchi->setup();
}

void loop() {
  M5.update();

  lv_task_handler();

  pokegotchi->loop();
  delay(REFRESH_MS);
}
