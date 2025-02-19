#include <stdio.h>

#include "Soda/Time.h"

// Static 멤버 초기화
LARGE_INTEGER soda::Time::cpu_freq_{};
LARGE_INTEGER soda::Time::prev_freq_{};
LARGE_INTEGER soda::Time::cur_freq_{};
float soda::Time::delta_time_{.0f};

void soda::Time::initialize() {
  // CPU 고유 진동수
  QueryPerformanceFrequency(&cpu_freq_);
  // 프로그램 시작시 고유 진동수
  QueryPerformanceCounter(&prev_freq_);
}

void soda::Time::update() {
  QueryPerformanceCounter(&cur_freq_);

  float const freq_diff = 
    static_cast<float>(cur_freq_.QuadPart - prev_freq_.QuadPart);
  
  // 시간 간격 업데이트
  delta_time_ = freq_diff / static_cast<float>(cpu_freq_.QuadPart);

  prev_freq_.QuadPart = cur_freq_.QuadPart;
}

#define SODA_TIME_DEBUG_BUFF_LEN 128

void soda::Time::render(HDC hdc) {
  static float time = .0f;
  time += delta_time_;

  float const fps = 1.f / delta_time_;

  wchar_t str[SODA_TIME_DEBUG_BUFF_LEN] = L"";
  // TODO: 이거 하는일이 뭐야?
  swprintf_s(str, SODA_TIME_DEBUG_BUFF_LEN, L">Time: %.3f\n> FPS: %.3f", time, fps);
  size_t const len = wcsnlen_s(str, SODA_TIME_DEBUG_BUFF_LEN);
  RECT rect{10, 10, 300, 300};
  DrawText(hdc, str, -1, &rect, DT_LEFT);
  // TextOut(hdc, 0, 0, str, len);
}

float soda::Time::get_dt() {
  return delta_time_;
}
