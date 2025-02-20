#include "Soda/Comp/SpriteRenderer.h"

#include <string>

#include "Soda/WinGdiCommon.h"

#include "Soda/GObj.h"
#include "Soda/Comp/Transform.h"
#include "Soda/Math/V2.h"

namespace soda {

void SpriteRenderer::initialize() {

}

void SpriteRenderer::pre_update() {

}

void SpriteRenderer::update() {

}

void SpriteRenderer::post_update() {

}

void SpriteRenderer::render(HDC hdc) {
  Transform *tr = get_owner()->get_comp<Transform>();
  V2 const &p = tr->get_pos();

  Gdiplus::Graphics gp(hdc);

  gp.DrawImage(img_, Gdiplus::Rect((INT)p.x, (INT)p.y, width_, height_));
}

void SpriteRenderer::load_image(std::wstring const & path) {
  img_ = Gdiplus::Image::FromFile(path.c_str());
  width_ = img_->GetWidth();
  height_ = img_->GetHeight();
}

}