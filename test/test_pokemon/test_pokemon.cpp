// Unit tests of the Pokemon life engine: they simulate days of game time,
// second by second like the device does.
#include <unity.h>
#include <stdlib.h>
#include "Pokemon.h"

using namespace Pokegotchi;

// Images and HAL functions the engine references, not needed by the logic
extern const lv_image_dsc_t pokemon_133 = {}, pokemon_134 = {}, pokemon_135 = {}, pokemon_136 = {}, pokemon_196 = {}, pokemon_197 = {}, pokemon_470 = {}, pokemon_471 = {}, pokemon_25 = {},
                            pokemon_26 = {}, pokemon_172 = {};
extern const lv_image_dsc_t pokemon_sick_133 = {}, pokemon_sick_134 = {}, pokemon_sick_135 = {}, pokemon_sick_136 = {}, pokemon_sick_196 = {}, pokemon_sick_197 = {}, pokemon_sick_470 = {},
                            pokemon_sick_471 = {}, pokemon_sick_25 = {}, pokemon_sick_26 = {}, pokemon_sick_172 = {};
extern const lv_image_dsc_t stone_thunder = {}, stone_water = {}, stone_fire = {}, stone_leaf = {}, stone_ice = {};
const void *eevee_face, *vaporeon_face, *jolteon_face, *flareon_face, *espeon_face, *umbreon_face, *leafeon_face, *glaceon_face, *pikachu_face, *raichu_face, *pichu_face;
void hal_printf(const char*, char*) {}
int hal_random(int min, int max) { return max > min ? rand() % (max - min) + min : min; }

static const uint32_t DAY = 86400;

// Real time: a day of the device, at an hour
static uint32_t at(uint32_t day, uint32_t hour, uint32_t minute = 0) { return (20000 + day) * DAY + hour * 3600 + minute * 60; }

// Advance second by second like the device does
static uint16_t run(Pokemon& p, uint32_t from, uint32_t to) {
  uint16_t events = 0;
  for (uint32_t t = from; t <= to; t++) {
    p.update(t);
    events |= p.take_events();
  }
  return events;
}

static BagItemSpecifications food_specs[3] = {
    {2, 5, 0, 0, 1, 1, 0},
    {2, 20, 0, 0, 1, 1, 0},
    {2, 0, 0, 0, 1, 1, 1},
};
static BagItem meal = {nullptr, "meal", "", &food_specs[0]};
static BagItem feast = {nullptr, "feast", "", &food_specs[1]};
static BagItem candy = {nullptr, "candy", "", &food_specs[2]};

// A Pokemon on the real clock, hatched at this time
static uint32_t hatch(Pokemon& p, uint32_t t) {
  p.set_speed(SPEED_REAL);
  run(p, t, t + EGG_HATCH_SECONDS + 1);
  p.take_events();
  return t + EGG_HATCH_SECONDS + 1;
}

static void clean(Pokemon& p) {
  while (p.get_poos() > 0) p.clean_poo();
  while (p.get_pees() > 0) p.clean_pee();
}

void setUp(void) { srand(1); }

void tearDown(void) {}

void test_egg_hatches_after_5_minutes(void) {
  Pokemon p(POKEMON_EEVEE);
  p.set_speed(SPEED_REAL);
  uint32_t t = at(0, 10);
  p.update(t);
  TEST_ASSERT_TRUE(p.is_egg());

  uint16_t events = run(p, t, t + EGG_HATCH_SECONDS - 10);
  TEST_ASSERT_TRUE(p.is_egg());
  TEST_ASSERT_FALSE(events & EVENT_HATCHED);

  events = run(p, t + EGG_HATCH_SECONDS - 10, t + EGG_HATCH_SECONDS + 5);
  TEST_ASSERT_FALSE(p.is_egg());
  TEST_ASSERT_TRUE(events & EVENT_HATCHED);
  TEST_ASSERT_EQUAL(FRIENDSHIP_BASE, p.get_friendship());
}

