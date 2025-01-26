#pragma once

#include "Commands/Instruction.hpp"
class MoveStepsInstruction : public Instruction {
public:
  MoveStepsInstruction();
  void execute(CharacterManager &character, SymbolTable &symbol_table,
               ScriptExecution &exeuction, Vector<double> mouse_pointer,
               Time time) override;
};
