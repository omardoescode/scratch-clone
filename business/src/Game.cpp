#include "Game.hpp"

Game::Game() {
  // TODO: Initialize Game State
}

Game &Game::get_instance() {
  static Game game;
  return game;
}

std::vector<DTO::Section> Game::get_sections() {
  auto sections = Command::get_sections();
  std::vector<DTO::Section> result;

  // for (auto &sec : sections)
  //   result.push_back({sec.first, sec.second});

  return result;
}
