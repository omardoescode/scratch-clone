
#include "Instructions/InstructionSet/MoveStepsInstruction.hpp"
#include "Instructions/Instruction.hpp"
#include "Instructions/InstructionParts.hpp"

MoveStepsInstruction::MoveStepsInstruction() {
  upsert_value("steps", 0);

  ListOfParts parts = {
      {"move to", InstructionPart::TEXT},
      {"steps", InstructionPart::VALUE},
  };
  set_command(parts);
}
void MoveStepsInstruction::execute(Game &game, Character &character) {
  // TODO: Finish the execute function
}
