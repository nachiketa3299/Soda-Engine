#pragma once

#include <vector>

#include "Soda/WinCommon.h"

#include "Soda/GEntity.h"

namespace soda {

class Comp;

class GObj: public GEntity {
public:
  GObj() = default;
  ~GObj();

public:
  virtual void initialize();

  virtual void pre_update();
  virtual void update();
  virtual void post_update();
  virtual void render(HDC dc);

public:
  template <typename T>
  T *add_comp() {
    T *comp = new T();
    comp->set_owner(this);
    comps_.push_back(comp);

    return comp;
  }

  template <typename T>
  T *get_comp() {
    for (Comp *comp: comps_) {
      T *t_comp = dynamic_cast<T *>(comp);

      if (t_comp != nullptr) {
        return t_comp;
      }
    }

    return nullptr;
  }

private:
  std::vector<Comp *> comps_;
};

}