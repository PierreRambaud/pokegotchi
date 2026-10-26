#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utils_hal.h"
#include "SDL2/SDL.h"

void hal_printf(const char* context, char* buffer) {
  printf("[%s] ", context);
  printf(buffer);
  printf("\n");
}

void hal_set_brightness(int32_t value) { return; }

unsigned long hal_millis(void) { return SDL_GetTicks(); }

void hal_restart(void) {}

// Same contract as Arduino random(): min included, max excluded
int hal_random(int min, int max) { return max > min ? (rand() % (max - min)) + min : min; }

static int32_t clock_offset = 0;

/**
 * Local time as seconds since 1970, like the RTC of the device
 */
static uint32_t local_time(void) {
  time_t now = time(NULL);
  struct tm local;
  localtime_r(&now, &local);

  return (uint32_t)(now + local.tm_gmtoff);
}

void hal_init_clock(void) { clock_offset = 0; }

uint32_t hal_now(void) { return local_time() + clock_offset; }

void hal_set_now(uint32_t now) { clock_offset = (int32_t)(now - local_time()); }

void hal_vibrate(uint16_t duration_ms) {}

void hal_beep(uint16_t frequency, uint16_t duration_ms) {}

void hal_update_feedback(void) {}

bool hal_shake_detected(void) {
  const uint8_t* keystates = SDL_GetKeyboardState(NULL);
  static bool was_pressed = false;
  bool pressed = keystates[SDL_SCANCODE_S];
  bool shake = pressed && !was_pressed;
  was_pressed = pressed;

  return shake;
}

void hal_update_motion(void) {}

// No accelerometer on the emulator: each press on W is a walk of 50 steps
uint16_t hal_take_steps(void) {
  const uint8_t* keystates = SDL_GetKeyboardState(NULL);
  static bool was_pressed = false;
  bool pressed = keystates[SDL_SCANCODE_W];
  bool walk = pressed && !was_pressed;
  was_pressed = pressed;

  return walk ? 50 : 0;
}

bool hal_user_activity(void) { return (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON_LMASK) != 0; }