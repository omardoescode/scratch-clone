#pragma once

#include "Character.hpp"
#include "Vector.hpp"
#include <memory>
#include <stack>

class Script;

/*
 * @brief Represent an execution of a script when the game starts
 *
 * @description
 * The script execution maintians a stack of script where the topmost script
 * represents the block that is currently running
 *
 * An execution may have more than one script with instructions that support
 * scripts as children like `forever`, `repeat` and `if`. The current
 * instruciton runs by fetching both the latest stack and the latest current
 * index and execute the instruction at that index
 *
 * The execution runs instructions[index] of the current stack and the
 * instructions are responsible for determining if it's allowed to proceed to
 * the next instruction (Similar to the program counter where some instructions
 * may modify it like `jmp`)
 */

class ScriptExecution {
public:
  ScriptExecution(std::shared_ptr<Character>);

  /*
   * @brief run the next instruction in the current stack
   */
  void execute(SymbolTable &symbol_table, Vector<double> mouse_pointer,
               Time time);

  /*
   * @brief advance the current instruction pointer
   *
   * @note Must check if index==size,in such a case, delete from the current
   * stack and get back to a previous stack or just remove the current stack
   */
  void advance();

  /*
   * @brief Getter for character
   */
  std::shared_ptr<Character> get_character();

private:
  std::stack<std::shared_ptr<Script>> _scripts;
  std::stack<int> _current_index;
  std::shared_ptr<Character> _character;
  bool _is_finished;
};
