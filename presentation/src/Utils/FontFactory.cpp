#include "Utils/FontFactory.hpp"
#include <memory>

std::unique_ptr<sf::Font> FontFactory::get_primary_font() {
  auto font = std::make_unique<sf::Font>();

  // TODO: Set all of these string values in a json file
  if (!font->loadFromFile("./assets/fonts/MainFont.otf")) {
    std::cerr << "Failed to load font" << std::endl;
    exit(1);
  }

  return font;
}

FontFactory &FontFactory::get_instance() {
  static FontFactory instance;
  return instance;
}
