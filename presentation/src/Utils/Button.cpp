
#include "Utils/Button.hpp"
#include "SFML/System/Vector2.hpp"
#include "Utils/BorderRectangle.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include <memory>

Button::Button(sf::Text str, sf::Color color, float paddingX, float paddingY,
               sf::Vector2f pos)
    : text{str} {
  // Get text bounds
  sf::FloatRect textBounds = text.getGlobalBounds();

  // Calculate the box size based on the text's bounds and padding
  sf::RectangleShape box;

  box.setSize(sf::Vector2f(textBounds.width + 2 * paddingX,
                           textBounds.height + 2 * paddingY));

  box.setPosition(pos.x, pos.y);
  box.setFillColor(color);

  text.setPosition(pos.x + paddingX - textBounds.left,
                   pos.y + paddingY - textBounds.top);

  rect = std::make_unique<sf::RectangleShape>(std::move(box));
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(*rect, states);
  target.draw(text, states);
}

bool Button::is_hovered(sf::Vector2f point) {
  return rect->getGlobalBounds().contains(point);
}

void Button::set_handler(std::function<void(void)> func) { handler = func; }

void Button::handle_click() { handler(); }
