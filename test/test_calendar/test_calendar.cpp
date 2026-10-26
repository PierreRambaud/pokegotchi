// Unit tests of the date conversion used to read the RTC
#include <unity.h>
#include "Calendar.h"

void setUp(void) {}

void tearDown(void) {}

void test_epoch(void) { TEST_ASSERT_EQUAL_INT32(0, days_from_civil(1970, 1, 1)); }

void test_leap_days(void) {
  TEST_ASSERT_EQUAL_INT32(11016, days_from_civil(2000, 2, 29));
  TEST_ASSERT_EQUAL_INT32(19782, days_from_civil(2024, 2, 29));
  TEST_ASSERT_EQUAL_INT32(days_from_civil(2024, 2, 29) + 1, days_from_civil(2024, 3, 1));
}

void test_recent_dates(void) {
  TEST_ASSERT_EQUAL_INT32(20454, days_from_civil(2026, 1, 1));
  TEST_ASSERT_EQUAL_INT32(20752, days_from_civil(2026, 10, 26));
}

void test_end_of_the_rtc_range(void) { TEST_ASSERT_EQUAL_INT32(47481, days_from_civil(2099, 12, 31)); }

void test_consecutive_days(void) {
  // Every day of 2026 follows the previous one
  int32_t previous = days_from_civil(2025, 12, 31);
  const uint8_t month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for (uint8_t month = 1; month <= 12; month++) {
    for (uint8_t day = 1; day <= month_days[month - 1]; day++) {
      int32_t current = days_from_civil(2026, month, day);
      TEST_ASSERT_EQUAL_INT32(previous + 1, current);
      previous = current;
    }
  }
}

int main(int argc, char** argv) {
  UNITY_BEGIN();
  RUN_TEST(test_epoch);
  RUN_TEST(test_leap_days);
  RUN_TEST(test_recent_dates);
  RUN_TEST(test_end_of_the_rtc_range);
  RUN_TEST(test_consecutive_days);
  return UNITY_END();
}
