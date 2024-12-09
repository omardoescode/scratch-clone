#pragma once
#include "Commands/Instruction.hpp"
#include <list>
#include <memory>

class Script {
private:
  std::list<std::shared_ptr<Instruction>> instructions;

public:
  /*
   * @brief Check if the stack has no instructions
   *
   * @return returns `true` if empty
   */
  bool empty() const;

  /*
   * @brief Add an instruction to the list at index `index`
   */
  void add_instruction(unsigned int index, std::shared_ptr<Instruction> &);

  /*
   * @brief Add a subscriber to the event bus by utilitizing the firs `starter`
   * instruction
   */
  void subscribe();
};
