#include "Soda/GObj.h"

#include "Soda/Comp/Comp.h"

namespace soda {

GObj::~GObj() {
  for (Comp *comp: comps_) {
    delete comp;
    comp = nullptr;
  }
}

void GObj::initialize() {
  for (Comp *comp: comps_) {
    comp->initialize();
  }
}

void GObj::pre_update() {
  for (Comp *comp: comps_) {
    comp->pre_update();
  }
}

void GObj::update() {
  for (Comp *comp: comps_) {
    comp->update();
  }
}

void GObj::post_update() {
  for (Comp *comp: comps_) {
    comp->post_update();
  }
}

void GObj::render(HDC dc) {
  for (Comp *comp: comps_) {
    comp->render(dc);
  }
}

}