void test_egg_hatches_after_500_steps(void) {
  Pokemon p(POKEMON_EEVEE);
  uint32_t t = at(0, 10);
  p.update(t);
  p.add_steps(200);
  TEST_ASSERT_TRUE(p.is_egg());
  TEST_ASSERT_EQUAL(200, p.get_egg_steps());
  TEST_ASSERT_TRUE(p.get_hatch_progress() >= 0.4f);

  p.update(t + 60);
  p.add_steps(400);
  TEST_ASSERT_FALSE(p.is_egg());
  TEST_ASSERT_TRUE(p.take_events() & EVENT_HATCHED);
  TEST_ASSERT_EQUAL(EGG_HATCH_STEPS, p.get_egg_steps());
}

void test_hunger_empties_and_the_pokemon_calls(void) {
  Pokemon p(POKEMON_PICHU);
  uint32_t t = hatch(p, at(0, 9));

  // 20 points, one every 15 minutes: empty after 5 hours
  run(p, t, t + 299 * 60);
  TEST_ASSERT_LESS_OR_EQUAL(1, p.get_hunger());
  TEST_ASSERT_NOT_EQUAL(CALL_NONE, p.get_call());
}

void test_digestion_comes_later(void) {
  Pokemon p(POKEMON_PICHU);
  uint32_t t = hatch(p, at(0, 9));
  run(p, t, t + 60 * 60);

  p.eat(&meal);
  TEST_ASSERT_EQUAL(0, p.get_poos());
  uint16_t events = run(p, t + 60 * 60, t + 60 * 60 + POO_DIGESTION_SECONDS + 5);
  TEST_ASSERT_EQUAL(1, p.get_poos());
  TEST_ASSERT_TRUE(events & EVENT_POOED);
}

void test_full_pokemon_refuses_food(void) {
  Pokemon p(POKEMON_PICHU);
  hatch(p, at(0, 9));
  TEST_ASSERT_EQUAL(ACTION_REFUSED_FULL, p.eat(&meal));
}

void test_too_many_sweets_make_it_sick(void) {
  Pokemon p(POKEMON_PICHU);
  hatch(p, at(0, 9));
  for (int i = 0; i < SNACKS_SICKNESS; i++) p.eat(&candy);
  TEST_ASSERT_TRUE(p.is_sick());
  TEST_ASSERT_EQUAL(ACTION_REFUSED_SICK, p.play());
  TEST_ASSERT_EQUAL(ACTION_REFUSED_SICK, p.train());
}

void test_bedtime_call_care_mistake_and_morning(void) {
  Pokemon p(POKEMON_PICHU);
  uint32_t t = hatch(p, at(0, 20, 50));
  p.eat(&feast);

  uint16_t events = run(p, t, at(0, 21, 1));
  TEST_ASSERT_EQUAL(CALL_SLEEPY, p.get_call());
  TEST_ASSERT_TRUE(events & EVENT_CALL);

  // Nobody turns off the light: a care mistake, it falls asleep by itself
  events = run(p, at(0, 21, 1), at(0, 21, 50));
  TEST_ASSERT_TRUE(events & EVENT_CARE_MISTAKE);
  TEST_ASSERT_TRUE(p.is_sleeping());
  TEST_ASSERT_EQUAL(1, p.get_care_mistakes());

  // It wakes up in the morning, hungry but healthy
  events = run(p, at(0, 21, 50), at(1, 7, 5));
  TEST_ASSERT_FALSE(p.is_sleeping());
  TEST_ASSERT_TRUE(events & EVENT_WOKE_UP);
  TEST_ASSERT_GREATER_OR_EQUAL(HUNGER_SLEEPING_MIN - 1, p.get_hunger());
  TEST_ASSERT_GREATER_THAN(90, p.get_life());
}

void test_offline_catch_up_never_faints(void) {
  Pokemon p(POKEMON_PICHU);
  uint32_t t = hatch(p, at(0, 12));
  p.update(t + 5 * DAY);
  uint16_t events = p.take_events();
  TEST_ASSERT_FALSE(p.is_ko());
  TEST_ASSERT_FALSE(events & EVENT_KO);
  TEST_ASSERT_GREATER_OR_EQUAL(CATCH_UP_MIN_LIFE, p.get_life());
  TEST_ASSERT_EQUAL(0, p.get_care_mistakes());
}

