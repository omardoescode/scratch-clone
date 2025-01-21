#include "Utils/WithBackground.hpp"
#include "Data/RenderData.hpp"
#include "Utils/Container.hpp"

WithBackground::WithBackground(std::shared_ptr<Widget> widget, sf::Color color)
    : Container(widget) {
  auto bounds = get_global_bounds();
  __rect.setSize(sf::Vector2f(bounds.width, bounds.height));

  __rect.setFillColor(color);
}

void WithBackground::render(RenderData ren) {
  ren.window.draw(__rect);
  Container::render(ren);
}

void WithBackground::set_position(float x, float y) {
  Container::set_position(x, y);
  __rect.setPosition(x, y);
}

sf::Color WithBackground::get_background_color() { return _bg_color; }
