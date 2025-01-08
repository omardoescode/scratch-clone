#pragma once

#include "Utils/Text.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

// TODO: Document this class
class TextBuilder {
public:
  TextBuilder &setText(const std::string &);
  TextBuilder &setText(std::string &&);
  TextBuilder &setColor(sf::Color);
  TextBuilder &setFont(std::unique_ptr<sf::Font>);
  TextBuilder &setSize(int);
  Text build();

private:
  Text _text;
};
