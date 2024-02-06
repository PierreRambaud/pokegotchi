#include "stdio.h"
#include "utils_hal.h"
#include "SDL2/SDL.h"

void hal_printf(const char* context, char* buffer) {
    printf("[%s] ", context);
    printf(buffer);
    printf("\n");
}

void hal_set_brightness(int32_t value) {
  return;
}

bool hal_start_storage() {
    return false;
}

unsigned long hal_millis(void)  {
    return SDL_GetTicks();
}