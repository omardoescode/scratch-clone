#include "Interfaces/Hoverable.hpp"

bool Hoverable::is_hovered(const sf::Shape &shape,
                           sf::Vector2i mouse_position) {
  return shape.getGlobalBounds().contains(mouse_position.x, mouse_position.y);
}

bool Hoverable::is_hovered(const Widget &widget, sf::Vector2i mouse_position) {
  return widget.get_global_bounds().contains(mouse_position.x,
                                             mouse_position.y);
}
