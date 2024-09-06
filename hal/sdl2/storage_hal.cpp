#include "Utils.h"
#include "lv_i18n.h"
#include "storage_hal.h"

bool hal_remove_file(const char*) { return false; }

bool hal_start_storage(void) { return false; }

void hal_stop_storage(void) {}

void hal_prepare_storage(poke_config_t* global_config) { return; }

DeserializationError hal_load_save_file(JsonDocument* doc, char* file_path) { return DeserializationError::EmptyInput; }

void hal_read_directory(StorageConfig* storage_config, const char* path) { return; }

hal_file_t hal_open_file(const char* path) {
  hal_file_t file(path);
  if (!file.is_open()) {
    return hal_file_t();  // Return an empty ifstream object
  }

  return file;
}
