#include "Commands/Constant.hpp"
#include "Commands/IExpression.hpp"
#include "DTOs/Sections.hpp"
#include "DataType.hpp"
#include <string>

Constant::Constant(DataType type, const Value &value)
    : IExpression(DTO::UNKNOWN, type), value(value) {}
Constant::Constant(DataType type, Value &&value)
    : IExpression(DTO::UNKNOWN, type), value(std::move(value)) {}

Constant::Constant(const std::string &value)
    : Constant(DataType::TEXT, value) {}
Constant::Constant(std::string &&value)
    : Constant(DataType::TEXT, std::move(value)) {}
Constant::Constant(float value)
    : Constant(DataType::NUMBER, std::to_string(value)) {}
Constant::Constant(bool value)
    : Constant(DataType::BOOLEAN, std::to_string(value)) {}

Value Constant::execute(CharacterManager &character, SymbolTable &symbol_table,
                        ScriptExecution &exeuction,
                        Vector<double> mouse_pointer, Time time) {
  return value;
}