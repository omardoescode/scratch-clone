#pragma once
#include "Commands/IExpression.hpp"
class Constant : public IExpression {
public:
  /*
   * @brief Constructor
   *
   * @param type The data type for the value
   * @param value The initial value for `value` (lvalue)
   */
  Constant(DataType type, const Value &value);

  /*
   * @brief Constructor
   *
   * @param type The data type for the value
   * @param value The initial value for `value` (lvalue)
   */
  Constant(DataType type, Value &&value);

  /**
   * @brief Constructor for string value (lvalue)
   */
  Constant(const std::string &);

  /**
   * @brief Constructor for string value (rvalue)
   */
  Constant(std::string &&);

  /**
   * @brief Constructor for numbers
   */
  Constant(float);

  /**
   * @brief Constructor for booleans
   */
  Constant(bool);

  /*
   * @brief Constant
   */
  Value execute(CharacterManager &character, SymbolTable &symbol_table,
                ScriptExecution &exeuction, Vector<double> mouse_pointer,
                Time time) override;

private:
  Value value;
};
