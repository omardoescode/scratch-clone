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

  void render(RenderData) override;
  void handle_events(EventData) override;
  void update(UpdateData) override;
  sf::FloatRect get_global_bounds() const override;

private:
  std::vector<sf::RectangleShape> _borders;
};
