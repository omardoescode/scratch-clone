#pragma once

#include "Utils/Container.hpp"
#include "Utils/EdgeInsets.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

// TODO: Document This Widget
class RectangularBorder : public Container {
public:
  RectangularBorder(std::shared_ptr<Widget> widget, sf::Color color,
                    EdgeInsets offset);

  void render(RenderData) override;
  void set_position(float x, float y) override;

private:
  std::vector<sf::RectangleShape> _borders;
  EdgeInsets _offsets;
};
