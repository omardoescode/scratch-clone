#pragma once

#include "SFML/Graphics/Color.hpp"
#include "Utils/Text.hpp"
struct ButtonConfig {
  Text text;
  sf::Color color = sf::Color::Black;
  sf::Vector2f pos = {0, 0};
  float paddingX = 0;
  float paddingY = 0;
  float width = -1;
  float height = -1;
};
