#pragma once

#include "Soda/WinCommon.h"

namespace soda {

class Time {
public:
  static void initialize();
  static void update();
  static void render(HDC hdc);
public:
  static float get_dt();

private:
  /// @brief CPU의 고유 진동수
  static LARGE_INTEGER cpu_freq_;
  static LARGE_INTEGER prev_freq_;
  static LARGE_INTEGER cur_freq_;

  static float delta_time_;
};

};