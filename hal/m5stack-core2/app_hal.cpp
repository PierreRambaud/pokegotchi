#define ANALOG_PIN 35
#include "lvgl.h"
#include "Arduino.h"
#include "M5Core2.h"
#include "drivers/lv_fs_littlefs.h"
#include "app_hal.h"
#include "lfs.h"
#include "LittleFS.h"
#include "Utils.h"
#include "esp_partition.h"

M5Display *tft;

/**
 * @param lv_display_t *disp
 * @param const lv_area_t *area
 * @param const uint8_t *px_map
 *
 * @return void
 */
void flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft->startWrite();
  tft->setAddrWindow(area->x1, area->y1, w, h);
  tft->pushColors((uint16_t *)px_map, w * h, true);
  tft->endWrite();

  lv_display_flush_ready(disp);
}

lv_display_t *hal_create_display(void) {
  lv_display_t *display = lv_display_create(LV_HOR_RES_MAX, LV_VER_RES_MAX);
  lv_display_set_flush_cb(display, flush_cb);

  return display;
}

/**
 * @param lv_indev_t *indev
 * @param lv_indev_data_t *data
 *
 * @return void
 */
void touchpad_read_cb(lv_indev_t *indev, lv_indev_data_t *data) {
  TouchPoint_t pos = M5.Touch.getPressPoint();

  bool touched = (pos.x <= 0 || pos.y <= 0 || pos.x >= LV_HOR_RES_MAX || pos.y >= LV_VER_RES_MAX) ? false : true;
  if (!touched) {
    data->state = LV_INDEV_STATE_RELEASED;
  } else {
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = pos.x;
    data->point.y = pos.y;
  }
}

// Initialize the touch screen
void init_touch_driver(void) {
  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, touchpad_read_cb);
}

static uint32_t s_blockSize = 4096;

int lfs_flash_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size) {
  // Calculate the address to read from
    size_t addr = c->block_size * block + off;

    // Find the data partition
    const esp_partition_t *partition = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_DATA_SPIFFS, NULL);
    if (partition == NULL) {
        return LFS_ERR_IO;
    }

    // Read data from the flash memory
    esp_err_t err = esp_partition_read(partition, addr, buffer, size);
    if (err != ESP_OK) {
        return LFS_ERR_IO;
    }

    return 0;
}

int lfs_flash_prog(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size) {
    const esp_partition_t *partition = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_DATA_SPIFFS, NULL);
    if (partition == NULL) {
        return LFS_ERR_IO;
    }

    const esp_partition_t *next_partition = NULL;
    size_t num_partitions;
    esp_partition_iterator_t it = esp_partition_find(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_DATA_SPIFFS, NULL);

    // Iterate over all partitions
    while (it != NULL) {
        const esp_partition_t *part = esp_partition_get(it);
        if (part->address > partition->address) {
            next_partition = part;
            break;
        }
        it = esp_partition_next(it);
    }

    // If next_partition is still NULL, it means there are no partitions after the current one
    if (next_partition == NULL) {
        return LFS_ERR_IO;
    }

    // Calculate the size of the current partition
    size_t partition_size = next_partition->address - partition->address;

    size_t addr = partition->address + (block * c->block_size) + off;

    if (addr + size > partition_size) {
        return LFS_ERR_IO;
    }

    return esp_partition_write(partition, addr, buffer, size);
}


int lfs_flash_erase(const struct lfs_config *c, lfs_block_t block) { return 0; }

int lfs_flash_sync(const struct lfs_config *c) {
  (void)c;
  return 0;
}

// Initialize hal
void hal_setup(void) {
  randomSeed(analogRead(ANALOG_PIN));
  M5.begin(true, false);

  lv_fs_littlefs_init();
#define LFS_CACHE_SIZE 512U

uint8_t readBuff[LFS_CACHE_SIZE];
uint8_t writeBuff[LFS_CACHE_SIZE];
uint8_t lookBuff[LFS_CACHE_SIZE];
uint8_t fileBuff[LFS_CACHE_SIZE];

  static lfs_t s_fs;
  static lfs_config s_cfg;
  memset(&s_fs, 0, sizeof(s_fs));
  memset(&s_cfg, 0, sizeof(s_cfg));
  s_cfg.read = lfs_flash_read;
  s_cfg.prog = lfs_flash_prog;
  s_cfg.erase = lfs_flash_erase;
  s_cfg.sync = lfs_flash_sync;

  s_cfg.read_size = 64;
  s_cfg.prog_size = 64;
  s_cfg.block_size = s_blockSize;
  s_cfg.block_count = 3538944 / s_blockSize;
  s_cfg.block_cycles = 16;  // TODO - need better explanation
  s_cfg.cache_size = 64;
  s_cfg.lookahead_size = 64;
  s_cfg.read_buffer = nullptr;
  s_cfg.prog_buffer = nullptr;
  s_cfg.lookahead_buffer = nullptr;
  s_cfg.name_max = 0;
  s_cfg.file_max = 0;
  s_cfg.attr_max = 0;

  int res = lfs_mount(&s_fs, &s_cfg);
  if (res) {
    serial_printf("LITTLEFS", "not mounted");
  } else {
    serial_printf("LITTLEFS", "mounted");
  }
  lv_littlefs_set_handler(&s_fs);
  init_touch_driver();

  tft = &M5.Lcd;
}

// hal loop behavior
void hal_loop(void) { M5.update(); }
