#pragma once

#include "Data/UpdateData.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "Utils/Container.hpp"
#include "Utils/EdgeInsets.hpp"
#include <memory>

class Padding : public Container {
public:
  Padding(std::shared_ptr<Widget> widget, EdgeInsets offsets);

  void render(RenderData) override;
  void update(UpdateData) override;
  void handle_events(EventData) override;
  sf::FloatRect get_global_bounds() const override;
  void set_position(float x, float y) override;

private:
  sf::RectangleShape _paddings;
  EdgeInsets _offsets;
};
