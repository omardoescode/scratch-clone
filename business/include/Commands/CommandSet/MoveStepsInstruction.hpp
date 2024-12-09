#pragma once

#include "Commands/InstructionWithExpressions.hpp"
class MoveStepsInstruction : public InstructionWithExpressions {
public:
  MoveStepsInstruction();
  void execute(CharacterManager &character, SymbolTable &symbol_table,
               ScriptExecution &exeuction, Vector<double> mouse_pointer,
               Time time) override;
};