void test_neglect_leads_to_ko(void) {
  Pokemon p(POKEMON_PICHU);
  p.set_speed(SPEED_REAL);
  uint16_t events = run(p, at(0, 12), at(2, 12));
  TEST_ASSERT_TRUE(p.is_ko());
  TEST_ASSERT_TRUE(events & EVENT_KO);
}

// Pet, feed, play and clean until the friendship allows an evolution
static uint32_t befriend(Pokemon& p, uint32_t t) {
  while (p.get_friendship() < FRIENDSHIP_EVOLUTION) {
    t += PET_COOLDOWN;
    p.update(t);
    p.pet();
    if (p.get_hunger() < 10) p.eat(&meal);
    if (p.get_mood() < 5) p.play();
    clean(p);
  }
  return t;
}

static int train_until_evolution(Pokemon& p, uint32_t t) {
  p.take_events();
  while (!(p.take_events() & EVENT_EVOLVE)) {
    t++;
    p.update(t);
    p.eat(&meal);
    TEST_ASSERT_EQUAL(ACTION_DONE, p.train());
  }
  return p.get_number();
}

void test_eevee_evolves_into_espeon_by_day(void) {
  Pokemon p(POKEMON_EEVEE);
  uint32_t t = befriend(p, hatch(p, at(0, 10)));
  TEST_ASSERT_EQUAL(POKEMON_ESPEON, train_until_evolution(p, t));
  TEST_ASSERT_EQUAL(POKEMON_EEVEE, p.get_evolution_from());
}

void test_eevee_evolves_into_umbreon_by_night(void) {
  Pokemon p(POKEMON_EEVEE);
  uint32_t t = befriend(p, hatch(p, at(0, 18, 30)));
  TEST_ASSERT_TRUE(t < at(0, 21, 2));
  t = at(0, 21, 2);
  p.update(t);
  TEST_ASSERT_EQUAL(POKEMON_UMBREON, train_until_evolution(p, t));
}

void test_pichu_evolves_with_friendship(void) {
  Pokemon p(POKEMON_PICHU);
  uint32_t t = befriend(p, hatch(p, at(0, 10)));
  TEST_ASSERT_EQUAL(POKEMON_PIKACHU, train_until_evolution(p, t));
}

void test_evolution_stones(void) {
  Pokemon p(POKEMON_EEVEE);
  hatch(p, at(0, 10));
  TEST_ASSERT_EQUAL(ACTION_NO_EFFECT, p.use_stone(STONE_WATER));

  int found = -1;
  for (int i = 0; i < 500 && found != STONE_WATER; i++) {
    found = p.reward_minigame(25);
  }
  TEST_ASSERT_EQUAL(STONE_WATER, found);
  TEST_ASSERT_EQUAL(ACTION_DONE, p.use_stone(STONE_WATER));
  TEST_ASSERT_EQUAL(POKEMON_VAPOREON, p.get_number());
  // Already evolved: no effect, the stone is kept
  TEST_ASSERT_EQUAL(ACTION_NO_EFFECT, p.use_stone(STONE_FIRE));
}

void test_save_and_load(void) {
  Pokemon p(POKEMON_PICHU);
  uint32_t t = hatch(p, at(0, 12));
  run(p, t, t + 600);
  p.eat(&meal);
  p.add_steps(123);

  JsonDocument doc;
  p.save(doc.to<JsonObject>());
  Pokemon q(POKEMON_EEVEE);
  q.load(doc.as<JsonObject>());
  TEST_ASSERT_EQUAL(POKEMON_PICHU, q.get_number());
  TEST_ASSERT_FALSE(q.is_egg());
  TEST_ASSERT_EQUAL(p.get_hunger(), q.get_hunger());
  TEST_ASSERT_EQUAL(p.get_friendship(), q.get_friendship());
  TEST_ASSERT_EQUAL(p.get_speed(), q.get_speed());
  TEST_ASSERT_EQUAL(123, q.get_total_steps());

  // One hour later, it catches up
  q.update(t + 600 + 3600);
  TEST_ASSERT_LESS_THAN(p.get_hunger(), q.get_hunger());
}

