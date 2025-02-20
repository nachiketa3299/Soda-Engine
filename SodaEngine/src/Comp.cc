#include "Soda/Comp/Comp.h"

#include "Soda/WinCommon.h"

namespace soda {

void Comp::initialize() {}

void Comp::pre_update() {}

void Comp::update() {}

void Comp::post_update() {}

void Comp::render(HDC hdc) {}

void Comp::set_owner(GObj *owner) {
  owner_ = owner;
}

GObj * Comp::get_owner() const {
  return owner_;
}

}