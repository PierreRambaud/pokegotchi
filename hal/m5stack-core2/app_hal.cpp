#define ANALOG_PIN 35
#include "lvgl.h"
#include "Arduino.h"
#include "M5Unified.h"
#include "app_hal.h"
#include "utils_hal.h"

// Lines rendered per buffer: two buffers let LVGL render the next strip
// while the previous one is sent to the panel by DMA
#define DISPLAY_BUFFER_LINES 30

static bool display_writing = false;

/**
 * Send a rendered strip to the panel with DMA, without waiting for it
 *
 * @param lv_display_t *disp
 * @param const lv_area_t *area
 * @param const uint8_t *px_map
 *
 * @return void
 */
void flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  // Keep the bus for the whole refresh: pushImageDMA waits for the previous
  // transfer, so the buffer LVGL renders into next is never being sent
  if (!display_writing) {
    M5.Display.startWrite();
    display_writing = true;
  }

  // LVGL renders in RGB565_SWAPPED, the panel native format: no conversion
  M5.Display.pushImageDMA(area->x1, area->y1, w, h, (const lgfx::swap565_t *)px_map);

  lv_display_flush_ready(disp);
}

/**
 * Release the bus once a refresh is done, the SD card shares it
 */
static void refresh_ready_cb(lv_event_t *e) {
  LV_UNUSED(e);

  if (display_writing) {
    M5.Display.endWrite();
    display_writing = false;
  }
}

lv_display_t *hal_create_display(void) {
  lv_display_t *display = lv_display_create(LV_HOR_RES_MAX, LV_VER_RES_MAX);
  lv_display_set_flush_cb(display, flush_cb);
  lv_display_set_color_format(display, LV_COLOR_FORMAT_RGB565_SWAPPED);
  lv_display_add_event_cb(display, refresh_ready_cb, LV_EVENT_REFR_READY, NULL);

  // DMA can only read internal memory
  size_t buffer_size = LV_HOR_RES_MAX * DISPLAY_BUFFER_LINES * sizeof(uint16_t);
  void *buffer_1 = heap_caps_malloc(buffer_size, MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);
  void *buffer_2 = heap_caps_malloc(buffer_size, MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);
  lv_display_set_buffers(display, buffer_1, buffer_2, buffer_size, LV_DISPLAY_RENDER_MODE_PARTIAL);

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

  // The touch panel is taller than the screen: the strip below it holds the
  // A/B/C touch buttons, handled by M5Unified, so keep it away from LVGL.
  if (touch.isPressed() && touch.y < LV_VER_RES_MAX) {
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
  hal_init_clock();
}

// hal loop behavior
void hal_loop(void) {
  M5.update();
  hal_update_feedback();
  hal_update_motion();
}

void hal_delay(uint32_t ms) { delay(ms); }
