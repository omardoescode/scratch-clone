#include "App.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"

App::App() { init_window(); }

void App::init_window() {
  window =
      new sf::RenderWindow(sf::VideoMode(window_width, window_height), "SFML");
}

void App::run() {
  while (window->isOpen()) {
    event_loop();
    update();
    render();
  }
}

void App::event_loop() {
  static sf::Event event;

  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window->close();
    } else {
    }
  }
}

void App::update() {}

void App::render() {
  window->clear();
  // UI Logic Here
  window->display();
}
