#include "M5Unified.h"
#include "utils_hal.h"

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
