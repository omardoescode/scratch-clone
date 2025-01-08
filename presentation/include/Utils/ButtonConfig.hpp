#pragma once

#include "SFML/Graphics/Color.hpp"
#include "Utils/Text.hpp"
struct ButtonConfig {
  Text text;
  sf::Color color = sf::Color::Black;
  float width = -1;
  float height = -1;
};
