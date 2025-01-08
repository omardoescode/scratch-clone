#include "Utils/Container.hpp"
#include <memory>

Container::Container(std::unique_ptr<Widget> widget)
    : _widget(std::move(widget)) {}

void Container::render(RenderData ren) { _widget->render(ren); }
void Container::handle_events(EventData evt) { _widget->handle_events(evt); }
void Container::update(UpdateData dat) { _widget->update(dat); }
sf::FloatRect Container::get_global_bounds() const {
  return _widget->get_global_bounds();
}
void Container::set_position(float x, float y) { _widget->set_position(x, y); }

void Container::handle_click() { _widget->handle_click(); }
