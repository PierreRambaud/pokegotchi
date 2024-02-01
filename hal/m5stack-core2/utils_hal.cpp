#include "M5Core2.h"
#include "utils_hal.h"

void hal_printf(const char* context, char* buffer) {
    Serial.printf("[%s] ", context);
    Serial.println(buffer);
}