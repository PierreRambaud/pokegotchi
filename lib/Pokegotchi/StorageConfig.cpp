#include "lv_i18n.h"
#include "Options.h"
#include "StorageConfig.h"
#include "Utils.h"
#include "storage_hal.h"

using namespace Pokegotchi;

StorageConfig::StorageConfig(poke_config_t* global_config) { _config = global_config; }

char* extract_file_name_without_extension(const char* filename) {
  char* result = strdup(filename);
  char* lastDot = strrchr(result, '.');

  if (lastDot != NULL) {
    *lastDot = '\0';
  }

  return result;
}

void StorageConfig::add_save_file_to_list(const char* file_name) {
  _save_files = (poke_save_file_info*)realloc(_save_files, (_save_count + 1) * sizeof(poke_save_file_info));
  if (_save_files == NULL) {
    return;
  }

  _save_files[_save_count].name = extract_file_name_without_extension(file_name);

  size_t path_len = strlen(_config->save_files_path);
  size_t name_len = strlen(file_name);
  _save_files[_save_count].path = (char*)malloc(path_len + 1 + name_len + 1);  // +1 pour le séparateur de répertoire et +1 pour le caractère nul
  if (_save_files[_save_count].path == NULL) {
    free(_save_files[_save_count].name);
    return;
  }

  strcpy(_save_files[_save_count].path, _config->save_files_path);
  strcat(_save_files[_save_count].path, "/");
  strcat(_save_files[_save_count].path, file_name);

  _save_count++;
}

void StorageConfig::free_list() {
  for (int i = 0; i < _save_count; i++) {
    free(_save_files[i].name);
    free(_save_files[i].path);
  }

  free(_save_files);
}

void StorageConfig::load_save_files() {
  if (hal_start_storage() == false) {
    return;
  }

  hal_read_directory(this, _config->save_files_path);

  for (int i = 0; i < _save_count; i++) {
    serial_printf("Sd", "Save found \"%s\", Path: \"%s\"", get_save_files()[i].name, get_save_files()[i].path);
  }
}
