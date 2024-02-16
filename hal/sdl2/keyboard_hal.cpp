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
