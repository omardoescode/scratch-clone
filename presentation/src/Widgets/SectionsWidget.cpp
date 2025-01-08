#include "Widgets/SectionsWidget.hpp"
#include "Game.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "Utils/Button.hpp"
#include "Utils/FontFactory.hpp"
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

void SectionsWidget::render(RenderData ren) {
  ren.window.draw(*box);
  for (auto &btn : sections_buttons)
    btn->render(ren);
}

void SectionsWidget::handle_events(EventData evt) {
  for (auto &btn : sections_buttons)
    btn->handle_events(evt);
}

void SectionsWidget::init_sections() {
  sections = Game::get_instance().get_sections();
  std::cout << sections.size() << std::endl;
  TextBuilder builder;

  float x = 10.f, y = 10.f;
  float xOffset = 100.f;
  float yOffset = 40.f;
  int columns = 0;

  for (auto &[str, color] : sections) {
    auto &[r, g, b] = color;
    auto text = builder.setSize(13)
                    .setText(str)
                    .setColor(sf::Color::White)
                    .setFont(FontFactory::get_instance().get_primary_font())
                    .build();

    sections_buttons.push_back(std::make_unique<Button>(
        text, sf::Color(r, g, b), 20, 10, sf::Vector2f{x, y}));
    sections_buttons.back()->set_handler(
        [str]() { std::cout << str << std::endl; });

    columns++;
    if (columns == 2) {
      columns = 0;  // Reset to the first column
      x = 10.f;     // Reset to initial x position
      y += yOffset; // Move down to the next row
    } else {
      x += xOffset; // Move to the next column
    }
  }
}

void SectionsWidget::update(UpdateData) {}
sf::FloatRect SectionsWidget::get_global_bounds() const {
  return box->getGlobalBounds();
}
