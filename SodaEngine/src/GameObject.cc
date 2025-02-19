#include "Soda/GameObject.h"
#include "Soda/Input.h"

namespace soda {

void GameObject::set_pos(int x, int y) {
  x_ = x;
  y_ = y;
}

int GameObject::get_pos_x() const {
  return x_;
}

int GameObject::get_pos_y() const {
  return y_;
}

void GameObject::pre_update() {
}

void GameObject::update() {
  if (Input::is_down(KeyCode::W)) {

  } 
  if (Input::is_down(KeyCode::S)) {

  } 
  if (Input::is_down(KeyCode::A)) {

  } 
  if (Input::is_down(KeyCode::D)) {

  }
}

void GameObject::post_update() {
}

void GameObject::render(HDC dc) {
}

}
