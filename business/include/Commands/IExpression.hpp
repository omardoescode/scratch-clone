#pragma once

#include "CharacterManager.hpp"
#include "Commands/Command.hpp"
#include "Commands/Instruction.hpp"
#include "DTOs/Sections.hpp"
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
  IExpression(DTO::SectionType type, DataType return_type);

  /*
   * @brief Execute the expression
   */
  virtual Value execute(CharacterManager &character, SymbolTable &symbol_table,
                        ScriptExecution &exeuction,
                        Vector<double> mouse_pointer, Time time) = 0;

  /**
   * @brief Getter for return type
   */
  DataType get_return_type() const;

private:
  DataType _return_type;
};
