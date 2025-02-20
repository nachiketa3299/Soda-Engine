#include "LoadScene.h"

#include <Soda/SceneManager.h>

#include "TestGame/include/PlayScene.h"

void LoadScenes() {
  soda::SceneManager::create_scene<tg::PlayScene>(L"Play_Scene");
  soda::SceneManager::load_scene(L"Play_Scene");
}