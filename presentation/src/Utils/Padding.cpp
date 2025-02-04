#include "Utils/Padding.hpp"
#include "Data/RenderData.hpp"
#include "Data/UpdateData.hpp"
#include "SFML/System/Vector2.hpp"
#include "Utils/Container.hpp"

// TODO: Figure out what to do with all of this
Padding::Padding(std::shared_ptr<Widget> widget, EdgeInsets offsets)
    : Container(widget), _offsets(offsets) {}

void Padding::render(RenderData ren) {
  ren.window.draw(_paddings);
  Container::render(ren);
}

void Padding::handle_events(EventData ren) {
  bool padding_clicked = _paddings.getGlobalBounds().contains(
      ren.mouse_position.x, ren.mouse_position.y);
  bool widget_clicked = Container::get_global_bounds().contains(
      ren.mouse_position.x, ren.mouse_position.y);

  if (ren.event.type == sf::Event::MouseButtonPressed && padding_clicked &&
      !widget_clicked) {
    Container::handle_click();
    std::cout << "padding clicked" << std::endl;
  } else {
    // TODO: Should I use a flag to check if has been clickd to prevent multiple
    // clicks or just use an else statement here?
    Container::handle_events(ren);
  }
}

sf::FloatRect Padding::get_global_bounds() const {
  auto bounds = Container::get_global_bounds();
  bounds.width += _offsets.left() + _offsets.right();
  bounds.height += _offsets.top() + _offsets.bottom();
  return {__pos.x, __pos.y, bounds.width, bounds.height};
}

void Padding::set_position(float x, float y) {
  _paddings.setPosition(x, y);
  Container::set_position(x + _offsets.left(), y + _offsets.top());
  Widget::set_position(x, y);
}

void Padding::update(UpdateData upd) {
  Container::update(upd);

  auto bounds = get_global_bounds();
  _paddings.setSize(sf::Vector2f(bounds.width, bounds.height));
  _paddings.setFillColor(Container::get_background_color());
}
