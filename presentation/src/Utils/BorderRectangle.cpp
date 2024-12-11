#include "Utils/BorderRectangle.hpp"
#include "iostream"

BorderRectangle::BorderRectangle(const sf::RectangleShape &shape, int thickness,
                                 sf::Color color, int direction)
    : rect(shape) {
  // Check directions
  bool has_top = direction & TOP, has_bottom = direction & BOTTOM,
       has_left = direction & LEFT, has_right = direction & RIGHT;

  if (has_top) {
    sf::RectangleShape topBorder;
    topBorder.setSize(
        {shape.getSize().x + 2 * thickness, static_cast<float>(thickness)});
    topBorder.setPosition(shape.getPosition().x - thickness,
                          shape.getPosition().y - thickness);
    topBorder.setFillColor(color);
    borders.push_back(topBorder);
    std::cout << "Adding top" << std::endl;
  }

  if (has_bottom) {
    sf::RectangleShape bottomBorder;
    bottomBorder.setSize(
        {shape.getSize().x + 2 * thickness, static_cast<float>(thickness)});
    bottomBorder.setPosition(shape.getPosition().x - thickness,
                             shape.getPosition().y + shape.getSize().y);
    bottomBorder.setFillColor(color);
    borders.push_back(bottomBorder);
    std::cout << "Adding bottom" << std::endl;
  }

  if (has_left) {
    sf::RectangleShape leftBorder;
    leftBorder.setSize(
        {static_cast<float>(thickness), shape.getSize().y + 2 * thickness});
    leftBorder.setPosition(shape.getPosition().x - thickness,
                           shape.getPosition().y - thickness);
    leftBorder.setFillColor(color);
    borders.push_back(leftBorder);
    std::cout << "Adding left" << std::endl;
  }

  if (has_right) {
    sf::RectangleShape rightBorder;
    rightBorder.setSize(
        {static_cast<float>(thickness), shape.getSize().y + 2 * thickness});
    rightBorder.setPosition(shape.getPosition().x + shape.getSize().x,
                            shape.getPosition().y - thickness);
    rightBorder.setFillColor(color);
    borders.push_back(rightBorder);
    std::cout << "Adding right" << std::endl;
  }
}

void BorderRectangle::draw(sf::RenderTarget &target,
                           sf::RenderStates states) const {
  target.draw(rect, states);
  for (const auto &border : borders)
    target.draw(border, states);
}
