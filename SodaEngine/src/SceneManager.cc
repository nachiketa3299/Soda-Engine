#include "Soda/SceneManager.h"
#include "Soda/Scene.h"

namespace soda {

std::map<std::wstring, Scene *> SceneManager::sc_tree_{};

Scene *SceneManager::a_scene_{nullptr};

void SceneManager::initialize() {
  //a_scene_->initialize();
}

Scene *SceneManager::load_scene(std::wstring const &name) {
  std::map<std::wstring, Scene *>::iterator it 
    = sc_tree_.find(name);
  
  if (it == sc_tree_.end()) {
    return nullptr;
  }

  return a_scene_ = it->second;
}

void SceneManager::update() {
  a_scene_->update();
}

void SceneManager::post_update() {
  a_scene_->post_update();
}

void SceneManager::render(HDC hdc) {
  a_scene_->render(hdc);
}


}