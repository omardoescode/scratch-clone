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
 * scripts as children like `forever`, `repeat` and `if`
 *
 * The execution runs instructions[index] of the current stack and the
 * instructions are responsible for determining if it's allowed to proceed to
 * the next instruction (Similar to the program counter where some instructions
 * may modify it like `jmp`)
 */

class ScriptExecution {
public:
  ScriptExecution();

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

private:
  std::stack<std::shared_ptr<Script>> scripts;
  std::stack<int> current_index;
  std::shared_ptr<Character> character;
  bool is_finished;
};
