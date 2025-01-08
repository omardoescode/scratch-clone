#pragma once

#include "Utils/Container.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

// TODO: Document This Widget
class RectangularBorder : public Container {
public:
  enum Direction {
    TOP = 1,
    BOTTOM = 2,
    LEFT = 4,
    RIGHT = 8,
    ALL = TOP | BOTTOM | LEFT | RIGHT,
  };

  RectangularBorder(std::unique_ptr<Widget> widget, int thickness,
                    sf::Color color, int direction);

private:
  std::vector<sf::RectangleShape> _borders;
};
