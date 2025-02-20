#include "Soda/Input.h"

#include <array>

#include "Soda/WinCommon.h"


std::array<soda::Input::Key, (size_t)soda::KeyCode::End> soda::Input::keys_;
std::array<char, (size_t)soda::KeyCode::End> soda::Input::ch_keys_;

void soda::Input::initialize() {
  // 키 코드를 keys_에 초기화
  for (size_t i = 0; i < keys_.size(); ++i) {
    keys_[i].code = static_cast<KeyCode>(i);
  }

  ch_keys_ = {
    'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
    'Z', 'X', 'C', 'V', 'B', 'N', 'M',
    VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
  };
}

char soda::Input::ctoa(KeyCode code) {
  return ch_keys_[(size_t)code];
}

void soda::Input::update() {
  for (size_t i = 0; i < keys_.size(); ++i) {
    if (GetAsyncKeyState(ctoa(keys_[i].code) & 0x8000)) {
      // 키가 눌린 경우
      if (!keys_[i].is_pressed) {
        // 이전 프레임에는 눌려 있지 않았음
        keys_[i].state = KeyState::Down;
      } else {
        // 이전 프레임에도 눌려 있었음
        keys_[i].state = KeyState::Pressed;
      }

      keys_[i].is_pressed = true;
    } else {
      // 키가 안눌린 경우
      if (!keys_[i].is_pressed) {
        keys_[i].state = KeyState::None;
      } else {
        keys_[i].state = KeyState::Up;
      }

      keys_[i].is_pressed = false;
    }
  }
}

bool soda::Input::is_down(KeyCode kc) {
  return keys_[(size_t)kc].state == KeyState::Down;
}

bool soda::Input::is_up(KeyCode kc) {
  return keys_[(size_t)kc].state == KeyState::Up;
}

bool soda::Input::is_pressed(KeyCode kc) {
  return keys_[(size_t)kc].state == KeyState::Pressed;
}