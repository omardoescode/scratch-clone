#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

class BorderRectangle : public sf::RectangleShape {
public:
  enum Directions {
    TOP = 1,
    BOTTOM = 2,
    LEFT = 4,
    RIGHT = 8,
  };

  BorderRectangle(const sf::RectangleShape &shape, int thickness,
                  sf::Color color, int direction);

private:
  sf::RectangleShape rect;
  std::vector<sf::RectangleShape> borders;

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
