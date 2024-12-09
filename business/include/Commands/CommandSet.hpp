#pragma once

#include "Commands/Command.hpp"
#include <map>
#include <string>
#include <vector>

class CommandSet {
public:
  /*
   * @brief Give access to the singleton's instance
   */
  CommandSet &get_instance();

  /*
   * @brief Getter for a section's commands
   */
  const std::vector<Command> &get_section_commands(Command::Section) const;

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
  std::map<Command::Section, std::vector<Command>> commands;
  static std::map<Command::Section, std::string> colors;
};
