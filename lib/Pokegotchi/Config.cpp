#include "Config.h"

Config* Config::instance = nullptr;

Config::Config() {
  sd_directory_path = "/.pokegotchi";
  save_file_path = "/.pokegotchi/pokegotchi.json";
}
