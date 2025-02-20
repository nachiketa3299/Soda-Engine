#pragma once

#include <Soda/WinCommon.h>

#include <Soda/Scene.h>

namespace tg {

class PlayScene: public soda::Scene {
public:
  void initialize() override;
  void update() override;
  void post_update() override;
  void render(HDC hdc) override;
};

}
