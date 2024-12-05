#include "Instructions/InstructionWithStack.hpp"

void InstructionWithStack::set_stack(std::unique_ptr<InstructionStack> &value) {
  stack = std::move(value);
}
