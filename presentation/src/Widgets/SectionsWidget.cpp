#include "Widgets/SectionsWidget.hpp"
#include "Game.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "Utils/Button.hpp"
#include "Utils/ButtonConfig.hpp"
#include "Utils/EdgeInsets.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/Padding.hpp"
#include "Utils/RectangularBorder.hpp"
#include "Utils/TextBuilder.hpp"
#include <memory>

SectionsWidget::SectionsWidget(unsigned width, unsigned height,
                               sf::Color background)
    : _bg_color(background) {
  sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(width, height));
  rect.setFillColor(sf::Color(_bg_color));
  _box = std::make_unique<sf::RectangleShape>(std::move(rect));

  init_sections();

  TextBuilder builder;
}

void SectionsWidget::render(RenderData ren) {
  ren.window.draw(*_box);
  for (auto &btn : _sections_btns)
    btn->render(ren);
}

void SectionsWidget::handle_events(EventData evt) {
  for (auto &btn : _sections_btns)
    btn->handle_events(evt);
}

void SectionsWidget::update(UpdateData upd) {
  for (auto &btn : _sections_btns)
    btn->update(upd);
}

void SectionsWidget::init_sections() {
  _sections = Game::get_instance().get_sections();
  TextBuilder builder;

  for (auto &[str, color] : _sections) {
    auto &[r, g, b] = color;
    auto text = builder.setSize(14)
                    .setText(str)
                    .setColor(sf::Color::White)
                    .setFont(FontFactory::get_instance().get_primary_font())
                    .build();

    ButtonConfig config = {.text = text, .width = 80};

    auto btn = std::make_unique<Button>(config);

    btn->set_handler([str]() { std::cout << str << std::endl; });

    _sections_btns.push_back(std::make_unique<RectangularBorder>(
        std::make_unique<Padding>(std::move(btn),
                                  EdgeInsets(EdgeInsets::ALL, 10)),
        sf::Color(r, g, b), EdgeInsets(EdgeInsets::LEFT, 3)));
  }
}

sf::FloatRect SectionsWidget::get_global_bounds() const {
  return _box->getGlobalBounds();
}

void SectionsWidget::set_position(float _x, float _y) {
  _box->setPosition(_x, _y);
  float x = _x, y = _y;
  float xOffset = 120.f;
  float yOffset = 40.f;
  int columns = 0;

  for (auto &btn : _sections_btns) {
    btn->set_position(x, y);
    columns++;
    if (columns == 2) {
      columns = 0;  // Reset to the first column
      x = _x;       // Reset to initial x position
      y += yOffset; // Move down to the next row
    } else {
      x += xOffset; // Move to the next column
    }
  }
}

sf::Color SectionsWidget::get_background_color() { return _bg_color; }
