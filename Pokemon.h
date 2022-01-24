#pragma once

struct pokemon_data {
  char name[20];

  int8_t life;
  int8_t level;
  int8_t mood;
};

class Pokemon {
 public:
  void Pokemon();

 private:
  pokemon_data* data;
};
