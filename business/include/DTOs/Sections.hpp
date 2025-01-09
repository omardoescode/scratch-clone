#pragma once

#include "DTOs/DTO.hpp"
#include <stdexcept>
#include <string>
namespace DTO {
enum SectionType {
  MOTION,
  CONTROL,
  LOOKS,
  SENSING,
  SOUND,
  OPERATORS,
  VARIABLES,
};
struct Section {
  SectionType type;
  Color color;
};

std::string sectiontype_name_mapper(SectionType type);

} // namespace DTO
