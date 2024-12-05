#pragma once
#include "Instructions/Instruction.hpp"
#include "Instructions/InstructionStack.hpp"
#include <memory>

class InstructionWithStack : public Instruction {
private:
  std::unique_ptr<InstructionStack> stack;

public:
  void set_stack(std::unique_ptr<InstructionStack> &);
};
