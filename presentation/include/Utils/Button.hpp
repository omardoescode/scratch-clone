#pragma once

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Text.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>
#include <memory>

class Button : public sf::Drawable {
public:
  Button(sf::Text, sf::Color color = sf::Color::Black, float paddingX = 0,
         float paddingY = 0, sf::Vector2f pos = {0, 0});

public:
  /*
   * @brief Detect Button Hover over the rectangle
   */
  bool is_hovered(sf::Vector2f point);

  /*
   * @brief Set a handle that runs when the button is clicked
   */
  void set_handler(std::function<void(void)> func);

  /*
   * @brief Run the handler
   */
  void handle_click();

private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
  sf::Text text;
  std::unique_ptr<sf::RectangleShape> rect;
  std::function<void(void)> handler;
};
