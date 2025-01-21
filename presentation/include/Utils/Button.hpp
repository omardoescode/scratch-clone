#pragma once

#include "Interfaces/Hoverable.hpp"
#include "Utils/WithBackground.hpp"
#include <functional>

// TODO: Document This Class
class Button : public WithBackground, public Hoverable {
public:
  explicit Button(std::shared_ptr<Widget> widget, float width = -1,
                  float height = -1, sf::Color color = sf::Color::Black);

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

private:
  std::function<void(void)> _handler;
  float _padding_x;
  float _padding_y;
};
