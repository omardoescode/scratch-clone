#include "Widgets/SectionsWidget.hpp"
#include "DTOs/Sections.hpp"
#include "Game.hpp"
#include "Utils/Button.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/Padding.hpp"
#include "Utils/RectangularBorder.hpp"
#include "Utils/TextBuilder.hpp"
#include "Utils/WidgetList.hpp"
#include "Utils/WidgetListBuilder.hpp"
#include <memory>

SectionsWidget::SectionsWidget(sf::Color background,
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
  TextBuilder builder;

  WidgetList btns = WidgetListBuilder::build(sections.size(), [&](int index) {
    auto &[type, color] = sections[index];
    auto &[r, g, b] = color;
    auto text = builder.setText(DTO::sectiontype_name_mapper(type))
                    .setColor(sf::Color::White)
                    .setFont(FontFactory::get_instance().get_primary_font())
                    .setSize(14)
                    .build();

    auto btn =
        std::make_unique<Button>(std::make_unique<Text>(std::move(text)), 80);

    // clang -Wc++20-extensions
    btn->set_handler([type, handler]() { handler(type); });

    return std::make_unique<RectangularBorder>(
        std::make_unique<Padding>(std::move(btn), EdgeInsets(8.f, 6.f)),
        sf::Color(r, g, b), EdgeInsets(EdgeInsets::LEFT, 3));
  });

  _grid = std::make_unique<GridView>(std::move(btns), 2, 120, 50);
}

sf::FloatRect SectionsWidget::get_global_bounds() const { return {0, 0, 0, 0}; }

void SectionsWidget::set_position(float x, float y) {
  Widget::set_position(x, y);
  assert(_grid);
  _grid->set_position(x, y);
}

// sf::Color SectionsWidget::get_background_color() { return _bg_color; }
