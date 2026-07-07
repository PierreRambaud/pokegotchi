#include "lvgl.h"
#include "app_hal.h"
#include "Utils.h"
#include "GameSwitcher.h"

static lv_display_t *display;

void custom_log_cb(lv_log_level_t level, const char *buf) {
  LV_UNUSED(level);
  serial_printf("LVGL", buf);
}

void lv_display_initialization(void) {
  lv_init();

  lv_display_t *display = hal_create_display();

  static uint16_t buf[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // Declare a buffer for 1/10 screen size
  // Initialize `display_buf` display buffer with the buffer(s).
  lv_display_set_buffers(display, buf, NULL, sizeof(buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
}

void setup(void) {
  lv_display_initialization();

  hal_setup();

  lv_log_register_print_cb(custom_log_cb);

  GameSwitcher::Runner::setInstance(new GameSwitcher::Runner());
}

void loop(void) {
  // Tell LVGL how much real wall-clock time actually elapsed since the last
  // call, rather than assuming a fixed 1ms per iteration. That assumption
  // silently broke once the loop started sleeping a variable amount below:
  // LVGL's clock would run far slower than real time, making every
  // animation/timer/timeout appear to drag.
  static uint32_t last_tick_ms = hal_millis();
  uint32_t now_ms = hal_millis();
  lv_tick_inc(now_ms - last_tick_ms);
  last_tick_ms = now_ms;

  hal_loop();

  uint32_t time_till_next = lv_timer_handler();

  GameSwitcher::Runner::getInstance()->loop();

  // Cap the sleep so touch/button input (polled via hal_loop, outside LVGL's
  // timer system) still gets serviced promptly even when no LVGL timer is due.
  hal_delay(time_till_next > 5 ? 5 : time_till_next);
}

#ifdef USE_SDL
int main(void) {
  setup();

  while (1) {
    loop();
  }

  return 1;
}
#endif