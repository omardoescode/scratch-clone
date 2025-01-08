#include "Utils/FontFactory.hpp"

std::unique_ptr<sf::Font> FontFactory::get_primary_font() {
  std::unique_ptr<sf::Font> font;
  font->loadFromFile("./assets/MainFont.ttf"); // TODO: Set all of these string
                                               // values in a json file
  return font;
}
