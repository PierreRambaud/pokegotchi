#include <time.h>
#include "M5Unified.h"
#include "utils_hal.h"

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

/**
 * Days since 1970-01-01 for a civil date (Howard Hinnant's algorithm),
 * independent from any timezone configuration
 */
static int32_t days_from_civil(int32_t year, uint32_t month, uint32_t day) {
  year -= month <= 2;
  const int32_t era = (year >= 0 ? year : year - 399) / 400;
  const uint32_t year_of_era = (uint32_t)(year - era * 400);
  const uint32_t day_of_year = (153 * (month + (month > 2 ? -3 : 9)) + 2) / 5 + day - 1;
  const uint32_t day_of_era = year_of_era * 365 + year_of_era / 4 - year_of_era / 100 + day_of_year;
  return era * 146097 + (int32_t)day_of_era - 719468;
}

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

void hal_beep(uint16_t frequency, uint16_t duration_ms) { M5.Speaker.tone(frequency, duration_ms); }

void hal_update_feedback(void) {
  if (vibration_end != 0 && millis() >= vibration_end) {
    M5.Power.setVibration(0);
    vibration_end = 0;
  }
}

static bool shake_detected = false;
static uint16_t steps_detected = 0;

/**
 * A shake is several strong acceleration peaks in a short time
 */
static void detect_shake(unsigned long now, float magnitude) {
  static unsigned long first_peak = 0;
  static uint8_t peaks = 0;
  static bool in_peak = false;

  bool peak = magnitude > 1.8f || magnitude < 0.3f;
  if (peak && !in_peak) {
    if (peaks == 0 || now - first_peak > 800) {
      first_peak = now;
      peaks = 0;
    }
    peaks++;
  }
  in_peak = peak;

  if (peaks >= 3) {
    peaks = 0;
    shake_detected = true;
  }
}

/**
 * Pedometer: a step is a moderate peak of acceleration over the gravity.
 * Steps only count once they come in a walking rhythm, so a single bump or
 * picking up the device does not count.
 */
static void detect_step(unsigned long now, float magnitude) {
  static float baseline = 1.0f;
  static bool in_peak = false;
  static float peak_max = 0;
  static unsigned long last_step = 0;
  static uint8_t streak = 0;

  // Slow average of the magnitude: gravity, whatever the device orientation
  baseline += (magnitude - baseline) * 0.05f;
  float dynamic = magnitude - baseline;

  // Follow each peak to its maximum before deciding what it was
  if (dynamic > 0.15f) {
    in_peak = true;
    peak_max = dynamic > peak_max ? dynamic : peak_max;
    return;
  }

  if (!in_peak || dynamic > 0.03f) {
    return;
  }
  in_peak = false;

  // Too strong for a step: that is a shake or a drop
  bool step = peak_max < 1.0f;
  peak_max = 0;
  if (!step) {
    streak = 0;
    return;
  }

  unsigned long interval = now - last_step;
  if (interval < 280) {
    return;
  }
  last_step = now;

  if (interval > 2000) {
    // The walk stopped: start a new streak
    streak = 1;
    return;
  }

  streak++;
  if (streak == 4) {
    // The rhythm is confirmed: count the steps of the streak too
    steps_detected += 4;
  } else if (streak > 4) {
    steps_detected++;
  }
}

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

  float magnitude = sqrtf(ax * ax + ay * ay + az * az);
  detect_shake(now, magnitude);
  detect_step(now, magnitude);
}

bool hal_shake_detected(void) {
  bool shake = shake_detected;
  shake_detected = false;
  return shake;
}

uint16_t hal_take_steps(void) {
  uint16_t steps = steps_detected;
  steps_detected = 0;
  return steps;
}

bool hal_user_activity(void) { return M5.Touch.getCount() > 0 || M5.BtnA.isPressed() || M5.BtnB.isPressed() || M5.BtnC.isPressed(); }
