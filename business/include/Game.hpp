#pragma once
#include "CharacterManager.hpp"
#include "Events/EventBroker.hpp"
#include "Instructions/ScriptExecution.hpp"
#include "SymbolTable.hpp"
#include <list>

class Game {
private:
  enum GameState { RUNNING, EDITING };

public:
  Game();

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

private:
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
  CharacterManger character_manager;
  GameState state;
  EventBroker event_broker;
  std::list<ScriptExecution> executions;
};
