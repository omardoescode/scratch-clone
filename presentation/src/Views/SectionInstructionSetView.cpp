#include "Views/SectionInstructionSetView.hpp"

#include "Commands/CommandSet.hpp"
#include "Views/SectionInstructionSetView.hpp"

SectionInstructionSetView::SectionInstructionSetView(DTO::SectionType section) {
  // Fetch Instructions
  auto instructions = CommandSet::get_instance().get_section_commands(section);

  // Create a command view for each
  for (const auto &instance : instructions)
    _commands.push_back(std::make_shared<CommandView>(instance));
}

void SectionInstructionSetView::render(RenderData ren) {
  for (auto &cmd : _commands)
    cmd->render(ren);
}
void SectionInstructionSetView::handle_events(EventData evt) {
  for (auto &cmd : _commands)
    cmd->handle_events(evt);
}
void SectionInstructionSetView::update(UpdateData upd) {
  for (auto &cmd : _commands)
    cmd->update(upd);
}
sf::FloatRect SectionInstructionSetView::get_global_bounds() const {
  return {0, 0, 0, 0};
}
void SectionInstructionSetView::set_position(float x, float y) {
  // TODO: FIX THIS to add a constant offset
  for (auto &cmd : _commands)
    cmd->set_position(x, y);
}
