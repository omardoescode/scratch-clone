#pragma once

#include "Data/EventData.hpp"
#include "Data/RenderData.hpp"
#include "Data/UpdateData.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

class Widget {
public:
  /*
   * @brief Render the widget in the given window
   *
   * @param ren Current Render Data
   */
  virtual void render(RenderData) = 0;

  /*
   * @brief Handle Events for the widget
   *
   * @param dat Current Event Data
   */
  virtual void handle_events(EventData) = 0;

  /**
   * @brief Update the widget
   */
  virtual void update(UpdateData) = 0;

  /**
   * @brief Get Global Bounds
   */
  virtual sf::FloatRect get_global_bounds() const = 0;
};
