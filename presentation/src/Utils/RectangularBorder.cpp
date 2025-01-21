#include "Utils/RectangularBorder.hpp"
#include "Utils/EdgeInsets.hpp"
#include <memory>

RectangularBorder::RectangularBorder(std::shared_ptr<Widget> widget,
                                     sf::Color color, EdgeInsets offsets)
    : Container(std::move(widget)), _offsets(offsets), _color(color) {
  auto [x, y, width, height] = get_global_bounds();

  if (_offsets.top()) {
    sf::RectangleShape border;
    border.setSize({width + _offsets.left() + _offsets.right(),
                    static_cast<float>(_offsets.top())});
    border.setPosition(x, y);
    border.setFillColor(_color);
    _borders[EdgeInsets::TOP] = border;
  }

  if (_offsets.bottom()) {
    sf::RectangleShape border;
    border.setSize({width + _offsets.left() + _offsets.right(),
                    static_cast<float>(_offsets.bottom())});
    border.setPosition(x, y + height);
    border.setFillColor(_color);
    _borders[EdgeInsets::BOTTOM] = border;
  }

  if (_offsets.left()) {
    sf::RectangleShape border;
    border.setSize({static_cast<float>(_offsets.left()),
                    height + _offsets.top() + _offsets.bottom()});
    border.setPosition(x, y);
    border.setFillColor(_color);
    _borders[EdgeInsets::LEFT] = border;
  }

  if (_offsets.right()) {
    sf::RectangleShape border;
    border.setSize({static_cast<float>(_offsets.right()),
                    height + _offsets.top() + _offsets.bottom()});
    border.setPosition(x + width, y);
    border.setFillColor(_color);
    _borders[EdgeInsets::RIGHT] = border;
  }
}

void RectangularBorder::render(RenderData ren) {
  Container::render(ren);
  for (auto [dir, brd] : _borders)
    ren.window.draw(brd);
}

void RectangularBorder::set_position(float x, float y) {
  Widget::set_position(x, y);
  auto bounds = Container::get_global_bounds();

  float left = x;
  float right = x + bounds.width;
  float top = y;
  float bottom = y + bounds.height;

  if (auto itr = _borders.find(EdgeInsets::TOP); itr != _borders.end())
    itr->second.setPosition(left, top);

  if (auto itr = _borders.find(EdgeInsets::BOTTOM); itr != _borders.end())
    itr->second.setPosition(left, bottom);

  if (auto itr = _borders.find(EdgeInsets::LEFT); itr != _borders.end())
    itr->second.setPosition(left, top);

  if (auto itr = _borders.find(EdgeInsets::RIGHT); itr != _borders.end())
    itr->second.setPosition(right, top);

  Container::set_position(x + _offsets.left(), y + _offsets.top());
}

void RectangularBorder::set_thickness(EdgeInsets thickness) {
  _offsets = thickness;
}

sf::FloatRect RectangularBorder::get_global_bounds() const {
  auto bounds = Container::get_global_bounds();
  bounds.width += _offsets.left() + _offsets.right();
  bounds.height += _offsets.top() + _offsets.bottom();
  return bounds;
}

sf::Color RectangularBorder::get_color() const { return _color; }

void RectangularBorder::set_color(sf::Color color) {
  _color = color;
  for (auto &[dir, brd] : _borders)
    brd.setFillColor(color);
}
