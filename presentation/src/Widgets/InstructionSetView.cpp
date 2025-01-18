#include "Widgets/InstructionSetView.hpp"
#include "DTOs/Sections.hpp"
#include "Views/SectionInstructionSetView.hpp"
#include <memory>

InstructionSetView::InstructionSetView() : _current_section(DTO::MOTION) {}

std::shared_ptr<Widget> InstructionSetView::get_current_instruction_set() {
  auto itr = _sections_instruction_sets.find(_current_section);
  if (itr != _sections_instruction_sets.end())
    return itr->second;
  auto set = std::make_shared<SectionInstructionSetView>(_current_section);
  set->set_position(__pos.x, __pos.y);
  return _sections_instruction_sets[_current_section] = set;
}

std::shared_ptr<Widget>
InstructionSetView::get_current_instruction_set() const {
  auto itr = _sections_instruction_sets.find(_current_section);
  if (itr != _sections_instruction_sets.end())
    return itr->second;
  return nullptr;
}
void InstructionSetView::render(RenderData ren) {
  get_current_instruction_set()->render(ren);
}
void InstructionSetView::handle_events(EventData evt) {
  get_current_instruction_set()->handle_events(evt);
}
void InstructionSetView::update(UpdateData upt) {
  get_current_instruction_set()->update(upt);
}
sf::FloatRect InstructionSetView::get_global_bounds() const {
  return get_current_instruction_set()->get_global_bounds();
}

void InstructionSetView::change_section(DTO::SectionType section) {
  _current_section = section;
}
void InstructionSetView::set_position(float x, float y) {
  Widget::set_position(x, y);
}
