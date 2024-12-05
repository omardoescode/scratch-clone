#pragma once
#include "Instructions/Instruction.hpp"
#include <map>
#include <string>
#include <variant>

/*
 * @brief Represent a value/variable in an instruction
 * Can be seen as a variable in the instruction scope
 */
typedef std::variant<std::string, int> Value;

/*
 * @brief Represent an instruction with values that may change
 */
class InstructionWithValues : public Instruction {
private:
  std::map<std::string, Value> values;

  /*
   * @brief Add/Insert a value to be altered
   */
  void upsert_value(std::string &&, Value);

public:
  virtual void execute();
  virtual ~InstructionWithValues() = default;
};
