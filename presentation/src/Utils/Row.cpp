#include "Utils/Row.hpp"
#include "Data/RenderData.hpp"
#include <algorithm>

Row::Row(WidgetList lst, int space_between)
    : _list(std::move(lst)), _space_between(space_between) {}

void Row::render(RenderData ren) {
  for (auto &widget : _list.widgets())
    widget->render(ren);
}
void Row::update(UpdateData upd) {
  for (auto &widget : _list.widgets())
    widget->update(upd);
}
void Row::handle_events(EventData evt) {
  for (auto &widget : _list.widgets())
    widget->handle_events(evt);
}
sf::FloatRect Row::get_global_bounds() const {
  float max_height = 0;
  float width = 0;

  for (auto &widget : _list.widgets()) {
    auto bounds = widget->get_global_bounds();
    max_height = std::max(max_height, bounds.height);
    width += bounds.width;
  }

  // Add the spaces between to width
  width += (_list.size() - 1) * _space_between;

  return {__pos.x, __pos.y, width, max_height};
}

void Row::set_position(float x, float y) {
  Widget::set_position(x, y);

  // Get the height center
  // TODO: Change this behavior to take the alignment as well
  // inspiration:
  // https://api.flutter.dev/flutter/rendering/MainAxisAlignment.html

  auto bounds = get_global_bounds();
  float cur_x = x, cur_y = y + bounds.height / 2;

  for (auto &widget : _list.widgets()) {
    auto wid_bounds = widget->get_global_bounds();
    widget->set_position(cur_x, cur_y - wid_bounds.height / 2);
    cur_x += wid_bounds.width + _space_between;
  }
}
