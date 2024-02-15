#pragma once
#ifndef POKEGOTCHI_SD
#define POKEGOTCHI_SD

#include "lvgl.h"
#include "Config.h"

struct poke_save_file_info {
  char* name;
  char* path;
};

namespace Pokegotchi {
  class StorageConfig {
   public:
    StorageConfig(poke_config_t*);
    void add_save_file_to_list(const char* base_path);
    void free_list(void);
    poke_save_file_info* get_save_files(void) { return _save_files; }
    int get_save_count(void) { return _save_count; }
    bool has_save_files(void) { return _save_count > 0; }
    void load_save_files(void);

   private:
    poke_config_t* _config;

    int _save_count = 0;
    poke_save_file_info* _save_files = NULL;
  };
}  // namespace Pokegotchi
#endif
