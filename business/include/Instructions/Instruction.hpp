#pragma once
#include "Character.hpp"
#include "Game.hpp"
#include "Instructions/InstructionPart.hpp"
#include <string>
#include <vector>

typedef std::vector<std::pair<std::string, InstructionPart>> ListOfParts;
/*
 * @brief Represent an instruction interface
 */
class Instruction {
private:
  ListOfParts parts;

public:
  /*
   * @brief Execute the instruction
   */
  virtual void execute(Game &, Character &) = 0;

  /*
   * @brief Set a representation of the command using text and values
   */
  void set_command(ListOfParts &);

  /*
   * @brief Destructor
   */
  virtual ~Instruction() = default;
};
