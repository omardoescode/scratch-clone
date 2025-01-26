#include "Commands/Constant.hpp"
#include "DTOs/Sections.hpp"
#include "DataType.hpp"
#include <string>

Constant::Constant(DataType type, const Value &value)
    : Expression(DTO::UNKNOWN, type), _value(value) {}
Constant::Constant(DataType type, Value &&value)
    : Expression(DTO::UNKNOWN, type), _value(std::move(value)) {}

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
  return _value;
}

Value Constant::get_value() const { return _value; }

void Constant::set_value(std::string &&value) { _value = value; }
