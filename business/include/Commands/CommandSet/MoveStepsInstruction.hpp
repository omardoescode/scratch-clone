#pragma once

#include "Commands/InstructionWithExpressions.hpp"
class MoveStepsInstruction : public InstructionWithExpressions {
public:
  MoveStepsInstruction();
  void execute(Character &character, SymbolTable &symbol_table,
               ScriptExecution &exeuction, Vector<double> mouse_pointer,
               Time time) override;
};
