
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#elif defined(LV_BUILD_TEST)
#include "../lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_DUST
#define LV_ATTRIBUTE_IMG_DUST
#endif

static const
LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_DUST
uint8_t object_berry_map[] = {

    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x42,0xef,0x84,0xff,0x42,0xef,0x84,0xff,0x42,0xad,0x42,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0x29,0xad,0xff,0xff,0x29,0xad,0xff,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0x42,0xef,0x84,0xff,0x42,0xef,0x84,0xff,0x3a,0x5a,0x29,0xff,0x3a,0x5a,0x29,0xff,0x3a,0x5a,0x29,0xff,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x42,0xe6,0xff,0xff,0x42,0xe6,0xff,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0x42,0xef,0x84,0xff,0x42,0xad,0x42,0xff,0x3a,0x5a,0x29,0xff,0x42,0xad,0x42,0xff,0x42,0xad,0x42,0xff,0x3a,0x5a,0x29,0xff,0x42,0xef,0x84,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0x29,0xad,0xff,0xff,0x42,0xe6,0xff,0xff,0x42,0xe6,0xff,0xff,0x29,0xad,0xff,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0x42,0xad,0x42,0xff,0x42,0xad,0x42,0xff,0x3a,0x5a,0x29,0xff,0x42,0xad,0x42,0xff,0x3a,0x5a,0x29,0xff,0x3a,0x5a,0x29,0xff,0x42,0xef,0x84,0xff,0x42,0xef,0x84,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x29,0xad,0xff,0xff,0x31,0x5a,0xde,0xff,0x29,0xad,0xff,0xff,0x29,0xad,0xff,0xff,0x29,0xad,0xff,0xff,0x29,0x8c,0xf7,0xff,0x31,0x5a,0xde,0xff,0x3a,0x5a,0x29,0xff,0x42,0xad,0x42,0xff,0x3a,0x5a,0x29,0xff,0x3a,0x5a,0x29,0xff,0x3a,0x5a,0x29,0xff,0x42,0xef,0x84,0xff,0x42,0xef,0x84,0xff,0x42,0xad,0x42,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x29,0xad,0xff,0xff,0x42,0xe6,0xff,0xff,0x42,0xe6,0xff,0xff,0x31,0x5a,0xde,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x3a,0x5a,0x29,0xff,0x42,0xad,0x42,0xff,0x3a,0x5a,0x29,0xff,0x42,0xad,0x42,0xff,0x42,0xad,0x42,0xff,0x42,0xad,0x42,0xff,0x3a,0x5a,0x29,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x29,0xad,0xff,0xff,0x42,0xe6,0xff,0xff,0x42,0xe6,0xff,0xff,0x29,0x8c,0xf7,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x29,0xad,0xff,0xff,0x42,0xe6,0xff,0xff,0x42,0xe6,0xff,0xff,0x3a,0x5a,0x29,0xff,0x42,0xad,0x42,0xff,0x42,0xad,0x42,0xff,0x3a,0x5a,0x29,0xff,0x3a,0x5a,0x29,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x29,0x8c,0xf7,0xff,0x29,0xad,0xff,0xff,0x29,0xad,0xff,0xff,0x29,0x8c,0xf7,0xff,0x31,0x5a,0xde,0xff,0x29,0x8c,0xf7,0xff,0x29,0xad,0xff,0xff,0x42,0xe6,0xff,0xff,0x42,0xe6,0xff,0xff,0x29,0xad,0xff,0xff,0x3a,0x5a,0x29,0xff,0x3a,0x5a,0x29,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x5a,0xde,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x31,0x5a,0xde,0xff,0x29,0x8c,0xf7,0xff,0x29,0xad,0xff,0xff,0x29,0xad,0xff,0xff,0x29,0xad,0xff,0xff,0x29,0x8c,0xf7,0xff,0x29,0x42,0x9c,0xff,0x29,0x42,0x9c,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x5a,0xde,0xff,0x29,0xad,0xff,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x29,0xad,0xff,0xff,0x31,0x5a,0xde,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x29,0x42,0x9c,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x42,0xe6,0xff,0xff,0x29,0xad,0xff,0xff,0x29,0x8c,0xf7,0xff,0x29,0x42,0x9c,0xff,0x29,0xad,0xff,0xff,0x42,0xe6,0xff,0xff,0x29,0xad,0xff,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x29,0xad,0xff,0xff,0x29,0xad,0xff,0xff,0x29,0x8c,0xf7,0xff,0x29,0x42,0x9c,0xff,0x29,0xad,0xff,0xff,0x29,0xad,0xff,0xff,0x29,0xad,0xff,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x29,0x42,0x9c,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x5a,0xde,0xff,0x29,0x8c,0xf7,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x29,0x8c,0xf7,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x29,0x42,0x9c,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x29,0x42,0x9c,0xff,0x31,0x31,0x31,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x29,0x42,0x9c,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x5a,0xde,0xff,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0x31,0x31,0x31,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,

};

const lv_image_dsc_t object_berry = {
  .header.magic = LV_IMAGE_HEADER_MAGIC,
  .header.cf = LV_COLOR_FORMAT_ARGB8888,
  .header.flags = 0,
  .header.w = 30,
  .header.h = 30,
  .header.stride = 120,
  .data_size = 3600,
  .data = object_berry_map,
};

