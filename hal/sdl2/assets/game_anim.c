#include "game_anim.h"

LV_IMG_DECLARE(background_2)
LV_IMG_DECLARE(background_4)
LV_IMG_DECLARE(background_6)
LV_IMG_DECLARE(background_8)
LV_IMG_DECLARE(background_10)
LV_IMG_DECLARE(background_12)
LV_IMG_DECLARE(background_14)
LV_IMG_DECLARE(background_16)
LV_IMG_DECLARE(background_18)
LV_IMG_DECLARE(background_20)

const lv_image_dsc_t* game_background_frames[NUMBER_BACKGROUND_FRAMES] = {
    &background_2, &background_4, &background_6, &background_8, &background_10, &background_12, &background_14, &background_16, &background_18, &background_20,
};

// Night until 4h, dawn, day, afternoon, sunset from 18h then night again
const uint8_t game_background_hours[24] = {
    7, 7, 7, 7, 7, 8, 8, 9, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7,
};

const bool game_background_dark[NUMBER_BACKGROUND_FRAMES] = {
    false, false, false, false, true, true, true, true, true, false,
};
