#pragma once

#include "DTOs/DTO.hpp"
#include <string>
#include <vector>
namespace DTO {
enum SectionType {
  UNKNOWN = -1,
  MOTION = 0,
  CONTROL,
  LOOKS,
  SENSING,
  SOUND,
  OPERATORS,
  VARIABLES,
};

static const std::vector<SectionType> sections = {
    MOTION, CONTROL, LOOKS, SENSING, SOUND, OPERATORS, VARIABLES};

struct SectionData {
  Color color;
};

std::string sectiontype_name_mapper(SectionType type);

} // namespace DTO
