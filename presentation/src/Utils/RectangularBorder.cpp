#include "Utils/RectangularBorder.hpp"
#include "iostream"
#include <memory>

RectangularBorder::RectangularBorder(std::unique_ptr<Widget> widget,
                                     sf::Color color, EdgeInsets offsets)
    : Container(std::move(widget)), _offsets(offsets) {
  auto [x, y, width, height] = get_global_bounds();

  if (_offsets.top()) {
    sf::RectangleShape border;
    border.setSize({width + _offsets.left() + _offsets.right(),
                    static_cast<float>(_offsets.top())});
    border.setPosition(x - _offsets.left(), y - _offsets.top());
    border.setFillColor(color);
    _borders.push_back(border);
  }

  if (_offsets.bottom()) {
    sf::RectangleShape border;
    border.setSize({width + _offsets.left() + _offsets.right(),
                    static_cast<float>(_offsets.bottom())});
    border.setPosition(x - _offsets.left(), y + height);
    border.setFillColor(color);
    _borders.push_back(border);
  }

  if (_offsets.left()) {
    sf::RectangleShape border;
    border.setSize({static_cast<float>(_offsets.left()),
                    height + _offsets.top() + _offsets.bottom()});
    border.setPosition(x - _offsets.left(), y - _offsets.top());
    border.setFillColor(color);
    _borders.push_back(border);
  }

  if (_offsets.right()) {
    sf::RectangleShape border;
    border.setSize({static_cast<float>(_offsets.bottom()),
                    height + _offsets.top() + _offsets.bottom()});
    border.setPosition(x + width, y - _offsets.top());
    border.setFillColor(color);
    _borders.push_back(border);
  }
}

void RectangularBorder::render(RenderData ren) {
  Container::render(ren);
  for (auto brd : _borders)
    ren.window.draw(brd);
}

// TODO: Use unordered map to map borders to direction instead of using a
// counter that uses the same order as the constructor
void RectangularBorder::set_position(float x, float y) {
  Widget::set_position(x, y);
  int i = 0;
  auto bounds = get_global_bounds();
  if (_offsets.top())
    _borders[i++].setPosition(x, y);

  if (_offsets.bottom())
    _borders[i++].setPosition(x, y + bounds.height);

  if (_offsets.left())
    _borders[i++].setPosition(x, y);

  if (_offsets.right()) {
    _borders[i++].setPosition(x + bounds.width, y);
  }

  Container::set_position(x + _offsets.left(), y + _offsets.right());
}
