#include "Views/SectionInstructionSetView.hpp"

#include "Commands/CommandSet.hpp"
#include "Utils/WidgetList.hpp"
#include "Utils/WidgetListBuilder.hpp"
#include "Views/CommandView.hpp"
#include "Views/SectionInstructionSetView.hpp"
#include <memory>

SectionInstructionSetView::SectionInstructionSetView(DTO::SectionType section) {
  // Fetch Instructions
  auto instructions = CommandSet::get_instance().get_section_commands(section);

  // Create a command view for each
  WidgetList lst =
      WidgetListBuilder::build(instructions.size(), [&](int index) {
        return std::make_shared<CommandView>(instructions[index]);
      });
  _commands = std::make_shared<Column>(lst, 10);
}

void SectionInstructionSetView::render(RenderData ren) {
  _commands->render(ren);
}
void SectionInstructionSetView::handle_events(EventData evt) {
  _commands->handle_events(evt);
}
void SectionInstructionSetView::update(UpdateData upd) {
  _commands->update(upd);
}
sf::FloatRect SectionInstructionSetView::get_global_bounds() const {
  return _commands->get_global_bounds();
}
void SectionInstructionSetView::set_position(float x, float y) {
  // TODO: FIX THIS to add a constant offset
  Widget::set_position(x, y);
  _commands->set_position(x, y);
}
