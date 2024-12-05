#include "Instructions/Instruction.hpp"
void Instruction::set_command(ListOfParts &value) { parts = std::move(value); }
