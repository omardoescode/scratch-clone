#pragma once
#include "Commands/Command.hpp"
#include "SymbolTable.hpp"
#include "Time.hpp"
#include "Vector.hpp"
#include <string>
#include <vector>

class Character;
class ScriptExecution;

class Instruction : Command {
public:
  /*
   * @brief Constructor
   *
   * @param starter The value of `starter`
   */
  Instruction(bool starter);

  /*
   * @brief Execute the instruction
   *
   * @param character The character on which this instruction will run
   * @param symbol_table The running game's symbol table
   * @param execution The script exeuction that is calling this instruction
   * @param mouse_pointer The current mouse pointer
   * @param time The time since the game has started
   */

  virtual void execute(Character &character, SymbolTable &symbol_table,
                       ScriptExecution &exeuction, Vector<double> mouse_pointer,
                       Time time) = 0;

  /*
   * @brief Destructor
   */
  virtual ~Instruction() = default;

private:
  bool starter; // `true` if the instruction is one that handles the evntBus and
                // allowed to start a ScriptExecution
};
