#pragma once

#include <windows.h>

namespace soda {

class SodaApp {
public:
  SodaApp() = default;
  ~SodaApp() = default;

public:
  void initialize(HWND hwnd, UINT width, UINT height);

  void run();

  void update();
  void render();

private:
  HWND hwnd_{nullptr};
  HDC dc_{nullptr};
  // 버퍼용 dc
  HDC bdc_{nullptr};

  UINT width_;
  UINT height_;

  HBITMAP buffer_;
};

}