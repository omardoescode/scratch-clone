#include "Commands/CommandSet.hpp"
#include "Commands/CommandSet/MoveStepsInstruction.hpp"
#include "DTOs/Sections.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>

CommandSet::CommandSet() { initialize_commands(); }

CommandSet &CommandSet::get_instance() {
  static CommandSet instance;
  return instance;
}

void CommandSet::initialize_commands() {
  commands[DTO::MOTION].push_back(std::make_shared<MoveStepsInstruction>());
  commands[DTO::MOTION].push_back(std::make_shared<MoveStepsInstruction>());
  commands[DTO::LOOKS].push_back(std::make_shared<MoveStepsInstruction>());
}

std::vector<std::shared_ptr<Command>>
CommandSet::get_section_commands(DTO::SectionType section) const {
  auto itr = commands.find(section);
  if (itr == commands.end()) {
    std::cerr << "Uninitialized section yet!" << std::endl;
    return {};
  }
  return itr->second;
}
