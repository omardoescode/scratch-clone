#pragma once

#include "SFML/Graphics/RectangleShape.hpp"
#include "Utils/Container.hpp"
#include "Utils/EdgeInsets.hpp"
#include <memory>

class Padding : public Container {
public:
  Padding(std::unique_ptr<Widget>, EdgeInsets offsets);

  void render(RenderData) override;
  void handle_events(EventData) override;
  sf::FloatRect get_global_bounds() const override;
  void set_position(float x, float y) override;

private:
  sf::RectangleShape _paddings;
  EdgeInsets _offsets;
};
