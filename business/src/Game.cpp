#include "Game.hpp"

Game::Game() {
  // TODO: Initialize Game State
}

Game &Game::get_instance() {
  static Game game;
  return game;
}

std::vector<DTO::Section> Game::get_sections() {
  return Command::get_sections();
}
