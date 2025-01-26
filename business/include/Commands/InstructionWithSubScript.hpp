#pragma once
#include "Commands/Instruction.hpp"
#include "Commands/Script.hpp"
#include "DTOs/Sections.hpp"
#include <memory>

class InstructionWithSubScript : public Instruction {
public:
  InstructionWithSubScript(DTO::Section section);
  virtual void execute(CharacterManager &character, SymbolTable &symbol_table,
                       ScriptExecution &exeuction, Vector<double> mouse_pointer,
                       Time time) override = 0;
  virtual ~InstructionWithSubScript();

  /*
   * @brief Setter for sub_script
   */
  void set_stack(std::unique_ptr<Script> &new_script);

private:
  std::unique_ptr<Script> sub_script;
};
