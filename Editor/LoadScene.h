#pragma once

#include <Soda/SceneManager.h>

#include "PlayScene.h"

namespace soda {

void LoadScenes() {
  SceneManager::create_scene<PlayScene>(L"Play_Scene");
  SceneManager::load_scene(L"Play_Scene");
}

}