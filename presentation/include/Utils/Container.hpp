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
  virtual void render(RenderData);

  /*
   * @brief Handle Events for the widget
   *
   * @param dat Current Event Data
   */
  virtual void handle_events(EventData);

  /**
   * @brief Update the widget
   */
  virtual void update(UpdateData);

  /**
   * @brief Get Global Bounds
   */
  virtual sf::FloatRect get_global_bounds() const;

private:
  std::unique_ptr<Widget> _widget;
};
