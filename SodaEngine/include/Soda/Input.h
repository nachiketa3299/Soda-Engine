#pragma once

#include <array>

namespace soda {

enum class KeyState {
  Down, Pressed, Up, None
};

enum class KeyCode {
  Q, W, E, R, T, Y, U, I, O, P,
  A, S, D, F, G, H, J, K, L,
  Z, X, C, V, B, N, M,
  LArrow, RArrow, UArrow, DArrow,
  End, None
};


class Input {
public:
  struct Key {
    KeyCode code{KeyCode::None};
    KeyState state{KeyState::None};
    bool is_pressed{false};
  };
public:
  static void initialize();
  static void update();

  static bool is_down(KeyCode kc);
  static bool is_up(KeyCode kc);
  static bool is_pressed(KeyCode kc);

  /// @brief \p KeyCode 를 \p char 로 변환한다.
  static char ctoa(KeyCode key);

private:
  static std::array<Key, (size_t)KeyCode::End> keys_;
  static std::array<char, (size_t)KeyCode::End> ch_keys_;
};

};