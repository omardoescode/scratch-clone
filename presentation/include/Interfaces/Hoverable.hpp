#pragma once

#include "Widget.hpp"
#include <algorithm>
#include <memory>
class Hoverable {
public:
  /**
   * @brief returns `true` if the shape is hovered
   */
  bool is_hovered(const sf::Shape &shape, sf::Vector2i mouse_position);

  /**
   * @brief returns `true` if the widget is hovered
   */
  bool is_hovered(const Widget &widget, sf::Vector2i mouse_position);
};
