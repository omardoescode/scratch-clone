#pragma once
#include "CharacterManager.hpp"
#include "Commands/IExpression.hpp"
#include "Value.hpp"
#include <map>
#include <memory>
#include <string>

class Expression : public IExpression {
public:
  virtual Value execute(CharacterManager &character, SymbolTable &symbol_table,
                        ScriptExecution &exeuction,
                        Vector<double> mouse_pointer, Time time) override = 0;
  virtual ~Expression() = default;

  /*
   * @brief Add/Insert a value to be altered with name `key` and info `value`
   */
  void set_expression(std::string &&key, std::shared_ptr<IExpression>);

private:
  std::map<std::string, std::shared_ptr<IExpression>>
      expressions; // Map distinct names set by each instruction to the
                   // expressions
};
