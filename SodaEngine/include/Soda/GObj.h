#pragma once

#include <windows.h>

#include "Soda/GEntity.h"

namespace soda {

class GObj: public GEntity {
  public:
    GObj() = default;
    ~GObj() = default;

    void set_pos(int x, int y);

    int get_pos_x() const;
    int get_pos_y() const;

public:
    void initialize();

    void pre_update();
    void update();
    void post_update();
    void render(HDC dc);

  private:
    int x_;
    int y_;
};

}