#include "Utils/Button.hpp"
#include "Utils/WithBackground.hpp"
#include <memory>

Button::Button(std::unique_ptr<Widget> widget, float width, float height,
               sf::Color color)
    : WithBackground(std::move(widget), color) {}

void Button::set_position(float x, float y) {
  Widget::set_position(x, y);
  WithBackground::set_position(x, y);
}

bool Button::is_hovered(sf::Vector2i point) {
  return __rect.getGlobalBounds().contains(point.x, point.y);
}

void Button::set_handler(std::function<void(void)> func) { _handler = func; }

void Button::render(RenderData ren) {
  ren.window.draw(__rect);
  WithBackground::render(ren);
}

void Button::handle_events(EventData evt) {
  if (is_hovered(evt.mouse_position)) {
    // TODO: Handle change the rect background

    // Handle Clicks
    if (evt.event.type == sf::Event::MouseButtonPressed)
      handle_click();
  }
}
void Button::update(UpdateData dat) {}

sf::FloatRect Button::get_global_bounds() const {
  return __rect.getGlobalBounds();
}

void Button::handle_click() { _handler(); }
