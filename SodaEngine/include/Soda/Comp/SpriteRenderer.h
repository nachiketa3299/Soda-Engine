#pragma once

#include <string>

#include "Soda/WinGdiCommon.h"

#include "Soda/Comp/Comp.h"

namespace soda {

class SpriteRenderer: public Comp {
public:
  void initialize() override;
  void pre_update() override;
  void update() override;
  void post_update() override;
  void render(HDC hdc) override;

public:
  void load_image(std::wstring const &path);

private:
  Gdiplus::Image *img_;
  UINT width_;
  UINT height_;
};

}