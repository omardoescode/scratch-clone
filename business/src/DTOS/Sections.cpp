#include "DTOs/Sections.hpp"
namespace DTO {
std::string sectiontype_name_mapper(SectionType type) {
  {
    switch (type) {
    case MOTION:
      return "Motion";
    case CONTROL:
      return "Control";
    case LOOKS:
      return "Looks";
    case SENSING:
      return "Sensing";
    case SOUND:
      return "Sound";
    case OPERATORS:
      return "Operators";
    case VARIABLES:
      return "Variables";
    default:
      throw std::runtime_error("Unidentified section type");
    }
  }
}
} // namespace DTO
