#pragma once

#include <Soda/GObj.h>

namespace tg {

class Character: public soda::GObj {
public:
  void initialize() override;

  void pre_update() override;
  void update() override;
  void post_update() override;
  void render(HDC dc) override;
};

}