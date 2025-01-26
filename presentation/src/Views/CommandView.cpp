#include "Views/CommandView.hpp"
#include "Commands/CommandPart.hpp"
#include "Utils/Button.hpp"
#include "Utils/EdgeInsets.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/NumericalInput.hpp"
#include "Utils/Padding.hpp"
#include "Utils/Row.hpp"
#include "Utils/TextBuilder.hpp"
#include "Utils/WidgetListBuilder.hpp"
#include <memory>
#include <stdexcept>

CommandView::CommandView(std::shared_ptr<Command> cmd) {
  TextBuilder builder;
  auto parts = cmd->get_parts();
  WidgetList lst = WidgetListBuilder::build(
      parts.size(), [&](int index) -> std::shared_ptr<Widget> {
        auto part = parts[index];
        switch (part.type) {
        case CommandPartType::TEXT:
          return std::make_shared<Text>(
              builder.setText(part.part_name)
                  .setColor(sf::Color::Red)
                  .setFont(FontFactory::get_instance().get_primary_font())
                  .setSize(20)
                  .build());
        case CommandPartType::EXPRESSION:
          switch (cmd->retreive_subexpression_datatype(part.part_name)) {
          case DataType::TEXT:
            throw std::runtime_error(
                "Not supported command view for text expression");
          case DataType::NUMBER:
            return std::make_shared<NumericalInput>(sf::Color::Black,
                                                    sf::Color::White, 10);
          case DataType::BOOLEAN:
            throw std::runtime_error(
                "Not supported command view for boolean expression");
          }
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
void CommandView::update(UpdateData dat) {
  _widget->set_position(__pos.x, __pos.y);
  _widget->update(dat);
}
sf::FloatRect CommandView::get_global_bounds() const {
  return _widget->get_global_bounds();
}
void CommandView::set_position(float x, float y) {
  Widget::set_position(x, y);
  _widget->set_position(x, y);
}
void CommandView::handle_click() {}
