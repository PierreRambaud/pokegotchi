#include <stdlib.h>
#include <stdio.h>
#include "utils_hal.h"
#include "SDL2/SDL.h"

void hal_printf(const char* context, char* buffer) {
  printf("[%s] ", context);
  printf(buffer);
  printf("\n");
}

void hal_set_brightness(int32_t value) { return; }

unsigned long hal_millis(void) { return SDL_GetTicks(); }

void hal_restart() {}

int hal_random(int min, int max) { return (rand() % (min - max + 1)) + min; }