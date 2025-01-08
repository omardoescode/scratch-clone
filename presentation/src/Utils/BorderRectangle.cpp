#include "Utils/BorderRectangle.hpp"
#include "iostream"
#include <memory>

BorderRectangle::BorderRectangle(std::shared_ptr<Widget> widget, int thickness,
                                 sf::Color color, int direction)
    : widget{widget} {
  // Check directions
  bool has_top = direction & TOP, has_bottom = direction & BOTTOM,
       has_left = direction & LEFT, has_right = direction & RIGHT;

  auto [x, y, width, height] = widget->get_global_bounds();

  if (has_top) {
    sf::RectangleShape topBorder;
    topBorder.setSize({x + 2 * thickness, static_cast<float>(thickness)});
    topBorder.setPosition(x - thickness, y - thickness);
    topBorder.setFillColor(color);
    borders.push_back(topBorder);
    std::cout << "Adding top" << std::endl;
  }

  if (has_bottom) {
    sf::RectangleShape bottomBorder;
    bottomBorder.setSize({x + 2 * thickness, static_cast<float>(thickness)});
    bottomBorder.setPosition(x - thickness, y + height);
    bottomBorder.setFillColor(color);
    borders.push_back(bottomBorder);
    std::cout << "Adding bottom" << std::endl;
  }

  if (has_left) {
    sf::RectangleShape leftBorder;
    leftBorder.setSize({static_cast<float>(thickness), y + 2 * thickness});
    leftBorder.setPosition(x - thickness, y - thickness);
    leftBorder.setFillColor(color);
    borders.push_back(leftBorder);
    std::cout << "Adding left" << std::endl;
  }

  if (has_right) {
    sf::RectangleShape rightBorder;
    rightBorder.setSize({static_cast<float>(thickness), y + 2 * thickness});
    rightBorder.setPosition(x + width, y - thickness);
    rightBorder.setFillColor(color);
    borders.push_back(rightBorder);
    std::cout << "Adding right" << std::endl;
  }
}

void BorderRectangle::render(RenderData ren) {
  widget->render(ren);
  for (auto &brd : borders)
    ren.window.draw(brd);
}
void BorderRectangle::handle_events(EventData) {}
void BorderRectangle::update(UpdateData) {}
sf::FloatRect BorderRectangle::get_global_bounds() const {
  // TODO: Fix This to include width of borders
  return widget->get_global_bounds();
}