void test_load_first_version_save(void) {
  JsonDocument old;
  deserializeJson(old, "{\"number\":25,\"level\":7,\"life\":80,\"mood\":5,\"hunger\":10,\"sleepiness\":60,\"is_sleeping\":false,\"potions\":1}");
  Pokemon p(POKEMON_PICHU);
  p.load(old.as<JsonObject>());
  p.update(at(3, 12));
  p.update(at(3, 12) + 1);
  TEST_ASSERT_FALSE(p.is_egg());
  TEST_ASSERT_EQUAL(POKEMON_PIKACHU, p.get_number());
  TEST_ASSERT_EQUAL(7, p.get_level());
  TEST_ASSERT_EQUAL(10, p.get_hunger());
}

void test_walking_cheers_it_up(void) {
  Pokemon p(POKEMON_PICHU);
  hatch(p, at(0, 10));
  uint8_t friendship = p.get_friendship();
  p.add_steps(250);
  TEST_ASSERT_EQUAL(friendship + 2, p.get_friendship());
}

void test_pedometer_today_and_total(void) {
  Pokemon p(POKEMON_PICHU);
  p.set_speed(SPEED_REAL);
  uint32_t t = at(0, 23, 50);
  p.update(t);
  p.add_steps(300);
  TEST_ASSERT_EQUAL(300, p.get_steps_today(t));

  p.update(t + 60);
  p.add_steps(300);
  TEST_ASSERT_FALSE(p.is_egg());
  p.sleep();
  p.add_steps(50);
  TEST_ASSERT_EQUAL(650, p.get_steps_today(t + 60));

  // A new day: nothing walked yet, the total is kept
  TEST_ASSERT_EQUAL(0, p.get_steps_today(at(1, 0, 5)));
  p.update(at(1, 0, 5));
  p.add_steps(40);
  TEST_ASSERT_EQUAL(40, p.get_steps_today(at(1, 0, 5)));
  TEST_ASSERT_EQUAL(690, p.get_total_steps());
}

void test_new_game_starts_at_the_chosen_speed(void) {
  for (int speed = 0; speed < SPEED_COUNT; speed++) {
    Pokemon p(POKEMON_EEVEE);
    p.set_speed((TimeSpeed)speed);
    uint32_t t = at(0, 22, 15);
    p.update(t);
    uint32_t expected_hour = speed == SPEED_REAL ? 22 : HOUR_GAME_START;
    TEST_ASSERT_EQUAL(speed, p.get_speed());
    TEST_ASSERT_EQUAL(expected_hour, Pokemon::hour_of(p.get_game_time()));

    // The clock goes at the speed of the days
    p.update(t + 60);
    uint32_t elapsed = p.get_game_time() % DAY - expected_hour * 3600;
    TEST_ASSERT_EQUAL(speed == SPEED_REAL ? 15 * 60 + 60 : 60 * TIME_SPEEDS[speed], elapsed);
  }
}

/**
 * A full day at a fast speed: bedtime, a night faster asleep, the needs
 * never faster than with 1 hour days, time to answer a call
 */
