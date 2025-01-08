#pragma once

#include "Widget.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

// TODO: Document This Widget
class BorderRectangle : public Widget {
public:
  enum Directions {
    TOP = 1,
    BOTTOM = 2,
    LEFT = 4,
    RIGHT = 8,
  };

  BorderRectangle(std::shared_ptr<Widget> widget, int thickness,
                  sf::Color color, int direction);

  void render(RenderData) override;
  void handle_events(EventData) override;
  void update(UpdateData) override;
  sf::FloatRect get_global_bounds() const override;

private:
  std::shared_ptr<Widget> widget;
  std::vector<sf::RectangleShape> borders;
};
