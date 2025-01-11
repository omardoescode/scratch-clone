#pragma once
#include "Commands/IExpression.hpp"
#include "Commands/Instruction.hpp"
#include "DTOs/Sections.hpp"
#include <map>
#include <memory>
#include <string>

/*
 * @brief Represent an instruction with values that may change
 */
class InstructionWithExpressions : public Instruction {

public:
  InstructionWithExpressions(DTO::SectionType section);

  virtual void execute(CharacterManager &character, SymbolTable &symbol_table,
                       ScriptExecution &exeuction, Vector<double> mouse_pointer,
                       Time time) override = 0;
  virtual ~InstructionWithExpressions() = default;

protected:
  /*
   * @brief Add/Insert a value to be altered with name `key` and info `value`
   */
  void set_expression(std::string &&key, std::shared_ptr<IExpression>);

  std::shared_ptr<IExpression> get_expression(std::string &&key);

private:
  std::map<std::string, std::shared_ptr<IExpression>>
      expressions; // Map distinct names set by each instruction to the
                   // expressions
};
