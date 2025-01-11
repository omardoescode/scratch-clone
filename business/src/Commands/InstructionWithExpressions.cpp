#include "Commands/InstructionWithExpressions.hpp"
#include <stdexcept>

InstructionWithExpressions::InstructionWithExpressions(DTO::SectionType section)
    : Instruction(section) {}

void InstructionWithExpressions::set_expression(
    std::string &&key, std::shared_ptr<IExpression> expression) {
  expressions[std::move(key)] = expression;
}
std::shared_ptr<IExpression>
InstructionWithExpressions::get_expression(std::string &&key) {
  auto itr = expressions.find(std::move(key));
  if (itr == expressions.end())
    throw std::runtime_error("Invalid key to an expression");
  return (*itr).second;
}
