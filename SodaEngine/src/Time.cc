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


void soda::Time::render(HDC hdc) {
}

float soda::Time::get_dt() {
  return delta_time_;
}
