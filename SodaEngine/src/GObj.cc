#include "Soda/GObj.h"
#include "Soda/Input.h"

void soda::GObj::set_pos(int x, int y) {
  x_ = x;
  y_ = y;
}

int soda::GObj::get_pos_x() const {
  return x_;
}

int soda::GObj::get_pos_y() const {
  return y_;
}

void soda::GObj::pre_update() {
}

void soda::GObj::initialize() {
}

void soda::GObj::update() {
}

void soda::GObj::post_update() {
}

void soda::GObj::render(HDC dc) {
}