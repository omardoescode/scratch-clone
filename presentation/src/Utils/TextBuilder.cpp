#include "Utils/TextBuilder.hpp"

const std::string TextBuilder::font_dir = "./assets/fonts/MainFont.ttf";
bool TextBuilder::font_initialized = false;
sf::Font TextBuilder::font;

TextBuilder::TextBuilder() {
  init_font();
  reset();
}

void TextBuilder::init_font() {
  if (font_initialized)
    return;

  if (!font.loadFromFile(font_dir))
    exit(1);

  font_initialized = true;
}

TextBuilder &TextBuilder::setSize(int size) {
  text.setCharacterSize(size);
  return *this;
}
TextBuilder &TextBuilder::setText(const std::string &value) {
  text.setString(value);
  return *this;
}

TextBuilder &TextBuilder::setText(std::string &&value) {
  text.setString(std::move(value));
  return *this;
}

TextBuilder &TextBuilder::setColor(sf::Color color) {
  text.setFillColor(color);
  return *this;
}

sf::Text TextBuilder::build() {
  sf::Text ret = std::move(text);
  reset();
  return ret;
}

void TextBuilder::reset() {
  text.setFillColor(sf::Color::Black);
  text.setCharacterSize(8);
  text.setString("Builder not set yet!!!");
  text.setFont(font);
}
