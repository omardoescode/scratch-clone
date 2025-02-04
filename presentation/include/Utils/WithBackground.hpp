#pragma once

#include "Utils/Container.hpp"
#include <memory>
class WithBackground : public Container {
public:
  WithBackground(std::shared_ptr<Widget> widget, sf::Color color);

  void render(RenderData) override;
  void update(UpdateData) override;
  void set_position(float x, float y) override;
  sf::Color get_background_color() const override;

protected:
  sf::RectangleShape __rect;

private:
  sf::Color _bg_color;
};
