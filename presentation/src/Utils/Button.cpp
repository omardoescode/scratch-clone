#include "Utils/Button.hpp"
#include "Utils/Container.hpp"

Button::Button(std::unique_ptr<Widget> widget, float width, float height,
               sf::Color color)
    : Container(std::move(widget)), _bg_color(color) {
  // Get text bounds
  sf::FloatRect widget_bounds = Container::get_global_bounds();

  // Calculate Actual Width & Height
  auto act_width =
      width != -1 ? std::max(width, widget_bounds.width) : widget_bounds.width;
  auto act_height = height != -1 ? std::max(height, widget_bounds.height)
                                 : widget_bounds.height;

  // Calculate the box size based on the text's bounds and padding
  sf::RectangleShape box;
  box.setSize(sf::Vector2f(act_width, act_height));

  box.setFillColor(color);

  _rect = box;
}

void Button::set_position(float x, float y) {
  Widget::set_position(x, y);
  _rect.setPosition(x, y);
  Container::set_position(x, y);
}

bool Button::is_hovered(sf::Vector2i point) {
  return _rect.getGlobalBounds().contains(point.x, point.y);
}

void Button::set_handler(std::function<void(void)> func) { _handler = func; }

void Button::render(RenderData ren) {
  ren.window.draw(_rect);
  Container::render(ren);
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
  return _rect.getGlobalBounds();
}

void Button::handle_click() { _handler(); }
sf::Color Button::get_background_color() { return _bg_color; }
