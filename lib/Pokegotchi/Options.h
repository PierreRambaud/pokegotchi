#ifndef POKEGOTCHI_OPTIONS
#define POKEGOTCHI_OPTIONS

class Options {
 public:
  static Options* getInstance() {
    if (instance == nullptr) {
      instance = new Options();
    }

    return instance;
  }

  void set_brightness(int value) { _brightness = value; }
  int get_brightness() { return _brightness; }

 protected:
  Options();

  static Options* instance;

 private:
  int _brightness = ((300 * 100) / 800);
};

#endif
