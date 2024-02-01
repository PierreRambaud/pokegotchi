
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
uint8_t ball_memory_map[] = {

    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x68,0x70,0xf8,0xff,0x68,0x70,0xf8,0xff,0x68,0x70,0xf8,0xff,0x68,0x70,0xf8,0xff,0x68,0x70,0xf8,0xff,0x68,0x70,0xf8,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x68,0x70,0xf8,0xff,0x68,0x70,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x68,0x70,0xf8,0xff,0x20,0x38,0xc8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x68,0x70,0xf8,0xff,0x98,0x98,0xf8,0xff,0x98,0x98,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x68,0x70,0xf8,0xff,0x98,0x98,0xf8,0xff,0xf8,0xf8,0xf8,0xff,0xf8,0xf8,0xf8,0xff,0x98,0x98,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x20,0x38,0xc8,0xff,0x30,0x40,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x68,0x70,0xf8,0xff,0x98,0x98,0xf8,0xff,0xf8,0xf8,0xf8,0xff,0xf8,0xf8,0xf8,0xff,0x98,0x98,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x20,0x38,0xc8,0xff,0x30,0x40,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x68,0x70,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x98,0x98,0xf8,0xff,0x98,0x98,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x30,0x40,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x68,0x70,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x30,0x40,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x20,0x38,0xc8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x28,0x38,0xa0,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x50,0x50,0x48,0xff,0x20,0x38,0xc8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x28,0x38,0xa0,0xff,0x28,0x38,0xa0,0xff,0x28,0x38,0xa0,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x28,0x38,0xa0,0xff,0x50,0x50,0x48,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x20,0x38,0xc8,0xff,0x50,0x50,0x48,0xff,0x20,0x38,0xc8,0xff,0x28,0x38,0xa0,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x28,0x38,0xa0,0xff,0x30,0x40,0xf8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x28,0x38,0xa0,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x20,0x38,0xc8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x50,0x50,0x48,0xff,0x30,0x40,0xf8,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x20,0x38,0xc8,0xff,0x30,0x40,0xf8,0xff,0x20,0x38,0xc8,0xff,0x50,0x50,0x48,0xff,0x28,0x38,0xa0,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x50,0x50,0x48,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x50,0x50,0x48,0xff,0x20,0x38,0xc8,0xff,0x50,0x50,0x48,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x30,0x40,0xf8,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x30,0x40,0xd8,0xff,0x30,0x40,0xf8,0xff,0x50,0x50,0x48,0xff,0x20,0x38,0xc8,0xff,0x30,0x40,0xf8,0xff,0x20,0x38,0xc8,0xff,0x50,0x50,0x48,0xff,0x28,0x38,0xa0,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x28,0x38,0xa0,0xff,0x28,0x38,0xa0,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x30,0x40,0xd8,0xff,0x28,0x38,0xa0,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x50,0x50,0x48,0xff,0x28,0x38,0xa0,0xff,0x28,0x38,0xa0,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x28,0x38,0xa0,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x30,0x40,0xd8,0xff,0x28,0x38,0xa0,0xff,0x28,0x38,0xa0,0xff,0x28,0x38,0xa0,0xff,0x28,0x38,0xa0,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x20,0x38,0xc8,0xff,0x30,0x40,0xd8,0xff,0x28,0x38,0xa0,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x28,0x38,0xa0,0xff,0x20,0x38,0xc8,0xff,0x30,0x40,0xd8,0xff,0x30,0x40,0xd8,0xff,0x20,0x38,0xc8,0xff,0x28,0x38,0xa0,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,

};

const lv_image_dsc_t ball_memory = {
  .header.magic = LV_IMAGE_HEADER_MAGIC,
  .header.cf = LV_COLOR_FORMAT_ARGB8888,
  .header.flags = 0,
  .header.w = 32,
  .header.h = 32,
  .header.stride = 128,
  .data_size = 4096,
  .data = ball_memory_map,
};

