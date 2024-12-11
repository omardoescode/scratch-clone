#include "Widgets/SectionsWidget.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "Utils/Button.hpp"
#include "Utils/TextBuilder.hpp"
#include <cmath>
#include <iostream>
#include <memory>

SectionsWidget::SectionsWidget() {
  sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
  rect.setFillColor(sf::Color(0x111111));
  box = std::make_unique<sf::RectangleShape>(std::move(rect));

  init_sections();

  TextBuilder builder;
}

void SectionsWidget::render(sf::RenderWindow *window) {
  window->draw(*box);
  for (auto &sec : sections_buttons) {
    window->draw(*sec);
  }
}
void SectionsWidget::handle_events(const sf::RenderWindow *window,
                                   const sf::Event &event) {
  // TODO: Fix the bug of not detecting the clicks
  if (event.type == event.MouseButtonPressed &&
      event.mouseButton.button == sf::Mouse::Left) {

    auto worldPos = window->mapPixelToCoords(sf::Mouse::getPosition());
    std::cout << "checking a click on " << worldPos.x << " " << worldPos.y
              << std::endl;

    for (auto &sec : sections_buttons) {
      if (sec->is_hovered(worldPos)) {
        std::cout << "mouse positions " << sf::Mouse::getPosition().x << " "
                  << sf::Mouse::getPosition().y << std::endl;
      }
    }
  }
}

void SectionsWidget::init_sections() {
  sections = {"Motion", "Control", "Sensing",
              "Sections"}; // TODO: Fix this initialization
  TextBuilder builder;

  float x = 10.f, y = 10.f;
  float xOffset = 120.f;
  float yOffset = 50.f;
  int columns = 0;

  for (auto &sec : sections) {
    auto text =
        builder.setSize(15).setText(sec).setColor(sf::Color::White).build();
    sections_buttons.push_back(std::make_unique<Button>(
        std::move(text), sf::Color(10, 10, 10), 20, 10, sf::Vector2f{x, y}));
    sections_buttons.back()->set_handler(
        [sec]() { std::cout << sec << std::endl; });

    columns++;
    if (columns == std::ceil(sections.size() / 2.f)) {
      columns = 0;  // Reset to the first column
      x = 10.f;     // Reset to initial x position
      y += yOffset; // Move down to the next row
    } else {
      x += xOffset; // Move to the next column
    }
  }
}
