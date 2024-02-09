#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include "SDL2/SDL.h"
#include "lvgl.h"

lv_display_t* hal_create_display(void) { return lv_sdl_window_create(LV_HOR_RES_MAX, LV_VER_RES_MAX); }

/**
 * A task to measure the elapsed time for LittlevGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void* data) {
  (void)data;

  while (1) {
    SDL_Delay(5);   /*Sleep for 5 millisecond*/
    lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
  }

  return 0;
}

void hal_setup(void) {
// Workaround for sdl2 `-m32` crash
// https://bugs.launchpad.net/ubuntu/+source/libsdl2/+bug/1775067/comments/7
#ifndef WIN32
  setenv("DBUS_FATAL_WARNINGS", "0", 1);
#endif

  /* Add the mouse as input device
   * Use the 'mouse' driver which reads the PC's mouse*/

  lv_indev_t* indev = lv_sdl_mouse_create();

  SDL_Init(SDL_INIT_VIDEO);

  /* Tick init.
   * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about how much time were elapsed
   * Create an SDL thread to do this*/
  SDL_CreateThread(tick_thread, "tick", NULL);
}

void hal_loop(void) {
  while (1) {
    SDL_Delay(5);
    lv_timer_handler();
  }
}