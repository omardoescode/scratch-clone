#pragma once

#include "Commands/Command.hpp"
#include "DTOs/Sections.hpp"
#include <future>
#include <map>
#include <string>
#include <vector>

class CommandSet {
public:
  /*
   * @brief Give access to the singleton's instance
   */
  static CommandSet &get_instance();

  /*
   * @brief Getter for a section's commands
   */
  std::vector<std::shared_ptr<Command>>
      get_section_commands(DTO::SectionType) const;

private:
  /*
   * @brief A private constructor for the singleton
   *
   * To access, use `CommandSet::get_instance()`
   */
  CommandSet();

  /*
   * @brief Initialize the command set by adding all needed commands to it
   */
  void initialize_commands();

private:
  std::map<DTO::SectionType, std::vector<std::shared_ptr<Command>>> commands;
};
