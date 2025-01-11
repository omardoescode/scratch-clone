#include "Widgets/SectionsWidget.hpp"
#include "DTOs/Sections.hpp"
#include "Game.hpp"
#include "Utils/Button.hpp"
#include "Utils/ButtonConfig.hpp"
#include "Utils/EdgeInsets.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/Padding.hpp"
#include "Utils/RectangularBorder.hpp"
#include "Utils/TextBuilder.hpp"
#include <memory>

SectionsWidget::SectionsWidget(unsigned width, unsigned height,
                               sf::Color background,
                               std::function<void(DTO::SectionType)> handler) {
  // sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(width, height));
  // rect.setFillColor(sf::Color(_bg_color));
  // _box = std::make_unique<sf::RectangleShape>(std::move(rect));
  //
  init_sections(handler);
}

void SectionsWidget::render(RenderData ren) {
  assert(_grid);
  _grid->render(ren);
}

void SectionsWidget::handle_events(EventData evt) {
  assert(_grid);
  _grid->handle_events(evt);
}

void SectionsWidget::update(UpdateData upd) {
  assert(_grid);
  _grid->update(upd);
}

void SectionsWidget::init_sections(
    std::function<void(DTO::SectionType)> handler) {
  auto sections = Game::get_instance().get_sections();
  std::list<std::unique_ptr<Widget>> btns;
  TextBuilder builder;

  for (auto &[type, color] : sections) {
    auto &[r, g, b] = color;
    auto text = builder.setText(DTO::sectiontype_name_mapper(type))
                    .setColor(sf::Color::White)
                    .setFont(FontFactory::get_instance().get_primary_font())
                    .setSize(14)
                    .build();

    ButtonConfig config = {.widget = std::make_unique<Text>(std::move(text)),
                           .width = 80};

    auto btn = std::make_unique<Button>(std::move(config));

    btn->set_handler([type, handler]() { handler(type); });

    btns.push_back(std::make_unique<RectangularBorder>(
        std::make_unique<Padding>(std::move(btn), EdgeInsets(8.f, 6.f)),
        sf::Color(r, g, b), EdgeInsets(EdgeInsets::LEFT, 3)));
  }

  _grid = std::make_unique<GridView>(std::move(btns), 2, 120, 50);
}

sf::FloatRect SectionsWidget::get_global_bounds() const { return {0, 0, 0, 0}; }

void SectionsWidget::set_position(float x, float y) {
  Widget::set_position(x, y);
  assert(_grid);
  _grid->set_position(x, y);
}

// sf::Color SectionsWidget::get_background_color() { return _bg_color; }
