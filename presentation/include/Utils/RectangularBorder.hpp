#pragma once

#include "SFML/Graphics/Rect.hpp"
#include "Utils/Container.hpp"
#include "Utils/EdgeInsets.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// TODO: Document This Widget
class RectangularBorder : public Container {
public:
  RectangularBorder(std::shared_ptr<Widget> widget, sf::Color color,
                    EdgeInsets thickness);

  void render(RenderData) override;
  void set_position(float x, float y) override;

  sf::FloatRect get_global_bounds() const override;

  /**
   * @brief Change the thickness of the border
   */
  void set_thickness(EdgeInsets new_thickness);

  /**
   * @brief Get color for borders
   */
  sf::Color get_color() const;

  /**
   * @brief Set Color
   */
  void set_color(sf::Color);

private:
  std::map<EdgeInsets::BaseDirection, sf::RectangleShape> _borders;
  EdgeInsets _offsets;
  sf::Color _color;
};
