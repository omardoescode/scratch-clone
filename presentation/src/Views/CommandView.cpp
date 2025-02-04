#include "Views/CommandView.hpp"
#include "Commands/CommandPart.hpp"
#include "Game.hpp"
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

// TODO: Refactor the whole thing buddy
CommandView::CommandView(std::shared_ptr<Command> cmd) {
  assert(cmd);
  TextBuilder builder;

  // Get the color
  auto [r, g, b] =
      Game::get_instance().get_sections_map()[cmd->get_section_type()].color;

  auto parts = cmd->get_parts();

  // Build the parts in a row
  WidgetList lst = WidgetListBuilder::build(
      parts.size(), [&](int index) -> std::shared_ptr<Widget> {
        auto part = parts[index];
        switch (part.type) {
        case CommandPartType::TEXT:
          return std::make_shared<Text>(
              builder.setText(part.part_name)
                  .setColor(sf::Color::White)
                  .setFont(FontFactory::get_instance().get_primary_font())
                  .setSize(15)
                  .build());
          // TODO: Change this code to a component that's we can drag
          // expressions to
        case CommandPartType::EXPRESSION:
          switch (cmd->retreive_subexpression_datatype(part.part_name)) {
          case DataType::TEXT:
            throw std::runtime_error(
                "Not supported command view for text expression");
          case DataType::NUMBER: {
            // TODO: Is there a better way to check for a constant value
            if (auto constant = std::dynamic_pointer_cast<Constant>(
                    cmd->retrieve_subexpression(part.part_name))) {
              auto wid = std::make_shared<NumericalInput>(
                  constant, sf::Color::Black, sf::Color::White, 10, 15);
              return std::make_shared<Padding>(wid,
                                               EdgeInsets(EdgeInsets::ALL, 10));
            } else
              throw std::runtime_error(
                  "Not supported command view for sub-expression");
          }
          case DataType::BOOLEAN:
            throw std::runtime_error(
                "Not supported command view for boolean expression");
          }
        default:
          throw std::runtime_error("Unknown Command part type");
        }
      });

  _widget = std::make_shared<Button>(
      std::make_shared<Padding>(std::make_shared<Row>(std::move(lst)),
                                EdgeInsets(EdgeInsets::ALL, 5)),
      sf::Color(r, g, b));
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
