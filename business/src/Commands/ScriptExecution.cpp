#include "Commands/ScriptExecution.hpp"

ScriptExecution::ScriptExecution(std::shared_ptr<Character> character)
    : _character(character) {}

void ScriptExecution::advance() {
  // TODO: Do later!
}
std::shared_ptr<Character> ScriptExecution::get_character() {
  return _character;
}
