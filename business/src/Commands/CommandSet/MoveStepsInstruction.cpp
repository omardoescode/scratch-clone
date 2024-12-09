#include "Commands/CommandSet/MoveStepsInstruction.hpp"
#include "Character.hpp"
#include "Commands/CommandPart.hpp"
#include "Commands/Constant.hpp"
#include "Commands/Instruction.hpp"
#include "Commands/InstructionWithExpressions.hpp"
#include "Commands/ScriptExecution.hpp"
#include "DataType.hpp"
#include <cassert>
#include <cmath>
#include <memory>

MoveStepsInstruction::MoveStepsInstruction()
    : InstructionWithExpressions(Section::MOTION) {
  auto initial_value = std::make_shared<Constant>(DataType::NUMBER, 0);
  set_expression("steps", initial_value);

  set_parts({{CommandPartType::TEXT, "move "},
             {CommandPartType::EXPRESSION, "steps"},
             {CommandPartType::TEXT, " steps"}});
}

void MoveStepsInstruction::execute(CharacterManager &character_mng,
                                   SymbolTable &symbol_table,
                                   ScriptExecution &execution,
                                   Vector<double> mouse_pointer, Time time) {
  Value steps = get_expression("steps")->execute(
      character_mng, symbol_table, execution, mouse_pointer, time);

  int steps_value = static_cast<double>(std::stoi(steps));

  auto character = execution.get_character();
  PositionVector_t update = {cos(character->get_rotation()) * steps_value,
                             sin(character->get_rotation()) * steps_value};

  character->update_position(character->get_position() + update);

  execution.advance();
}
