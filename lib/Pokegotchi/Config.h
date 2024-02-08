#pragma once
#ifndef POKEGOTCHI_CONFIG
#define POKEGOTCHI_CONFIG

namespace Pokegotchi {

  struct game_config_struct {
    const bool use_storage;
    const char* save_files_path;
  };

  typedef struct game_config_struct poke_config_t;

}  // namespace Pokegotchi
#endif
