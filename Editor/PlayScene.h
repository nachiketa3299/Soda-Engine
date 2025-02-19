#pragma once

#include <Soda/Scene.h>

class PlayScene: public soda::Scene {
public:
  void initialize() override;
  void update() override;
  void post_update() override;
  void render(HDC hdc) override;
};
