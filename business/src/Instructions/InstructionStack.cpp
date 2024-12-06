#include "Instructions/InstructionStack.hpp"

void InstructionStack::execute(Game &game, Character &character) {
  for (auto &ins : list)
    ins->execute(game, character);
}

bool InstructionStack::empty() { return list.empty(); }

void InstructionStack::add_instruction(unsigned int index,
                                       std::shared_ptr<Instruction> &ins) {

  auto it = list.begin();
  std::advance(it, index);
  list.insert(it, ins);
}
