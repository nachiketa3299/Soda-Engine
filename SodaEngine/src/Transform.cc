#include "Soda/Comp/Transform.h"

namespace soda {

void Transform::initialize() {
}

void Transform::pre_update() {
}

void Transform::update() {
}

void Transform::post_update() {
}

void Transform::render(HDC hdc) {
}

void Transform::set_pos(V2 const &v) {
  p_ = v;
}

void Transform::set_pos(float x, float y) {
  p_.x = x;
  p_.y = y;
}

V2 const &Transform::get_pos() const {
  return p_;
}


}