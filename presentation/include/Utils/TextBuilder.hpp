#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TextBuilder {
public:
  static const std::string font_dir;

public:
  TextBuilder();

  TextBuilder &setText(const std::string &);
  TextBuilder &setText(std::string &&);
  TextBuilder &setColor(sf::Color);
  TextBuilder &setSize(int);
  sf::Text build();

private:
  void init_font();
  void reset();

private:
  sf::Text text;
  static sf::Font font;
  static bool font_initialized;
};
