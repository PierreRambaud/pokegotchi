#include <lv_i18n.h>
#include "Options.h"
#include "SdConfig.h"
#include "Utils.h"

using namespace Pokegotchi;

SdConfig::SdConfig(poke_config_t* global_config) { _config = global_config; }

char* extract_file_name_without_extension(const char* filename) {
  char* result = strdup(filename);
  char* lastDot = strrchr(result, '.');

  if (lastDot != NULL) {
    *lastDot = '\0';
  }

  return result;
}

void SdConfig::_add_save_file_to_list(poke_save_file_info** list, const char* file_name, int* count) {
  *list = (poke_save_file_info*)realloc(*list, (*count + 1) * sizeof(poke_save_file_info));
  if (*list == NULL) {
    return;
  }

  (*list)[*count].name = extract_file_name_without_extension(file_name);

  size_t path_len = strlen(_config->save_files_path);
  size_t name_len = strlen(file_name);
  (*list)[*count].path = (char*)malloc(path_len + 1 + name_len + 1);  // +1 pour le séparateur de répertoire et +1 pour le caractère nul
  if ((*list)[*count].path == NULL) {
    free((*list)[*count].name);
    return;
  }

  strcpy((*list)[*count].path, _config->save_files_path);
  strcat((*list)[*count].path, "/");
  strcat((*list)[*count].path, file_name);

  (*count)++;
}

void SdConfig::free_list() {
  for (int i = 0; i < _save_count; i++) {
    free(_save_files[i].name);
    free(_save_files[i].path);
  }

  free(_save_files);
}

void SdConfig::load_save_files() {
  if (sd_begin() == false) {
    display_alert("", _("sd.card.not_found"));
    return;
  }

  File directory = SD.open(_config->save_files_path);
  if (!directory or !directory.isDirectory()) {
    display_alert("", _("game.load.error"));
    return;
  }

  while (true) {
    File entry = directory.openNextFile();
    if (!entry) {
      // No more files
      break;
    }

    _add_save_file_to_list(&_save_files, entry.name(), &_save_count);
  }

  directory.close();
  SD.end();

  _has_save_file = _save_count > 0;

  for (int i = 0; i < _save_count; i++) {
    serial_printf("Sd", "Save found \"%s\", Path: \"%s\"", get_save_files()[i].name, get_save_files()[i].path);
  }
}
