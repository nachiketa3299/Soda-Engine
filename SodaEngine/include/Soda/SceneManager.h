#pragma once

#include <map>
#include <string>

#include "Soda/WinCommon.h"

namespace soda {

class Scene;

class SceneManager {
public:
  // TODO 그냥 T를 리턴하면 왜 안되는 것인지?
  template<typename T>
  static T *create_scene(std::wstring const &name) {
    T *sc = new T();
    sc->set_name(name);
    sc->initialize();
    sc_tree_.insert({name, sc});

    return sc;
  }

  /*!
   * @brief \p name 이름을 가진 씬을 존재하는 씬들 중에서 찾은 후, 활성 씬으로 만들고 반환한다.
   * @note 만일 \p name 이름을 가진 씬이 존재하지 않으면, \p nullptr 을 반환한다.
   */
  static Scene *load_scene(std::wstring const &name);

public:
  static void initialize();

  static void pre_update();
  static void update();
  static void post_update();

  static void render(HDC hdc);

public:
  static Scene *get_a_scene();

private:
  static std::map<std::wstring, Scene *> sc_tree_;
  static Scene *a_scene_;
};

}