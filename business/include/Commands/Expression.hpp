#pragma once
#include "CharacterManager.hpp"
#include "Commands/Command.hpp"
#include "Commands/ScriptExecution.hpp"
#include "DTOs/Sections.hpp"
#include "DataType.hpp"
#include "SymbolTable.hpp"
#include "Value.hpp"

class Expression : public Command {
public:
  /*
   * @brief Constructor
   *
   * @param The return type for IExpression
   */
  Expression(DTO::SectionType type, DataType return_type);

  virtual Value execute(CharacterManager &character, SymbolTable &symbol_table,
                        ScriptExecution &exeuction,
                        Vector<double> mouse_pointer, Time time) = 0;
  virtual ~Expression() = default;

  /**
   * @brief Get the datatype
   */
  DataType get_datatype() const;

private:
  DataType _datatype;
};
