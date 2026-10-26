#pragma once
#ifndef CALENDAR_H
#define CALENDAR_H

#include <stdint.h>

/**
 * Days since 1970-01-01 for a civil date (Howard Hinnant's algorithm),
 * independent from any timezone configuration
 */
static inline int32_t days_from_civil(int32_t year, uint32_t month, uint32_t day) {
  year -= month <= 2;
  const int32_t era = (year >= 0 ? year : year - 399) / 400;
  const uint32_t year_of_era = (uint32_t)(year - era * 400);
  const uint32_t day_of_year = (153 * (month + (month > 2 ? -3 : 9)) + 2) / 5 + day - 1;
  const uint32_t day_of_era = year_of_era * 365 + year_of_era / 4 - year_of_era / 100 + day_of_year;
  return era * 146097 + (int32_t)day_of_era - 719468;
}

#endif
