#include "Utils/Button.hpp"
#include "Utils/WithBackground.hpp"
#include <memory>
#include <stdexcept>

Button::Button(std::shared_ptr<Widget> widget, float width, float height,
               sf::Color color)
    : WithBackground(widget, color) {}

void Button::set_position(float x, float y) {
  Widget::set_position(x, y);
  WithBackground::set_position(x, y);
}

void Button::set_handler(std::function<void(void)> func) { _handler = func; }

void Button::render(RenderData ren) {
  ren.window.draw(__rect);
  WithBackground::render(ren);
}

void Button::handle_events(EventData evt) {
  if (is_hovered(__rect, evt.mouse_position)) {
    // TODO: Handle change the rect background

    // Handle Clicks
    if (evt.event.type == sf::Event::MouseButtonPressed)
      handle_click();
  }
  WithBackground::handle_events(evt);
}

void Button::update(UpdateData dat) {}

sf::FloatRect Button::get_global_bounds() const {
  return __rect.getGlobalBounds();
}

void Button::handle_click() {
  if (!_handler)
    std::cerr << "Handler has not been setup";
  else
    _handler();
}
