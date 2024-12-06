#pragma once

#include "Instructions/InstructionWithValues.hpp"
class MoveStepsInstruction : public InstructionWithValues {
public:
  MoveStepsInstruction();
  void execute(Game &, Character &);
};
