#include "Game.hpp"

Game::Game() : state{EDITING} {
  // TODO: Initialize Game State
}

Game &Game::get_instance() {
  static Game game;
  return game;
}

std::vector<DTO::Section> Game::get_sections() {
  return Command::get_sections();
}

std::vector<std::unique_ptr<Instruction>>
Game::get_instructions(DTO::SectionType) {
  return {};
}
