#include "lvgl.h"
#include "app_hal.h"
#include <Utils.h>
#include "GameSwitcher.h"

static lv_display_t * display;

void custom_log_cb(lv_log_level_t level, const char *buf) {
  LV_UNUSED(level);
  serial_printf("LVGL", buf);
}

void lv_display_initialization() {
  lv_init();

  static uint16_t buf[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // Declare a buffer for 1/10 screen siz

  lv_display_t * display = lv_display_create(LV_HOR_RES_MAX, LV_VER_RES_MAX);

  // Initialize `display_buf` display buffer with the buffer(s).
  lv_display_set_buffers(display, buf, NULL, sizeof(buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
  lv_display_set_flush_cb(display, hal_flush_cb);
}

void setup() {
  lv_display_initialization();

  hal_setup();

  lv_log_register_print_cb(custom_log_cb);

  GameSwitcher::Runner::setInstance(new GameSwitcher::Runner());
}

void loop() {
  hal_loop();

  lv_task_handler();
  lv_tick_inc(1);

  GameSwitcher::Runner::getInstance()->loop();
}
