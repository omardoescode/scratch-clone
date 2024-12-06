#pragma once
#include "SFML/Graphics.hpp"

class App {
public:
  App();

  /*
   * @brief Orchestrate the entire app loop
   */
  void run();

private:
  /*
   * @brief Initialize the window object
   */
  void init_window();

  /*
   * @brief Detect Events
   * @note Must check for children events
   */
  void event_loop();

  /*
   * @brief Presentation Logic Before rendering
   */
  void update();

  /*
   * @brief Render the entire application
   */
  void render();

private:
  sf::RenderWindow *window;
  static constexpr double window_width = 1800;
  static constexpr double window_height = 1012.5;
};
