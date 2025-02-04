#include "Game.hpp"

Game::Game() : state{EDITING} {
  // TODO: Initialize Game State
}

Game &Game::get_instance() {
  static Game game;
  return game;
}

std::map<DTO::SectionType, DTO::SectionData> Game::get_sections_map() {
  return Command::get_sections();
}

std::vector<std::unique_ptr<Instruction>>
Game::get_instructions(DTO::SectionType) {
  return {};
}
