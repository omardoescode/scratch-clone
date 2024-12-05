#include "Instructions/InstructionWithValues.hpp"

void InstructionWithValues::upsert_value(std::string &&value_name,
                                         Value value) {
  values[std::move(value_name)] = value;
}

Value &InstructionWithValues::get_value(std::string &&key) {
  return values[key];
}
