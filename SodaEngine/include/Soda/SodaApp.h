#pragma once

#include "WinGdiCommon.h"

namespace soda {

class GObj;

class SodaApp {
public:
  SodaApp() = default;
  ~SodaApp() = default;

public:
  void initialize(HWND hwnd, UINT width, UINT height);

  void clear_render_target() const;
  void copy_render_target(HDC src, HDC dest) const;

  void run();

  void update();
  void render();

private:
  HWND hwnd_{nullptr};
  HDC dc_{nullptr};
  // 버퍼용 dc
  HDC bdc_{nullptr};

  UINT width_{};
  UINT height_{};

  HBITMAP buffer_{};

  ULONG_PTR gdi_token_;
  Gdiplus::GdiplusStartupInput gdi_sinput;
};

}