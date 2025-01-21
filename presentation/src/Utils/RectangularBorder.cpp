#include "Utils/RectangularBorder.hpp"
#include "Utils/EdgeInsets.hpp"
#include <memory>

RectangularBorder::RectangularBorder(std::shared_ptr<Widget> widget,
                                     sf::Color color, EdgeInsets offsets)
    : Container(std::move(widget)), _offsets(offsets) {
  auto [x, y, width, height] = get_global_bounds();

  if (_offsets.top()) {
    sf::RectangleShape border;
    border.setSize({width + _offsets.left() + _offsets.right(),
                    static_cast<float>(_offsets.top())});
    border.setPosition(x - _offsets.left(), y - _offsets.top());
    border.setFillColor(color);
    _borders[EdgeInsets::TOP] = border;
  }

  if (_offsets.bottom()) {
    sf::RectangleShape border;
    border.setSize({width + _offsets.left() + _offsets.right(),
                    static_cast<float>(_offsets.bottom())});
    border.setPosition(x - _offsets.left(), y + height);
    border.setFillColor(color);
    _borders[EdgeInsets::BOTTOM] = border;
  }

  if (_offsets.left()) {
    sf::RectangleShape border;
    border.setSize({static_cast<float>(_offsets.left()),
                    height + _offsets.top() + _offsets.bottom()});
    border.setPosition(x - _offsets.left(), y - _offsets.top());
    border.setFillColor(color);
    _borders[EdgeInsets::LEFT] = border;
  }

  if (_offsets.right()) {
    sf::RectangleShape border;
    border.setSize({static_cast<float>(_offsets.bottom()),
                    height + _offsets.top() + _offsets.bottom()});
    border.setPosition(x + width, y - _offsets.top());
    border.setFillColor(color);
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
  int i = 0;
  auto bounds = get_global_bounds();
  std::map<EdgeInsets::Direction, sf::RectangleShape>::iterator itr;

  if ((itr = _borders.find(EdgeInsets::TOP)) != _borders.end())
    _borders[EdgeInsets::TOP].setPosition(x, y);

  if ((itr = _borders.find(EdgeInsets::BOTTOM)) != _borders.end())
    _borders[EdgeInsets::BOTTOM].setPosition(x, y + bounds.height);

  if ((itr = _borders.find(EdgeInsets::LEFT)) != _borders.end())
    _borders[EdgeInsets::LEFT].setPosition(x, y);

  if ((itr = _borders.find(EdgeInsets::RIGHT)) != _borders.end())
    _borders[EdgeInsets::RIGHT].setPosition(x + bounds.width, y);

  Container::set_position(x + _offsets.left(), y + _offsets.right());
}
