#include "keyboard_hal.h"
#include "utils_hal.h"
#include "SDL2/SDL.h"

struct KeyState {
  bool pressed;
  bool prev_pressed;
};

struct KeyState key_states[SDL_NUM_SCANCODES] = {0};

// @TODO must be refactored
SDL_Event keyboard_event;
bool is_key_pressed(char key) {
  const uint8_t* keystates = SDL_GetKeyboardState(NULL);
  SDL_Scancode scancode = SDL_GetScancodeFromKey(key);

  // Update the state of the key
  key_states[scancode].prev_pressed = key_states[scancode].pressed;
  key_states[scancode].pressed = keystates[scancode];

  // Check if the key is pressed now but wasn't pressed in the previous frame
  return key_states[scancode].pressed && !key_states[scancode].prev_pressed;
}

bool hal_button_a_pressed(void) { return is_key_pressed(SDLK_a); }

bool hal_button_b_pressed(void) { return is_key_pressed(SDLK_b); }

bool hal_button_c_pressed(void) { return is_key_pressed(SDLK_c); }

// Like the device: a click is released before the hold time, a hold fires
// once while the key is still down
static const uint32_t HOLD_MS = 500;
static uint32_t c_down_since = 0;
static bool c_was_down = false;
static bool c_hold_fired = false;
static bool c_clicked = false;
static bool c_held = false;

static void update_button_c(void) {
  static uint32_t last_update = 0;
  uint32_t now = SDL_GetTicks();
  if (now == last_update) {
    return;
  }
  last_update = now;

  bool down = SDL_GetKeyboardState(NULL)[SDL_SCANCODE_C];
  if (down && !c_was_down) {
    c_down_since = now;
    c_hold_fired = false;
  } else if (down && !c_hold_fired && now - c_down_since >= HOLD_MS) {
    c_hold_fired = true;
    c_held = true;
    // Like the device, a held key is not a new press for hal_button_c_pressed
    SDL_Scancode scancode = SDL_GetScancodeFromKey(SDLK_c);
    key_states[scancode].pressed = true;
    key_states[scancode].prev_pressed = true;
  } else if (!down && c_was_down && !c_hold_fired) {
    c_clicked = true;
  }
  c_was_down = down;
}

bool hal_button_c_clicked(void) {
  update_button_c();
  bool clicked = c_clicked;
  c_clicked = false;
  return clicked;
}

bool hal_button_c_held(void) {
  update_button_c();
  bool held = c_held;
  c_held = false;
  return held;
}
