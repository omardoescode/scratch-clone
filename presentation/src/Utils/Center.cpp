#include "Utils/Center.hpp"

Center::Center(std::unique_ptr<Widget> widget, unsigned width, unsigned height)
    : _width(width), _height(height), Container(std::move(widget)) {}

void Center::set_position(float x, float y) {
  Widget::set_position(x, y);
  auto widget_bounds = Container::get_global_bounds();
  Container::set_position(x + (_width - widget_bounds.width) / 2.f,
                          y + (_height - widget_bounds.height) / 2.f);
}

sf::FloatRect Center::get_global_bounds() const {
  return {__pos.x, __pos.y, static_cast<float>(_width),
          static_cast<float>(_height)};
}
