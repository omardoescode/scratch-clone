#pragma once

#include "DTOs/Sections.hpp"
#include "Widget.hpp"
/**
 * @brief This represents the instruction set of a specific section. Instead of
 * keeping loading them from presentation, they are loaded into a map (external
 * usage of course)
 */
class SectionInstructionSetView : public Widget {
public:
  SectionInstructionSetView(unsigned width, unsigned height);

private:
  DTO::SectionType section_type;
};
