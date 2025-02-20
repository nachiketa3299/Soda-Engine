#include "Soda/GEntity.h"

#include <string>

namespace soda {

GEntity::~GEntity() {}

std::wstring const& GEntity::get_name() const {
  return name_;
}

void GEntity::set_name(std::wstring const & name) {
  name_ = name;
}

}
