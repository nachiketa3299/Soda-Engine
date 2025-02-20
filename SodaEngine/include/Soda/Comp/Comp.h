#pragma once

#include "Soda/WinCommon.h"

#include "Soda/GEntity.h"

namespace soda {

class GObj;

class Comp: public GEntity {
public:
  Comp() = default;
  ~Comp() = default;

  virtual void initialize();
  virtual void pre_update();
  virtual void update();
  virtual void post_update();
  virtual void render(HDC hdc);

  void set_owner(GObj *owner);
  GObj *get_owner() const;
  
private:
  GObj *owner_{nullptr};
};

}
