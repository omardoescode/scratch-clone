#include "Widgets/SectionsWidget.hpp"
#include "Game.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "Utils/Button.hpp"
#include "Utils/ButtonConfig.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/TextBuilder.hpp"
#include <memory>

SectionsWidget::SectionsWidget(unsigned width, unsigned height) {
  sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(width, height));
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

void SectionsWidget::update(UpdateData upd) {
  for (auto &btn : sections_buttons)
    btn->update(upd);
}

void SectionsWidget::init_sections() {
  sections = Game::get_instance().get_sections();
  TextBuilder builder;

  float x = 10.f, y = 10.f;
  float xOffset = 120.f;
  float yOffset = 40.f;
  int columns = 0;

  for (auto &[str, color] : sections) {
    auto &[r, g, b] = color;
    auto text = builder.setSize(14)
                    .setText(str)
                    .setColor(sf::Color::White)
                    .setFont(FontFactory::get_instance().get_primary_font())
                    .build();

    ButtonConfig config = {
        .text = text,
        .pos = {x, y},
        .paddingX = 10,
        .paddingY = 8,
        .width = 80,
    };

    auto btn = std::make_shared<Button>(config);

    btn->set_handler([str]() { std::cout << str << std::endl; });

    sections_buttons.push_back(btn);

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

sf::FloatRect SectionsWidget::get_global_bounds() const {
  return box->getGlobalBounds();
}
