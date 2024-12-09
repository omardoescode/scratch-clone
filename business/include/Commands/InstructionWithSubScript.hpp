#pragma once
#include "Commands/Instruction.hpp"
#include "Commands/Script.hpp"
#include <memory>

class InstructionWithSubScript : public Instruction {
private:
  std::unique_ptr<Script> stack;

public:
  virtual void execute(Character &character, SymbolTable &symbol_table,
                       ScriptExecution &exeuction, Vector<double> mouse_pointer,
                       Time time) override = 0;
  virtual ~InstructionWithSubScript();

  /*
   * @brief delete the old stack if any and make it `new_script`
   */
  void set_stack(std::unique_ptr<Script> &new_script);
};
