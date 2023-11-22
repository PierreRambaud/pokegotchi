#pragma once
#ifndef POKEGOTCHI_SD
#define POKEGOTCHI_SD

#include <lvgl.h>
#include "Config.h"

struct poke_save_file_info {
  char* name;
  char* path;
};

namespace Pokegotchi {
  class SdConfig {
   public:
    SdConfig(poke_config_t*);
    void load_save_files();
    bool has_save_files() { return _has_save_file; }
    poke_save_file_info* get_save_files() { return _save_files; }
    int get_save_count() { return _save_count; }
    void free_list();

   private:
    void _add_save_file_to_list(poke_save_file_info** list, const char* file_name,  int* count);

    poke_config_t* _config;

    int _save_count = 0;
    poke_save_file_info* _save_files = NULL;
    bool _has_save_file = false;
  };
}  // namespace Pokegotchi
#endif
