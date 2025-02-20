#include "../include/Character.h"

#include <Soda/WinCommon.h>

#include <Soda/GObj.h>

namespace tg {

void Character::initialize() {
  soda::GObj::initialize();
}

void Character::pre_update() {
  soda::GObj::pre_update();
}

void Character::update() {
  soda::GObj::update();
}

void Character::post_update() {
  soda::GObj::post_update();
}

void Character::render(HDC dc) {
  soda::GObj::render(dc);
}

}
