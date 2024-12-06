
#include "Instructions/InstructionSet/MoveStepsInstruction.hpp"
#include "Character.hpp"
#include "Instructions/Instruction.hpp"
#include "Instructions/InstructionPart.hpp"
#include <cassert>
#include <cmath>
#include <variant>

MoveStepsInstruction::MoveStepsInstruction() {
  upsert_value("steps", 0);

  ListOfParts parts = {
      {"move to", InstructionPart::TEXT},
      {"steps", InstructionPart::VALUE},
  };
  set_command(parts);
}

void MoveStepsInstruction::execute(Game &game, Character &character) {
  Value steps = get_value("steps");
  assert(std::holds_alternative<int>(steps));

  int steps_value = static_cast<double>(std::get<int>(steps));
  PositionVector_t update = {cos(character.get_rotation()) * steps_value,
                             sin(character.get_rotation()) * steps_value};

  character.update_position(character.get_position() + update);
}
