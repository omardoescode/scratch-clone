#include "Utils/Container.hpp"
#include <memory>

Container::Container(std::shared_ptr<Widget> widget) : _widget(widget) {}

Container::Container(Container &&rhs) { _widget = std::move(rhs._widget); }
void Container::operator=(Container &&rhs) { _widget = std::move(rhs._widget); }

void Container::render(RenderData ren) { _widget->render(ren); }
void Container::handle_events(EventData evt) { _widget->handle_events(evt); }
void Container::update(UpdateData dat) { _widget->update(dat); }
sf::FloatRect Container::get_global_bounds() const {
  return _widget->get_global_bounds();
}
void Container::set_position(float x, float y) {
  Widget::set_position(x, y);
  _widget->set_position(x, y);
}
sf::Color Container::get_background_color() {
  return _widget->get_background_color();
}
void Container::handle_click() { _widget->handle_click(); }

std::shared_ptr<Widget> Container::get_child() const { return _widget; }
