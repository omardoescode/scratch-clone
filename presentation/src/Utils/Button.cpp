
#include "Utils/Button.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

// TODO: Integrate Button Borders in here
Button::Button(Text str, sf::Color color, float paddingX, float paddingY,
               sf::Vector2f pos)
    : _text{str} {
  // Get text bounds
  sf::FloatRect textBounds = _text.get_global_bounds();

  // Calculate the box size based on the text's bounds and padding
  sf::RectangleShape box;

  box.setSize(sf::Vector2f(textBounds.width + 2 * paddingX,
                           textBounds.height + 2 * paddingY));

  box.setPosition(pos.x, pos.y);
  box.setFillColor(color);

  _text.set_position(pos.x + paddingX - textBounds.left,
                     pos.y + paddingY - textBounds.top);

  _rect = std::make_unique<sf::RectangleShape>(std::move(box));
}

bool Button::is_hovered(sf::Vector2i point) {
  return _rect->getGlobalBounds().contains(point.x, point.y);
}

void Button::set_handler(std::function<void(void)> func) { _handler = func; }

void Button::render(RenderData ren) {
  ren.window.draw(*_rect);
  _text.render(ren);
}

void Button::handle_events(EventData evt) {}
void Button::update(UpdateData dat) {}

sf::FloatRect Button::get_global_bounds() const {
  return _rect->getGlobalBounds();
}
