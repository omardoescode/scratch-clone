#include "Utils/TextBuilder.hpp"

TextBuilder &TextBuilder::setSize(int size) {
  _text.set_character_size(size);
  return *this;
}
TextBuilder &TextBuilder::setText(const std::string &value) {
  _text.set_string(value);
  return *this;
}

TextBuilder &TextBuilder::setText(std::string &&value) {
  _text.set_string(std::move(value));
  return *this;
}

TextBuilder &TextBuilder::setColor(sf::Color color) {
  _text.set_fill_color(color);
  return *this;
}

Text TextBuilder::build() {
  Text ret = std::move(_text);
  return ret;
}
