#include "Utils/RectangularBorder.hpp"
#include "iostream"
#include <memory>

RectangularBorder::RectangularBorder(std::unique_ptr<Widget> widget,
                                     int thickness, sf::Color color,
                                     int direction)
    : Container(std::move(widget)) {
  bool has_top = direction & TOP, has_bottom = direction & BOTTOM,
       has_left = direction & LEFT, has_right = direction & RIGHT;

  auto [x, y, width, height] = get_global_bounds();

  if (has_top) {
    sf::RectangleShape border;
    border.setSize({width + has_left * thickness + has_right * thickness,
                    static_cast<float>(thickness)});
    border.setPosition(x - has_left * thickness, y - has_top * thickness);
    border.setFillColor(color);
    _borders.push_back(border);
    std::cout << "Adding top" << std::endl;
  }

  if (has_bottom) {
    sf::RectangleShape border;
    border.setSize({width + has_left * thickness + has_right * thickness,
                    static_cast<float>(thickness)});
    border.setPosition(x - has_left * thickness, y + height);
    border.setFillColor(color);
    _borders.push_back(border);
    std::cout << "Adding bottom" << std::endl;
  }

  if (has_left) {
    sf::RectangleShape border;
    border.setSize({static_cast<float>(thickness),
                    height + has_top * thickness + has_bottom * thickness});
    border.setPosition(x - thickness, y - has_top * thickness);
    border.setFillColor(color);
    _borders.push_back(border);
    std::cout << border.getSize().x << " " << border.getSize().y << std::endl;
  }

  if (has_right) {
    sf::RectangleShape border;
    border.setSize({static_cast<float>(thickness),
                    height + has_top * thickness + has_bottom * thickness});
    border.setPosition(x + width, y - thickness);
    border.setFillColor(color);
    _borders.push_back(border);
    std::cout << "Adding right" << std::endl;
  }
}
