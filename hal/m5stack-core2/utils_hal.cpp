#include <time.h>
#include "M5Unified.h"
#include "utils_hal.h"
#include "Calendar.h"
#include "Motion.h"

// RTC time (local time, stored as if it was UTC) minus the uptime
static uint32_t clock_offset = 0;
static unsigned long vibration_end = 0;

void hal_printf(const char* context, char* buffer) {
  Serial.printf("[%s] ", context);
  Serial.println(buffer);
}

void hal_set_brightness(int32_t value) { M5.Display.setBrightness(value); }

unsigned long hal_millis(void) { return millis(); }

bool hal_battery_is_charging(void) { return M5.Power.isCharging(); }

float hal_battery_level(void) { return M5.Power.getBatteryLevel(); }

void hal_restart(void) { ESP.restart(); }

int hal_random(int min, int max) { return random(min, max); }

void hal_init_clock(void) {
  m5::rtc_datetime_t datetime;
  uint32_t now = 0;

  if (M5.Rtc.isEnabled() && M5.Rtc.getDateTime(&datetime) && datetime.date.year >= 2024) {
    now = days_from_civil(datetime.date.year, datetime.date.month, datetime.date.date) * 86400UL + datetime.time.hours * 3600UL + datetime.time.minutes * 60UL + datetime.time.seconds;
  } else {
    // RTC never set: start at noon, the clock can be changed in the options
    now = days_from_civil(2026, 1, 1) * 86400UL + 12 * 3600UL;
  }

  clock_offset = now - millis() / 1000;
}

uint32_t hal_now(void) { return clock_offset + millis() / 1000; }

void hal_set_now(uint32_t now) {
  time_t time = now;
  struct tm datetime;
  gmtime_r(&time, &datetime);

  if (M5.Rtc.isEnabled()) {
    M5.Rtc.setDateTime(&datetime);
  }

  clock_offset = now - millis() / 1000;
}

void hal_vibrate(uint16_t duration_ms) {
  M5.Power.setVibration(180);
  vibration_end = millis() + duration_ms;
}

static bool sound_enabled = true;

void hal_set_sound(bool enabled) {
  sound_enabled = enabled;
  if (!enabled) {
    M5.Speaker.stop();
  }
}

bool hal_sound_enabled(void) { return sound_enabled; }

void hal_beep(uint16_t frequency, uint16_t duration_ms) {
  if (sound_enabled) {
    M5.Speaker.tone(frequency, duration_ms);
  }
}

void hal_update_feedback(void) {
  if (vibration_end != 0 && millis() >= vibration_end) {
    M5.Power.setVibration(0);
    vibration_end = 0;
  }
}

static MotionDetector motion;

void hal_update_motion(void) {
  static unsigned long last_read = 0;

  unsigned long now = millis();
  if (now - last_read < 20) {
    return;
  }
  last_read = now;

  float ax, ay, az;
  if (!M5.Imu.getAccel(&ax, &ay, &az)) {
    return;
  }

  motion.feed(now, sqrtf(ax * ax + ay * ay + az * az));
}

bool hal_shake_detected(void) { return motion.take_shake(); }

uint16_t hal_take_steps(void) { return motion.take_steps(); }

bool hal_user_activity(void) { return M5.Touch.getCount() > 0 || M5.BtnA.isPressed() || M5.BtnB.isPressed() || M5.BtnC.isPressed(); }
