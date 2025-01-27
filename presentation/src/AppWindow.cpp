#include "AppWindow.hpp"
#include "DTOs/Sections.hpp"
#include "Widgets/InstructionSetView.hpp"
#include "Widgets/SectionsWidget.hpp"
#include <memory>

AppWindow::AppWindow() : _current_section(static_cast<DTO::SectionType>(0)) {
  _sections_widget = std::make_shared<SectionsWidget>(
      sf::Color(216, 203, 219),
      [this](DTO::SectionType type) { set_current_section(type); });
  _sections_widget->set_position(0, 0);

  _instruction_set = std::make_shared<InstructionSetView>();
  _instruction_set->set_position(0,
                                 _sections_widget->get_global_bounds().height);
  std::cout << _sections_widget->get_global_bounds().height << std::endl;
  r = std::make_shared<DebugRect>(_instruction_set);
}
void AppWindow::handle_events(EventData evt) {
  _sections_widget->handle_events(evt);
  _instruction_set->handle_events(evt);
}

void AppWindow::render(RenderData ren) {
  assert(r);
  _sections_widget->render(ren);
  _instruction_set->render(ren);
  r->render(ren);
}

void AppWindow::update(UpdateData upd) {
  _sections_widget->update(upd);
  _instruction_set->update(upd);
}
void AppWindow::set_current_section(DTO::SectionType type) {
  _current_section = type;
}
