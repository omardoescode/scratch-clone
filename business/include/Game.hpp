#pragma once
#include "CharacterManager.hpp"
#include "Commands/ScriptExecution.hpp"
#include "DTOs/Sections.hpp"
#include "SymbolTable.hpp"
#include <list>

class Game {
private:
  enum GameState { RUNNING, EDITING };

public:
  Game(const Game &) = delete;            // <delete the copy constructor
  Game &operator=(const Game &) = delete; // <delete the copy assignment
  /*
   * @brief Get the one instance of Game
   */
  static Game &get_instance();

  /*
   * @brief Start the game
   *
   * Subscribe to all events
   * Add an event to the event broker to indicate the game start
   */
  void start_game();

  /*
   * @brief End the game by toggling  `is_running`
   */
  void end_game();

  /*
   * @brief Run the next sequence of script executions
   */
  void run_next();

  /*
   * @brief Return the sections as DTOs
   */
  std::vector<DTO::Section> get_sections();

  /*
   * @brief Return the instructino of a specific section
   */
  std::vector<std::unique_ptr<Instruction>> get_instructions(DTO::SectionType);

private:
  /*
   * @brief Private Construcotr
   */
  Game();

  /*
   * @brief Add all commands to the command set
   */
  void initialize_command_set();

  /*
   * @brief A private helper method to subscribe to all events
   *
   * @note used by `start_game`
   */
  void subscribe_all();

private:
  SymbolTable symbol_table;
  CharacterManager character_manager;
  GameState state;
  std::list<ScriptExecution> executions;
  std::map<DTO::SectionType, std::vector<std::unique_ptr<Instruction>>>
      instruction_set;
};
