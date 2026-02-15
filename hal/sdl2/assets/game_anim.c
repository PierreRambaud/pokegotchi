#include "game_anim.h"

LV_IMG_DECLARE(background_1)
LV_IMG_DECLARE(background_2)
LV_IMG_DECLARE(background_3)
LV_IMG_DECLARE(background_4)
LV_IMG_DECLARE(background_5)
LV_IMG_DECLARE(background_6)
LV_IMG_DECLARE(background_7)
LV_IMG_DECLARE(background_8)
LV_IMG_DECLARE(background_9)
LV_IMG_DECLARE(background_10)
LV_IMG_DECLARE(background_11)
LV_IMG_DECLARE(background_12)
LV_IMG_DECLARE(background_13)
LV_IMG_DECLARE(background_14)
LV_IMG_DECLARE(background_15)
LV_IMG_DECLARE(background_16)
LV_IMG_DECLARE(background_17)
LV_IMG_DECLARE(background_18)
LV_IMG_DECLARE(background_19)
LV_IMG_DECLARE(background_20)

const lv_image_dsc_t* game_anim_night[NUMBER_ANIMATION_NIGHT] = {
    &background_6, &background_8, &background_10, &background_12, &background_14, &background_16,
};

const lv_image_dsc_t* game_anim_day[NUMBER_ANIMATION_DAY] = {
    &background_16, &background_18, &background_20, &background_2, &background_4, &background_6,
};