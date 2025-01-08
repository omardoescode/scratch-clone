#pragma once
#include "Commands/CommandPart.hpp"
#include "DTOs/Sections.hpp"
#include <vector>

class Command {
public:
  // The types of available sections
  enum class Section {
    MOTION,
    CONTROL,
    SENSING,
    LOOKS,
    SOUND,
    OPERATORS,
    VARIABLES
  };

public:
  Command(Section);

  /*
   * @brief Getter for section
   */
  Section get_section() const;

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
  Section section;
  std::vector<CommandPart> parts;
};
