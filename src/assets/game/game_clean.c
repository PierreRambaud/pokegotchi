
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
uint8_t game_clean_map[] = {

    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x70,0x78,0x68,0xff,0x70,0x78,0x68,0xff,0x70,0x78,0x68,0xff,0x58,0x60,0x50,0xff,0x58,0x60,0x50,0xff,0x58,0x60,0x50,0xff,0x58,0x60,0x50,0xff,0x70,0x78,0x68,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x70,0x78,0x68,0xff,0x70,0x78,0x68,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0xc8,0xc8,0xc0,0xff,0xc8,0xc8,0xc0,0xff,0xc8,0xc8,0xc0,0xff,0xc8,0xc8,0xc0,0xff,0xb0,0xb0,0xa8,0xff,0x58,0x60,0x50,0xff,0x70,0x78,0x68,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x58,0x60,0x50,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xb0,0xb0,0xa8,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xe0,0xe0,0xd8,0xff,0x70,0x78,0x68,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x58,0x60,0x50,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xb0,0xb0,0xa8,0xff,0xc8,0xc8,0xc0,0xff,0xc8,0xc8,0xc0,0xff,0xc8,0xc8,0xc0,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xe0,0xff,0x58,0x60,0x50,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x58,0x60,0x50,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xb0,0xb0,0xa8,0xff,0xc8,0xc8,0xc0,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0xb0,0xb0,0xa8,0xff,0xe0,0xe0,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x58,0x60,0x50,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0x70,0x78,0x68,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0xc8,0xc8,0xc0,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x58,0x60,0x50,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0x70,0x78,0x68,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xe0,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0xe0,0xe0,0xd8,0xff,0x70,0x78,0x68,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x58,0x60,0x50,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0x70,0x78,0x68,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xe0,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0xe0,0xe0,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xb0,0xb0,0xa8,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0x70,0x78,0x68,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xe0,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x58,0x60,0x50,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xb0,0xb0,0xa8,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xf8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0x70,0x78,0x68,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x58,0x60,0x50,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0x70,0x78,0x68,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xf8,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xe0,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0xe0,0xe0,0xd8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x58,0x60,0x50,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xb0,0xb0,0xa8,0xff,0x70,0x78,0x68,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xf8,0xff,0xf8,0xf8,0xe0,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0xc8,0xc8,0xc0,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xf8,0xff,0xe0,0xe0,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x70,0x78,0x68,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x70,0x78,0x68,0xff,0xc8,0xc8,0xc0,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xf8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xc8,0xc8,0xc0,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xf8,0xff,0xf8,0xf8,0xe0,0xff,0xe0,0xe0,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x70,0x78,0x68,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xf8,0xff,0xf0,0xf0,0xe8,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xf8,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0x70,0x78,0x68,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xf8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xf8,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x70,0x78,0x68,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xf8,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xf8,0xff,0xf8,0xf8,0xe0,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xf8,0xff,0xf8,0xf8,0xf8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0x70,0x78,0x68,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x70,0x78,0x68,0xff,0xc8,0xc8,0xc0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xf8,0xff,0xf8,0xf8,0xf8,0xff,0xf8,0xf8,0xf8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x70,0x78,0x68,0xff,0x30,0x30,0x30,0xff,0xf0,0xf0,0xe8,0xff,0xf8,0xf8,0xe0,0xff,0xf8,0xf8,0xf8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x30,0x30,0x30,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xf0,0xf0,0xe8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0x70,0x78,0x68,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x70,0x78,0x68,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0xe0,0xe0,0xd8,0xff,0x70,0x78,0x68,0xff,0x30,0x30,0x30,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0x70,0x78,0x68,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x30,0x30,0x30,0xff,0x70,0x78,0x68,0xff,0x70,0x78,0x68,0xff,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,
    0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,0xff,0xff,0xcc,0x00,

};

const lv_image_dsc_t game_clean = {
  .header.magic = LV_IMAGE_HEADER_MAGIC,
  .header.cf = LV_COLOR_FORMAT_ARGB8888,
  .header.flags = 0,
  .header.w = 32,
  .header.h = 32,
  .header.stride = 128,
  .data_size = sizeof(game_clean_map),
  .data = game_clean_map,
};

