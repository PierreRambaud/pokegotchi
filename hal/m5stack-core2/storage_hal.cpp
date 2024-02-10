#include "M5Core2.h"
#include "Utils.h"
#include "lv_i18n.h"
#include "storage_hal.h"

bool hal_remove_file(const char* path) {
  if (hal_start_storage() == false) {
    create_message_box(_("game.error"), _("sd.card.not_found"));
    return false;
  }

  bool result = SD.remove(path);
  SD.end();

  return result;
}

bool hal_start_storage(void) { return SD.begin(TFCARD_CS_PIN, SPI, 40000000); }

void hal_prepare_storage(poke_config_t* global_config) {
  File entry = SD.open(global_config->save_files_path);
  if (entry && !entry.isDirectory()) {
    entry.close();
    SD.remove(global_config->save_files_path);
  }

  entry = SD.open(global_config->save_files_path);
  if (!entry) {
    SD.mkdir(global_config->save_files_path);
  }

  SD.end();
}

DeserializationError hal_load_save_file(JsonDocument* doc, char* file_path) {
  File file = SD.open(file_path);
  if (!file) {
    create_message_box(_("game.error"), _("game.load.error"));
    return DeserializationError::EmptyInput;
  }

  DeserializationError error = deserializeJson(*doc, file);
  file.close();
  SD.end();

  return error;
}

void hal_read_directory(StorageConfig* storage_config, const char* path) {
  File directory = SD.open(path);
  if (!directory or !directory.isDirectory()) {
    create_message_box("", _("game.load.error"));
    return;
  }

  while (true) {
    File entry = directory.openNextFile();
    if (!entry) {
      // No more files
      break;
    }

    storage_config->add_save_file_to_list(entry.name());
  }

  directory.close();
  SD.end();
}