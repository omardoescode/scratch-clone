#pragma once

#include "SFML/Graphics/Rect.hpp"
#include "Utils/Text.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>
#include <memory>

// TODO: Document This Class
class Button : public Widget {
public:
  Button(Text text, sf::Color color = sf::Color::Black, float paddingX = 0,
         float paddingY = 0, sf::Vector2f pos = {0, 0});

public:
  /*
   * @brief Detect Button Hover over the rectangle
   */
  bool is_hovered(sf::Vector2i point);

  /*
   * @brief Set a handle that runs when the button is clicked
   */
  void set_handler(std::function<void(void)> func);

  /**
   * @brief Render the button
   */
  void render(RenderData) override;

  /**
   * @brief Handle the button click
   *
   * @details Run the handler when clicked
   */
  void handle_events(EventData) override;

  /**
   * @brief Update The button when hovered
   */
  void update(UpdateData) override;

  /**
   * @brief Return the global bounds of the button
   *
   * TODO: Consider the case of rectangles
   */
  sf::FloatRect get_global_bounds() const override;

private:
  Text _text;
  std::unique_ptr<sf::RectangleShape> _rect;
  std::function<void(void)> _handler;
};
