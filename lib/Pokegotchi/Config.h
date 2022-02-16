#ifndef POKEGOTCHI_CONFIG
#define POKEGOTCHI_CONFIG

class Config {
 public:
  static Config* getInstance() {
    if (instance == nullptr) {
      instance = new Config();
    }

    return instance;
  }

  bool is_sd_card_available = false;
  const char* sd_directory_path;
  const char* save_file_path;

 private:
  Config();
  static Config* instance;
};
#endif
