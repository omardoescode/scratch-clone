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

protected:
  /*
   * @brief Add/Insert a value to be altered with name `key` and info `value`
   */
  void upsert_value(std::string &&key, Value value);

  /*
   * @brief Get a value with name `key`
   */
  Value &get_value(std::string &&key);

public:
  virtual void execute();
  virtual ~InstructionWithValues() = default;
};
