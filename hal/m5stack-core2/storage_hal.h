#pragma once
#ifndef STORAGE_HAL_H
#define STORAGE_HAL_H

#include "ArduinoJson.h"
#include "Config.h"
#include "StorageConfig.h"
#include "FS.h"

using namespace Pokegotchi;

typedef File hal_file_t;

bool hal_remove_file(const char*);
bool hal_start_storage(void);
void hal_stop_storage(void);
void hal_prepare_storage(poke_config_t*);
DeserializationError hal_load_save_file(JsonDocument* doc, char* file_path);

void hal_read_directory(StorageConfig*, const char*);

hal_file_t hal_open_file(const char*);

#endif /*STORAGE_HAL_H*/