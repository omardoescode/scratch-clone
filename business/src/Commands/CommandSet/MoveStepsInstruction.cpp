#include "Commands/CommandSet/MoveStepsInstruction.hpp"
#include "Character.hpp"
#include "Commands/CommandPart.hpp"
#include "Commands/Constant.hpp"
#include "Commands/Instruction.hpp"
#include "Commands/ScriptExecution.hpp"
#include "DTOs/Sections.hpp"
#include <cassert>
#include <cmath>
#include <memory>

MoveStepsInstruction::MoveStepsInstruction() : Instruction(DTO::MOTION) {
  std::shared_ptr<Expression> initial_value = std::make_shared<Constant>(0.f);
  add_subexpression("steps", initial_value);

  set_parts({{CommandPartType::TEXT, "move "},
             {CommandPartType::EXPRESSION, "steps"},
             {CommandPartType::TEXT, " steps"}});
}

void MoveStepsInstruction::execute(CharacterManager &character_mng,
                                   SymbolTable &symbol_table,
                                   ScriptExecution &execution,
                                   Vector<double> mouse_pointer, Time time) {
  Value steps = retrieve_subexpression("steps")->execute(
      character_mng, symbol_table, execution, mouse_pointer, time);

  int steps_value = std::stoi(steps);

  auto character = execution.get_character();
  PositionVector_t update = {cos(character->get_rotation()) * steps_value,
                             sin(character->get_rotation()) * steps_value};

  character->update_position(character->get_position() + update);

  execution.advance();
}
