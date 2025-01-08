
#include "Utils/Button.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

// TODO: Integrate Button Borders in here
Button::Button(const ButtonConfig &config) : _text{config.text} {
  auto &[text, color, pos, paddingX, paddingY, conf_width, conf_height] =
      config;

  // Get text bounds
  sf::FloatRect textBounds = _text.get_global_bounds();

  // Calculate Width & Height
  auto width = conf_width != -1 ? conf_width : textBounds.width;
  auto height = conf_height != -1 ? conf_height : textBounds.height;

  // Calculate the box size based on the text's bounds and padding
  sf::RectangleShape box;
  box.setSize(sf::Vector2f(width + 2 * paddingX, height + 2 * paddingY));

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

void Button::handle_events(EventData evt) {
  if (is_hovered(evt.mouse_position)) {
    // TODO: Handle change the rect background

    // Handle Clicks
    if (evt.event.type == sf::Event::MouseButtonPressed)
      _handler();
  }
}
void Button::update(UpdateData dat) {}

sf::FloatRect Button::get_global_bounds() const {
  return _rect->getGlobalBounds();
}
