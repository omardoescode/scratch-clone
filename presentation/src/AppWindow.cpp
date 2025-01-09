#include "AppWindow.hpp"
#include "DTOs/Sections.hpp"
#include "Utils/Center.hpp"
#include "Utils/EdgeInsets.hpp"
#include "Utils/Padding.hpp"
#include <memory>

AppWindow::AppWindow() {
  sections = std::make_unique<SectionsWidget>(
      SIDEBAR_WIDTH, SECTIONS_HEIGHT, sf::Color(216, 203, 219),
      [this](DTO::SectionType type) { set_current_section(type); });
  sections->set_position(0, 0);
}
void AppWindow::handle_events(EventData evt) { sections->handle_events(evt); }
void AppWindow::render(RenderData ren) { sections->render(ren); }
void AppWindow::update(UpdateData upd) { sections->update(upd); }
void AppWindow::set_current_section(DTO::SectionType type) { current = type; }
