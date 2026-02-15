#ifndef GAME_ANIM_HAL_H
#define GAME_ANIM_HAL_H

#include "lvgl.h"

#define NUMBER_ANIMATION_NIGHT 6
#define NUMBER_ANIMATION_DAY 6

extern const lv_image_dsc_t* game_anim_night[NUMBER_ANIMATION_NIGHT];
extern const lv_image_dsc_t* game_anim_day[NUMBER_ANIMATION_DAY];

#endif  // GAME_ANIM_HAL_H