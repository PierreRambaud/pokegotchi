#pragma once
#ifndef MOTION_DETECTOR
#define MOTION_DETECTOR

#include <stdint.h>

/**
 * Turns accelerometer readings into steps and shakes. Hardware free: feed it
 * the magnitude of the acceleration (in g) about every 20 ms.
 */
class MotionDetector {
 public:
  void feed(unsigned long now_ms, float magnitude);

  // Steps walked since the last call
  uint16_t take_steps(void);
  // True once after a shake
  bool take_shake(void);

 private:
  void _detect_shake(unsigned long now_ms, float magnitude);
  void _detect_step(unsigned long now_ms, float magnitude);

  uint16_t _steps = 0;
  bool _shake = false;

  // Shake: strong peaks in a short time
  unsigned long _first_peak = 0;
  uint8_t _peaks = 0;
  bool _in_shake_peak = false;

  // Pedometer
  float _baseline = 1.0f;
  bool _in_step_peak = false;
  float _peak_max = 0;
  unsigned long _last_step = 0;
  uint8_t _streak = 0;
};

#endif
