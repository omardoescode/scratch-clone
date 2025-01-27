#include "Widgets/InstructionSetView.hpp"
#include "DTOs/Sections.hpp"
#include "Views/SectionInstructionSetView.hpp"
#include <memory>
#include <stdexcept>

InstructionSetView::InstructionSetView() {
  for (auto &section : DTO::sections)
    _sections_instruction_sets[section] =
        std::make_shared<SectionInstructionSetView>(section);
}

std::shared_ptr<Widget>
InstructionSetView::get_current_instruction_set() const {
  try {
    return _sections_instruction_sets.at(_current_section_type);
  } catch (std::out_of_range &) {
    return nullptr;
  }
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
