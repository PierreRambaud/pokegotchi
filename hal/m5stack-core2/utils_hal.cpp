#include "M5Core2.h"
#include "utils_hal.h"

void hal_printf(const char* context, char* buffer) {
  Serial.printf("[%s] ", context);
  Serial.println(buffer);
}

void hal_set_brightness(int32_t value) { M5.Axp.SetLcdVoltage(2500 + ((value * 800) / 100)); }

unsigned long hal_millis(void) { return millis(); }

bool hal_battery_is_charging(void) { return M5.Axp.isCharging(); }

float hal_battery_level(void) { return M5.Axp.GetBatteryLevel(); }

void hal_restart(void) { ESP.restart(); }

int hal_random(int min, int max) { return random(min, max); }