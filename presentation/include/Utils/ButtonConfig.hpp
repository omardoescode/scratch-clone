#pragma once

#include "SFML/Graphics/Color.hpp"
#include "Utils/Text.hpp"
#include <memory>
struct ButtonConfig {
  std::unique_ptr<Widget> widget;
  sf::Color color = sf::Color::Black;
  float width = -1;
  float height = -1;
};
