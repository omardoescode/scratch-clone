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
  auto sections = DTO::sections;
  auto sections_map = Game::get_instance().get_sections_map();
  TextBuilder builder;

  WidgetList btns = WidgetListBuilder::build(sections.size(), [&](int index) {
    auto type = sections[index];
    auto data = sections_map[type];
    auto &[r, g, b] = data.color;
    auto text = builder.setText(DTO::sectiontype_name_mapper(type))
                    .setColor(sf::Color::White)
                    .setFont(FontFactory::get_instance().get_primary_font())
                    .setSize(14)
                    .build();

    auto btn =
        std::make_shared<Button>(std::make_unique<Text>(std::move(text)));

    // clang -Wc++20-extensions
    btn->set_handler([type, handler]() { handler(type); });

    return std::make_shared<RectangularBorder>(
        std::make_shared<Padding>(std::move(btn), EdgeInsets(8.f, 6.f)),
        sf::Color(r, g, b), EdgeInsets(EdgeInsets::LEFT, 3));
  });

  _grid = std::make_shared<GridView>(std::move(btns), 2, 20, 10);
}

sf::FloatRect SectionsWidget::get_global_bounds() const {
  return _grid->get_global_bounds();
}

void SectionsWidget::set_position(float x, float y) {
  Widget::set_position(x, y);
  assert(_grid);
  _grid->set_position(x, y);
}
