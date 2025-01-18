#include "AppWindow.hpp"
#include "DTOs/Sections.hpp"
#include "Widgets/InstructionSetView.hpp"
#include "Widgets/SectionsWidget.hpp"
#include <memory>

AppWindow::AppWindow() : _current_section(static_cast<DTO::SectionType>(0)) {
  _sections_widget = std::make_unique<SectionsWidget>(
      sf::Color(216, 203, 219),
      [this](DTO::SectionType type) { set_current_section(type); });
  _sections_widget->set_position(0, 0);

  _instruction_set = std::make_unique<InstructionSetView>();
  _instruction_set->set_position(500, 500);
}
void AppWindow::handle_events(EventData evt) {
  _sections_widget->handle_events(evt);
  _instruction_set->handle_events(evt);
}

void AppWindow::render(RenderData ren) {
  _sections_widget->render(ren);
  _instruction_set->render(ren);
}

void AppWindow::update(UpdateData upd) {
  _sections_widget->update(upd);
  _instruction_set->update(upd);
}
void AppWindow::set_current_section(DTO::SectionType type) {
  _current_section = type;
}
