// Unit tests of the pedometer and the shake detection, with synthetic
// accelerometer magnitudes read every 20 ms like the device does
#include <unity.h>
#include <math.h>
#include <stdlib.h>
#include "Motion.h"

static MotionDetector* motion;
static unsigned long now_ms;
static bool shaken;

// Small noise of a real sensor
static float noise(void) { return ((rand() % 1000) / 1000.0f - 0.5f) * 0.04f; }

// Feed seconds of a signal, return the steps counted
template <typename Signal>
static uint16_t simulate(float seconds, Signal signal) {
  uint16_t steps = 0;
  shaken = false;
  for (float t = 0; t < seconds; t += 0.02f) {
    now_ms += 20;
    motion->feed(now_ms, signal(t) + noise());
    steps += motion->take_steps();
    shaken = motion->take_shake() || shaken;
  }
  return steps;
}

// Walking: a peak per step over the gravity
static uint16_t walk(float seconds, float cadence, float amplitude) {
  return simulate(seconds, [=](float t) { return 1.0f + amplitude * sinf(2 * (float)M_PI * cadence * t); });
}

void setUp(void) {
  srand(42);
  now_ms = 0;
  motion = new MotionDetector();
}

void tearDown(void) { delete motion; }

void test_walking_counts_every_step(void) {
  TEST_ASSERT_UINT16_WITHIN(2, 96, walk(60, 1.6f, 0.25f));
  TEST_ASSERT_UINT16_WITHIN(2, 120, walk(60, 2.0f, 0.25f));
}

void test_walking_with_strong_steps(void) { TEST_ASSERT_UINT16_WITHIN(2, 96, walk(60, 1.6f, 0.4f)); }

void test_still_device_counts_nothing(void) {
  TEST_ASSERT_EQUAL(0, simulate(60, [](float) { return 1.0f; }));
  TEST_ASSERT_FALSE(shaken);
}

void test_isolated_bumps_are_not_steps(void) {
  // Put down or picked up every 3 seconds
  TEST_ASSERT_EQUAL(0, simulate(10, [](float t) { return 1.0f + (fmodf(t, 3.0f) < 0.1f ? 0.5f : 0.0f); }));
}

void test_a_few_steps_do_not_count_before_a_rhythm(void) {
  // 3 steps then a stop: not a walk yet
  TEST_ASSERT_EQUAL(0, walk(1.6f, 2.0f, 0.3f));
  TEST_ASSERT_EQUAL(0, simulate(3, [](float) { return 1.0f; }));
}

void test_shake_is_not_a_walk(void) {
  uint16_t steps = simulate(1.5f, [](float t) { return 1.0f + 1.8f * sinf(2 * (float)M_PI * 6 * t); });
  TEST_ASSERT_TRUE(shaken);
  TEST_ASSERT_EQUAL(0, steps);
}

void test_steps_are_taken_once(void) {
  walk(10, 2.0f, 0.3f);
  TEST_ASSERT_EQUAL(0, motion->take_steps());
}

int main(int argc, char** argv) {
  UNITY_BEGIN();
  RUN_TEST(test_walking_counts_every_step);
  RUN_TEST(test_walking_with_strong_steps);
  RUN_TEST(test_still_device_counts_nothing);
  RUN_TEST(test_isolated_bumps_are_not_steps);
  RUN_TEST(test_a_few_steps_do_not_count_before_a_rhythm);
  RUN_TEST(test_shake_is_not_a_walk);
  RUN_TEST(test_steps_are_taken_once);
  return UNITY_END();
}
