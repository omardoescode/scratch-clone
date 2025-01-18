#pragma once

#include "Utils/Container.hpp"
#include <memory>
class WithBackground : public Container {
public:
  WithBackground(std::unique_ptr<Widget> widget, sf::Color color);

  void render(RenderData) override;
  void set_position(float x, float y) override;
  sf::Color get_background_color() override;

protected:
  sf::RectangleShape __rect;

private:
  sf::Color _bg_color;
};
