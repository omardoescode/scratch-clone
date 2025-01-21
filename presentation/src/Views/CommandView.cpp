#include "Views/CommandView.hpp"
#include "Commands/CommandPart.hpp"
#include "Utils/Button.hpp"
#include "Utils/EdgeInsets.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/Input.hpp"
#include "Utils/Padding.hpp"
#include "Utils/Row.hpp"
#include "Utils/TextBuilder.hpp"
#include "Utils/WidgetListBuilder.hpp"
#include <algorithm>
#include <memory>
#include <stdexcept>

CommandView::CommandView(std::shared_ptr<Command> cmd) {
  TextBuilder builder;
  auto parts = cmd->get_parts();
  WidgetList lst = WidgetListBuilder::build(
      parts.size(), [&](int index) -> std::unique_ptr<Widget> {
        auto part = parts[index];
        switch (part.type) {
        case CommandPartType::TEXT:
          return std::make_unique<Text>(
              builder.setText(part.part_name)
                  .setColor(sf::Color::Red)
                  .setFont(FontFactory::get_instance().get_primary_font())
                  .setSize(20)
                  .build());
        case CommandPartType::EXPRESSION:
          return std::make_unique<Input>();
        default:
          throw std::runtime_error("Unknown Command part type");
        }
      });

  _widget = std::make_shared<Button>(
      std::make_shared<Padding>(std::make_shared<Row>(Row(std::move(lst))),
                                EdgeInsets(EdgeInsets::ALL, 3)));
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
