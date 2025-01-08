#include "Utils/Text.hpp"
#include "Data/UpdateData.hpp"
#include <memory>

Text::Text()
    : _text(std::make_unique<sf::Text>()), _font(std::make_unique<sf::Font>()) {
}

Text::Text(std::unique_ptr<sf::Text> text, std::unique_ptr<sf::Font> font)
    : _text(std::move(text)), _font(std::move(font)) {
  assert(_text);
  assert(_font);

  // Initialize the font
  _text->setFont(*_font);
}

void Text::render(RenderData ren) {
  assert(_text);
  ren.window.draw(*_text);
}

void Text::handle_events(EventData) {}
void Text::update(UpdateData) {}

void Text::set_text(std::unique_ptr<sf::Text> text) { _text = std::move(text); }
void Text::set_font(std::unique_ptr<sf::Font> font) { _font = std::move(font); }

void Text::set_character_size(unsigned size) {
  assert(_text);
  _text->setCharacterSize(size);
}

void Text::set_fill_color(sf::Color color) {
  assert(_text);
  _text->setFillColor(color);
}

void Text::set_string(const std::string &value) { _text->setString(value); }

void Text::set_string(std::string &&value) {
  _text->setString(std::move(value));
}
