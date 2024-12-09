#pragma once
#include "Commands/Expression.hpp"
#include "Commands/Instruction.hpp"
#include <map>
#include <memory>
#include <string>

/*
 * @brief Represent an instruction with values that may change
 */
class InstructionWithExpressions : public Instruction {

public:
  virtual void execute(Character &character, SymbolTable &symbol_table,
                       ScriptExecution &exeuction, Vector<double> mouse_pointer,
                       Time time) override = 0;
  virtual ~InstructionWithExpressions() = default;

protected:
  /*
   * @brief Add/Insert a value to be altered with name `key` and info `value`
   */
  void set_expression(std::string &&key, std::shared_ptr<Expression>);

private:
  std::map<std::string, std::shared_ptr<Expression>>
      expressions; // Map distinct names set by each instruction to the
                   // expressions
};
