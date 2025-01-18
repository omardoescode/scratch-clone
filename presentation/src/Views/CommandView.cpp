#include "Views/CommandView.hpp"
#include "Commands/CommandPart.hpp"
#include "Utils/Button.hpp"
#include "Utils/EdgeInsets.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/Padding.hpp"
#include "Utils/Row.hpp"
#include "Utils/TextBuilder.hpp"
#include "Utils/WidgetListBuilder.hpp"
#include <memory>

CommandView::CommandView(std::shared_ptr<Command> cmd) {
  TextBuilder builder;
  auto parts = cmd->get_parts();
  WidgetList lst = WidgetListBuilder::build(parts.size(), [&](int index) {
    auto part = parts[index];
    return std::make_unique<Text>(
        builder.setText(part.part_name)
            .setColor(sf::Color::Red)
            .setFont(FontFactory::get_instance().get_primary_font())
            .setSize(20)
            .build());
  });

  _widget =
      std::make_unique<Button>(std::make_unique<Row>(Row(std::move(lst))));
}
void CommandView::render(RenderData ren) { _widget->render(ren); }

void CommandView::handle_events(EventData evt) { _widget->handle_events(evt); }
void CommandView::update(UpdateData dat) { _widget->update(dat); }
sf::FloatRect CommandView::get_global_bounds() const {
  return _widget->get_global_bounds();
}
void CommandView::set_position(float x, float y) {
  _widget->set_position(x, y);
}
void CommandView::handle_click() {}
