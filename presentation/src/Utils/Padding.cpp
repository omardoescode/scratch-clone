#include "Utils/Padding.hpp"
#include "Data/RenderData.hpp"
#include "SFML/System/Vector2.hpp"
#include "Utils/Container.hpp"

// TODO: Figure out what to do with all of this
Padding::Padding(std::shared_ptr<Widget> widget, EdgeInsets offsets)
    : Container(widget), _offsets(offsets) {

  auto bounds = get_global_bounds();
  _paddings.setSize(sf::Vector2f(bounds.width, bounds.height));
  _paddings.setFillColor(Container::get_background_color());
}

void Padding::render(RenderData ren) {
  ren.window.draw(_paddings);
  Container::render(ren);
}

void Padding::handle_events(EventData ren) {
  if (ren.event.type == sf::Event::MouseButtonPressed &&
      _paddings.getGlobalBounds().contains(ren.mouse_position.x,
                                           ren.mouse_position.y) &&
      !Container::get_global_bounds().contains(ren.mouse_position.x,
                                               ren.mouse_position.y))
    Container::handle_click();
  else {
    // TODO: Should I use a flag to check if has been clickd to prevent multiple
    // clicks or just use an else statement here?
    Container::handle_events(ren);
  }
}

sf::FloatRect Padding::get_global_bounds() const {
  auto bounds = Container::get_global_bounds();
  bounds.left -= _offsets.left();
  bounds.top -= _offsets.top();
  bounds.width += _offsets.left() + _offsets.right();
  bounds.height += _offsets.top() + _offsets.bottom();
  return bounds;
}

void Padding::set_position(float x, float y) {
  Widget::set_position(x, y);
  _paddings.setPosition(x, y);
  Container::set_position(x + _offsets.left(), y + _offsets.top());
}
