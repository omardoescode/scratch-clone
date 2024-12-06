#pragma once
#include "Instructions/Instruction.hpp"
#include <list>
#include <memory>

class InstructionStack {
private:
  std::list<std::shared_ptr<Instruction>> list;

public:
  void execute(Game &, Character &);
  bool empty();
  void add_instruction(unsigned int index, std::shared_ptr<Instruction> &);
};
