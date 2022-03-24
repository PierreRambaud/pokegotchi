#pragma once
#ifndef POKEGOTCHI_CONFIG
#define POKEGOTCHI_CONFIG

namespace Pokegotchi {

  struct game_config_struct {
    const char* sd_directory_path;
    const char* save_file_path;
  };

  typedef struct game_config_struct poke_config_t;

}  // namespace Pokegotchi
#endif
