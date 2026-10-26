#ifndef GAME_ANIM_HAL_H
#define GAME_ANIM_HAL_H

#include "lvgl.h"

// The backgrounds are a full day cycle, in order: day, sunset, night, dawn
#define NUMBER_BACKGROUND_FRAMES 10
#define BACKGROUND_FRAME_NIGHT 7

extern const lv_image_dsc_t* game_background_frames[NUMBER_BACKGROUND_FRAMES];
// Frame shown at each hour of the real clock
extern const uint8_t game_background_hours[24];
// Frames dark enough to need a light text
extern const bool game_background_dark[NUMBER_BACKGROUND_FRAMES];

#endif  // GAME_ANIM_HAL_H
