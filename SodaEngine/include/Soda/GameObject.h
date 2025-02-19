#pragma once

#include <windows.h>

namespace soda {

class GameObject {
  public:
    GameObject() = default;
    ~GameObject() = default;

    void set_pos(int x, int y);

    int get_pos_x() const;
    int get_pos_y() const;

    void pre_update();
    void update();
    void post_update();
    void render(HDC dc);

  private:
    int x_;
    int y_;
};

}