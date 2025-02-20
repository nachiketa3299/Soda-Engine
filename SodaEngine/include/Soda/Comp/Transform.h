#pragma once

#include "Soda/WinCommon.h"
#include "Soda/Comp/Comp.h"
#include "Soda/Math/V2.h"

namespace soda {

class Transform: public Comp {
public:
  Transform() = default;
  ~Transform() = default;

  void initialize() override;
  void pre_update() override;
  void update() override;
  void post_update() override;
  void render(HDC hdc) override;

  void set_pos(V2 const &v);
  void set_pos(float x, float y);

  V2 const &get_pos() const;

private:
  V2 p_;
};

}