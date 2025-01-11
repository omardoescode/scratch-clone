#pragma once
#include "Commands/CommandPart.hpp"
#include "DTOs/Sections.hpp"
#include <vector>

class Command {
public:
  Command(DTO::SectionType);

  /*
   * @brief Getter for section
   */
  DTO::SectionType get_section() const;

  /*
   * @brief Getter for parts
   */
  const std::vector<CommandPart> &get_parts();

  /*
   * @brief Return all sections names and colors
   */
  static std::vector<DTO::Section> get_sections();

protected:
  /*
   * @brief Setter for parts
   */
  void set_parts(std::vector<CommandPart> &&);

private:
  DTO::SectionType _section;
  std::vector<CommandPart> _parts;
};
