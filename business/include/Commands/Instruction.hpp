#pragma once
#include "CharacterManager.hpp"
#include "Commands/Command.hpp"
#include "SymbolTable.hpp"
#include "Time.hpp"
#include "Vector.hpp"

class Character;
class ScriptExecution;

class Instruction : public Command {
public:
  /*
   * @brief Constructor
   */
  Instruction(DTO::SectionType section);

  /*
   * @brief Execute the instruction
   *
   * @param character The character on which this instruction will run
   * @param symbol_table The running game's symbol table
   * @param execution The script exeuction that is calling this instruction
   * @param mouse_pointer The current mouse pointer
   * @param time The time since the game has started
   */

  virtual void execute(CharacterManager &character, SymbolTable &symbol_table,
                       ScriptExecution &exeuction, Vector<double> mouse_pointer,
                       Time time) = 0;

  /*
   * @brief Destructor
   */
  virtual ~Instruction() = default;

  /*
   * @brief Set Starter
   */
  void set_starter(bool starter);

private:
  bool starter; // `true` if the instruction is one that handles the evntBus and
                // allowed to start a ScriptExecution
};
