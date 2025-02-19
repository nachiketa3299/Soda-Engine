#pragma once

#include <string>

namespace soda {

class GEntity {
public:
  GEntity() = default;
  virtual ~GEntity() = 0;

public:
  std::wstring const &get_name() const;
  void set_name(std::wstring const &name);

private:
  std::wstring name_{L"not-assigned"};
};

}
