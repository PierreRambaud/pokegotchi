#ifndef LV_FS_LITTLEFS_H
#define LV_FS_LITTLEFS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "lfs.h"

void lv_littlefs_set_handler(lfs_t* lfs);
void lv_fs_littlefs_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
