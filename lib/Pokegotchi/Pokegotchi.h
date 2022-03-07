#ifndef POKEGOTCHI_POKEGOTCHI
#define POKEGOTCHI_POKEGOTCHI

const unsigned long PERIOD_REFRESH = 20 * 1000UL;

class Pokegotchi {
 public:
  Pokegotchi();
  void setup();
  void loop();

 private:
  long unsigned _last_refresh_time = 0;
};
#endif
