#pragma once
#include "Commands/IExpression.hpp"
class Constant : public IExpression {
public:
  /*
   * @brief Constructor
   *
   * @param value The initial value for `value`
   */
  Constant(DataType type, Value value);

  /*
   * @brief Constant
   */
  Value execute(CharacterManager &character, SymbolTable &symbol_table,
                ScriptExecution &exeuction, Vector<double> mouse_pointer,
                Time time) override;

private:
  Value value;
};
