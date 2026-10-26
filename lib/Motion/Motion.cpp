#include "Motion.h"

void MotionDetector::feed(unsigned long now_ms, float magnitude) {
  _detect_shake(now_ms, magnitude);
  _detect_step(now_ms, magnitude);
}

uint16_t MotionDetector::take_steps(void) {
  uint16_t steps = _steps;
  _steps = 0;
  return steps;
}

bool MotionDetector::take_shake(void) {
  bool shake = _shake;
  _shake = false;
  return shake;
}

/**
 * A shake is several strong acceleration peaks in a short time
 */
void MotionDetector::_detect_shake(unsigned long now_ms, float magnitude) {
  bool peak = magnitude > 1.8f || magnitude < 0.3f;
  if (peak && !_in_shake_peak) {
    if (_peaks == 0 || now_ms - _first_peak > 800) {
      _first_peak = now_ms;
      _peaks = 0;
    }
    _peaks++;
  }
  _in_shake_peak = peak;

  if (_peaks >= 3) {
    _peaks = 0;
    _shake = true;
  }
}

/**
 * Pedometer: a step is a moderate peak of acceleration over the gravity.
 * Steps only count once they come in a walking rhythm, so a single bump or
 * picking up the device does not count.
 */
void MotionDetector::_detect_step(unsigned long now_ms, float magnitude) {
  // Slow average of the magnitude: gravity, whatever the device orientation
  _baseline += (magnitude - _baseline) * 0.05f;
  float dynamic = magnitude - _baseline;

  // Follow each peak to its maximum before deciding what it was
  if (dynamic > 0.15f) {
    _in_step_peak = true;
    _peak_max = dynamic > _peak_max ? dynamic : _peak_max;
    return;
  }

  if (!_in_step_peak || dynamic > 0.03f) {
    return;
  }
  _in_step_peak = false;

  // Too strong for a step: that is a shake or a drop
  bool step = _peak_max < 1.0f;
  _peak_max = 0;
  if (!step) {
    _streak = 0;
    return;
  }

  unsigned long interval = now_ms - _last_step;
  if (interval < 280) {
    return;
  }
  _last_step = now_ms;

  if (interval > 2000) {
    // The walk stopped: start a new streak
    _streak = 1;
    return;
  }

  _streak++;
  if (_streak == 4) {
    // The rhythm is confirmed: count the steps of the streak too
    _steps += 4;
  } else if (_streak > 4) {
    _steps++;
  }
}
