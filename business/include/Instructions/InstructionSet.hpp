#pragma once
#include "Instructions/Instruction.hpp"
#include <functional>
#include <map>
#include <memory>
#include <vector>

class InstructionSet {
private:
  std::map<std::string, std::vector<std::unique_ptr<Instruction>>> sections;

private:
  void init_sections();
  void init_motion_instructions();

  void add_instruction(std::string section,
                       std::function<void(Game &, Character)> execute,
                       ListOfParts parts);

public:
  InstructionSet();
};
