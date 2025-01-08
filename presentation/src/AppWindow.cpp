#include "AppWindow.hpp"
#include <memory>

AppWindow::AppWindow() {
  sections = std::make_unique<SectionsWidget>(SIDEBAR_WIDTH, SECTIONS_HEIGHT);
  sections->set_position(0, 0);
}
void AppWindow::handle_events(EventData evt) { sections->handle_events(evt); }
void AppWindow::render(RenderData ren) { sections->render(ren); }
void AppWindow::update(UpdateData upd) { sections->update(upd); }
