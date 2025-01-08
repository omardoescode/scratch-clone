#pragma once

#include "SFML/Graphics/RectangleShape.hpp"
#include "Utils/Container.hpp"
#include <memory>

class Padding : public Container {
public:
  Padding(std::unique_ptr<Container>, float padding_x = 0, float padding_y = 0);

  void render(RenderData) override;
  void handle_events(EventData) override;
  sf::FloatRect get_global_bounds() const override;
  void set_position(float x, float y) override;

private:
  float _padding_x;
  float _padding_y;
  sf::RectangleShape paddings;
};
