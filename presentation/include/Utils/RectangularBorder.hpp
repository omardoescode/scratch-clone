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
                    EdgeInsets thickness);

  void render(RenderData) override;
  void set_position(float x, float y) override;

  /**
   * @brief Change the thickness of the border
   */
  void set_thickness(EdgeInsets new_thickness);

private:
  std::map<EdgeInsets::Direction, sf::RectangleShape> _borders;
  EdgeInsets _offsets;
};
