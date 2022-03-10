#pragma once
#ifndef POKEGOTCHI_CONFIG
#define POKEGOTCHI_CONFIG

#include <stdint.h>

namespace Pokegotchi {

  struct config_struct {
    const char* sd_directory_path;
    const char* save_file_path;
  };

  typedef struct config_struct Config;

  static Config* global_config = new Config{"/.pokegotchi", "/.pokegotchi/pokegotchi.json"};
}
#endif
