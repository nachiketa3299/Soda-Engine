#include <Soda/GObj.h>

#include "PlayScene.h"

void PlayScene::initialize() {
  auto *g_obj_0 = new soda::GObj();
  auto *g_obj_1 = new soda::GObj();

  g_obj_0->set_name(L"GO_00");
  g_obj_1->set_name(L"GO_01");

  add_g_obj(g_obj_0);
  add_g_obj(g_obj_1);

  soda::Scene::initialize();
}

void PlayScene::update() {
  soda::Scene::update();
}

void PlayScene::post_update() {
  soda::Scene::post_update();
}

void PlayScene::render(HDC hdc) {
  soda::Scene::render(hdc);
}
