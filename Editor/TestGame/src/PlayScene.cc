#include "../include/PlayScene.h"

#include <Soda/GObj.h>
#include <Soda/Scene.h>
#include <Soda/Comp/Transform.h>
#include <Soda/Comp/SpriteRenderer.h>
#include <Soda/Math/V2.h>

#include "../include/Character.h"

namespace tg {

void PlayScene::initialize() {

  // 씬 정의 시작
  auto *c = new Character();
    auto *t = c->add_comp<soda::Transform>();
      t->set_pos(soda::V2(.0f, .0f));
      t->set_name(L"Transform");
    auto *sr = c->add_comp<soda::SpriteRenderer>();
      sr->set_name(L"SpriteRenderer");
      sr->load_image(L"D:\\rznbrn\\Projects\\Soda\\Editor\\TestGame\\resources\\rukia.png");

  // 씬 정의 끝

  add_g_obj(c);

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

}