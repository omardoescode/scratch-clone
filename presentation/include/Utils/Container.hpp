#pragma once

/**
 * @brief A container is a decorator that receives a widget as a parameter and
 * adds styling, or functionality to that widget
 */
#include "Widget.hpp"
#include <memory>
class Container : public Widget {
public:
  Container(std::unique_ptr<Widget> width);

  /*
   * @brief Render the widget in the given window
   *
   * @param ren Current Render Data
   */
  virtual void render(RenderData) override;

  /*
   * @brief Handle Events for the widget
   *
   * @param dat Current Event Data
   */
  virtual void handle_events(EventData) override;

  /**
   * @brief Update the widget
   */
  virtual void update(UpdateData) override;

  /**
   * @brief Get Global Bounds
   */
  virtual sf::FloatRect get_global_bounds() const override;

  /**
   * @brief Setter for position
   */
  virtual void set_position(float x, float y) override;

  /**
   * @brief Click Handler
   */
  virtual void handle_click() override;

  /**
   * @brief Get the widget background color
   */
  virtual sf::Color get_background_color() override;

private:
  std::unique_ptr<Widget> _widget;
};
