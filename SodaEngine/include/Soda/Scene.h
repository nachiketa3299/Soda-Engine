#pragma once

#include <vector>

#include "Soda/WinCommon.h"

#include "Soda/GEntity.h"

namespace soda {

class GObj;

class Scene: public GEntity {
public:
  Scene() = default;
  ~Scene() override;

public:
  virtual void initialize();
  virtual void pre_update();
  virtual void update();
  virtual void post_update();
  virtual void render(HDC hdc);

  void add_g_obj(GObj *g_obj);

private:
  std::vector<GObj *> g_objs_{};

};

}
