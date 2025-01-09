#pragma once

#include "SFML/Graphics/Rect.hpp"
#include "Utils/Container.hpp"

/**
 * @brief Center the child in the given space
 */

class Center : public Container {
public:
  Center(std::unique_ptr<Widget> widget, unsigned width, unsigned height);

  void set_position(float x, float y) override;
  sf::FloatRect get_global_bounds() const override;

private:
  unsigned _width;
  unsigned _height;
};
