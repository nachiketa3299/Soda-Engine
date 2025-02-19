#include "Soda/Scene.h"
#include "Soda/GObj.h"

namespace soda {

Scene::~Scene() {
}

void Scene::initialize() {
  for (auto *g_obj: g_objs_) {
    g_obj->initialize();
  }
}

void Scene::update() {
  for (auto *g_obj: g_objs_) {
    g_obj->update();
  }
}

void Scene::post_update() {
  for (auto *g_obj: g_objs_) {
    g_obj->post_update();
  }
}

void Scene::render(HDC hdc) {
  for (auto *g_obj: g_objs_) {
    g_obj->render(hdc);
  }
}

void Scene::add_g_obj(GObj *g_obj) {
  g_objs_.push_back(g_obj);
}

}
