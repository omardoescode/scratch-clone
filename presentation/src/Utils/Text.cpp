#include "Utils/Text.hpp"
#include "Data/UpdateData.hpp"
#include <memory>

Text::Text()
    : _text(std::make_shared<sf::Text>()), _font(std::make_shared<sf::Font>()) {
}

Text::Text(std::shared_ptr<sf::Text> text, std::shared_ptr<sf::Font> font)
    : _text(text), _font(font) {
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

sf::FloatRect Text::get_global_bounds() const {
  return _text->getGlobalBounds();
}

void Text::set_text(std::unique_ptr<sf::Text> text) {
  assert(text);
  _text = std::move(text);
}
void Text::set_font(std::unique_ptr<sf::Font> font) {
  assert(_text);
  assert(font);
  _font = std::move(font);
  _text->setFont(*_font);
}

void Text::set_character_size(unsigned size) {
  assert(_text != nullptr);
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

void Text::set_position(float x, float y) {
  Widget::set_position(x, y);
  _text->setPosition(x, y);
}
void Text::set_position(const sf::Vector2f &pos) { _text->setPosition(pos); }

std::string Text::get_string() const { return _text->getString(); }
