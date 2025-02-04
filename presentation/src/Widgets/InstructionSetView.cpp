#include "Widgets/InstructionSetView.hpp"
#include "DTOs/Sections.hpp"
#include "Utils/Padding.hpp"
#include "Views/SectionInstructionSetView.hpp"
#include <memory>

InstructionSetView::InstructionSetView() {
  for (auto &section : DTO::sections)
    _sections_instruction_sets[section] = std::make_shared<Padding>(
        std::make_shared<SectionInstructionSetView>(section),
        EdgeInsets(EdgeInsets::ALL, 15));
  _current_section_type = static_cast<DTO::SectionType>(0);
}

std::shared_ptr<Widget>
InstructionSetView::get_current_instruction_set() const {
  auto itr = _sections_instruction_sets.find(_current_section_type);
  if (itr == _sections_instruction_sets.end())
    return nullptr;
  return itr->second;
}

void InstructionSetView::render(RenderData ren) {
  auto res = get_current_instruction_set();
  assert(res);
  res->render(ren);
}

void InstructionSetView::handle_events(EventData evt) {
  auto res = get_current_instruction_set();
  assert(res);
  res->handle_events(evt);
}

void InstructionSetView::update(UpdateData upt) {
  auto res = get_current_instruction_set();
  assert(res);
  res->update(upt);
}

sf::FloatRect InstructionSetView::get_global_bounds() const {
  return get_current_instruction_set()->get_global_bounds();
}

void InstructionSetView::change_section(DTO::SectionType section) {
  _current_section_type = section;
}

void InstructionSetView::set_position(float x, float y) {
  Widget::set_position(x, y);

  for (auto &[type, sec] : _sections_instruction_sets)
    sec->set_position(__pos);
}
