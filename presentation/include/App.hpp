#pragma once
#include "AppWindow.hpp"
#include "SFML/Graphics.hpp"

class App {
private:
  static constexpr double window_width = 1800;
  static constexpr double window_height = 1012.5;

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
  void handle_events();

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
  AppWindow app_window;
};
