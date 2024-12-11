#include "AppWindow.hpp"

void AppWindow::handle_events(const sf::RenderWindow *window,
                              const sf::Event &event) {
  sections.handle_events(window, event);
}

void AppWindow::render(sf::RenderWindow *window) { sections.render(window); }