static void check_day(TimeSpeed speed) {
  Pokemon p(POKEMON_PICHU);
  p.set_speed(speed);
  uint32_t t = at(0, 23, 30);
  p.update(t);
  TEST_ASSERT_EQUAL(HOUR_GAME_START, Pokemon::hour_of(p.get_game_time()));

  // Good care until it calls for bed
  uint32_t start = t;
  while (p.get_call() != CALL_SLEEPY) {
    t++;
    p.update(t);
    if ((t - start) % 30 == 0) {
      if (p.get_hunger() < 12) p.eat(&meal);
      if (p.get_mood() < 6) p.play();
      clean(p);
    }
  }
  uint32_t expected = (HOUR_BEDTIME - HOUR_GAME_START) * 3600 / TIME_SPEEDS[speed];
  TEST_ASSERT_EQUAL(HOUR_BEDTIME, Pokemon::hour_of(p.get_game_time()));
  TEST_ASSERT_UINT32_WITHIN(5, expected, t - start);

  // The night goes by faster asleep
  p.sleep();
  uint32_t bedtime = t;
  while (!(p.take_events() & EVENT_WOKE_UP)) {
    t++;
    p.update(t);
    TEST_ASSERT_TRUE(t - bedtime < 3600);
  }
  expected = (24 - HOUR_BEDTIME + HOUR_WAKE_UP) * 3600 / (TIME_SPEEDS[speed] * NIGHT_SLEEP_SPEEDUP);
  TEST_ASSERT_UINT32_WITHIN(10, expected, t - bedtime);
  TEST_ASSERT_EQUAL(0, p.get_care_mistakes());

  // A full stomach lasts at least as long as with 1 hour days
  p.eat(&feast);
  uint32_t fed = t;
  while (p.get_hunger() > 0) {
    t++;
    p.update(t);
    TEST_ASSERT_FALSE(p.is_ko());
    if (p.get_call() == CALL_SLEEPY) p.sleep();
    if (p.is_sleeping() && !Pokemon::is_night(p.get_game_time())) p.wake_up();
    if (p.get_mood() < 6) p.play();
    clean(p);
  }
  TEST_ASSERT_GREATER_OR_EQUAL(11 * 60, t - fed);

  // An ignored bedtime: a care mistake after 3 real minutes at most
  p.wake_up();
  p.eat(&feast);
  p.set_time_of_day(21, 0);
  p.take_events();
  uint32_t call = t;
  while (!(p.take_events() & EVENT_CARE_MISTAKE)) {
    t++;
    p.update(t);
    TEST_ASSERT_TRUE(t - call < 600);
  }
  TEST_ASSERT_LESS_OR_EQUAL(CALL_CARE_MISTAKE_MIN_REAL_SECONDS + 10, t - call);
  if (speed != SPEED_FAST) {
    TEST_ASSERT_GREATER_OR_EQUAL(CALL_CARE_MISTAKE_MIN_REAL_SECONDS, t - call);
  }
}

void test_day_at_normal_speed(void) { check_day(SPEED_NORMAL); }

void test_day_at_fast_speed(void) { check_day(SPEED_FAST); }

void test_back_to_the_real_clock(void) {
  Pokemon p(POKEMON_PICHU);
  p.update(at(0, 9));
  p.update(at(0, 9) + 10);
  p.set_speed(SPEED_REAL);
  TEST_ASSERT_EQUAL(at(0, 9) + 10, p.get_game_time());
}

int main(int argc, char** argv) {
  UNITY_BEGIN();
  RUN_TEST(test_egg_hatches_after_5_minutes);
  RUN_TEST(test_egg_hatches_after_500_steps);
  RUN_TEST(test_hunger_empties_and_the_pokemon_calls);
  RUN_TEST(test_digestion_comes_later);
  RUN_TEST(test_full_pokemon_refuses_food);
  RUN_TEST(test_too_many_sweets_make_it_sick);
  RUN_TEST(test_bedtime_call_care_mistake_and_morning);
  RUN_TEST(test_offline_catch_up_never_faints);
  RUN_TEST(test_neglect_leads_to_ko);
  RUN_TEST(test_eevee_evolves_into_espeon_by_day);
  RUN_TEST(test_eevee_evolves_into_umbreon_by_night);
  RUN_TEST(test_pichu_evolves_with_friendship);
  RUN_TEST(test_evolution_stones);
  RUN_TEST(test_save_and_load);
  RUN_TEST(test_load_first_version_save);
  RUN_TEST(test_walking_cheers_it_up);
  RUN_TEST(test_pedometer_today_and_total);
  RUN_TEST(test_new_game_starts_at_the_chosen_speed);
  RUN_TEST(test_day_at_normal_speed);
  RUN_TEST(test_day_at_fast_speed);
  RUN_TEST(test_back_to_the_real_clock);
  return UNITY_END();
}
