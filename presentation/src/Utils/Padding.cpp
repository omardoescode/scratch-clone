#include "Utils/Padding.hpp"
#include "Data/RenderData.hpp"
#include "SFML/System/Vector2.hpp"
#include "Utils/Container.hpp"

// TODO: Figure out what to do with all of this
Padding::Padding(std::unique_ptr<Widget> widget, float padding_x,
                 float padding_y)
    : Container(std::move(widget)), _padding_x(padding_x),
      _padding_y(padding_y) {
  auto bounds = get_global_bounds();
  paddings.setSize(sf::Vector2f(bounds.width, bounds.height));
  paddings.setFillColor(
      sf::Color::Black); // TODO: Figure out how to handle this
}

void Padding::render(RenderData ren) {
  ren.window.draw(paddings);
  Container::render(ren);
}
void Padding::handle_events(EventData ren) {
  if (ren.event.type == sf::Event::MouseButtonPressed &&
      paddings.getGlobalBounds().contains(ren.mouse_position.x,
                                          ren.mouse_position.y))
    handle_click();
  else {
    // TODO: Should I use a flag to check if has been clickd to prevent multiple
    // clicks or just use an else statement here
    Container::handle_events(ren);
  }
}

sf::FloatRect Padding::get_global_bounds() const {
  auto bounds = Container::get_global_bounds();
  bounds.left -= _padding_x;
  bounds.top -= _padding_y;
  bounds.width += 2 * _padding_x;
  bounds.height += 2 * _padding_y;
  return bounds;
}

void Padding::set_position(float x, float y) {
  paddings.setPosition(x, y);
  Container::set_position(x + _padding_x, y + _padding_y);
}
