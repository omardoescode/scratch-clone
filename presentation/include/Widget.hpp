#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
class Widget {
public:
  /*
   * @brief Render the widget in the given window
   *
   * @param window The window to render to
   */
  virtual void render(sf::RenderWindow *window) = 0;

  /*
   * @brief Handle Events for the widget
   *
   * @param window the render target
   * @param event The event to check against
   */
  virtual void handle_events(const sf::RenderWindow *window,
                             const sf::Event &event) = 0;
};
