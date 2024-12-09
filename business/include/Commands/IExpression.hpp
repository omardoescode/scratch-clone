#pragma once

#include "CharacterManager.hpp"
#include "Commands/Command.hpp"
#include "Commands/Instruction.hpp"
#include "DataType.hpp"
#include "SymbolTable.hpp"
#include "Value.hpp"
class IExpression : public Command {
public:
  /*
   * @brief Constructor
   *
   * @param The return type for IExpression
   */
  IExpression(DataType return_type);

  /*
   * @brief Execute the expression
   */
  virtual Value execute(CharacterManager &character, SymbolTable &symbol_table,
                        ScriptExecution &exeuction,
                        Vector<double> mouse_pointer, Time time) = 0;

private:
  DataType return_type;
};
