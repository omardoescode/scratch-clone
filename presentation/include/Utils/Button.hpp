#pragma once

#include "SFML/Graphics/Rect.hpp"
#include "Utils/ButtonConfig.hpp"
#include "Utils/Container.hpp"
#include "Utils/Text.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>

// TODO: Document This Class
class Button : public Container {
public:
  explicit Button(ButtonConfig);

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
   */
  sf::FloatRect get_global_bounds() const override;

  /**
   * @brief Set the button position
   */
  void set_position(float x, float y) override;

  /**
   * @brief Handle click
   *
   * @details Run the handler
   */
  void handle_click() override;

  /**
   * @brief Return the background color for the button
   */
  sf::Color get_background_color() override;

private:
  sf::RectangleShape _rect;
  std::function<void(void)> _handler;
  float padding_x;
  float padding_y;
  sf::Color _bg_color;
};
