#include "App.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>

App::App() { init_window(); }

void App::init_window() {
  window =
      new sf::RenderWindow(sf::VideoMode(window_width, window_height), "SFML");
  window->setView(window->getDefaultView());
}

void App::run() {
  while (window->isOpen()) {
    handle_events();
    update();
    render();
  }
}

void App::handle_events() {
  static sf::Event event;

  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window->close();
    } else if (event.type == sf::Event::Resized) {
      // Update window view
      window->setView(
          sf::View(sf::FloatRect(0, 0, static_cast<float>(window->getSize().x),
                                 static_cast<float>(window->getSize().y))));
    } else {
      app_window.handle_events(window, event);
    }
  }
}

void App::update() {}

void App::render() {
  window->clear(sf::Color::White);

  app_window.render(window);

  window->display();
}
