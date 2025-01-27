#include "Utils/Column.hpp"
#include "Data/RenderData.hpp"
#include "Utils/WidgetList.hpp"

Column::Column(WidgetList lst, int space_between)
    : _list(std::move(lst)), _space_between(space_between) {}

void Column::render(RenderData ren) {
  for (auto &widget : _list.widgets())
    widget->render(ren);
}

void Column::update(UpdateData upd) {
  for (auto &widget : _list.widgets())
    widget->update(upd);
}

void Column::handle_events(EventData evt) {
  for (auto &widget : _list.widgets())
    widget->handle_events(evt);
}

sf::FloatRect Column::get_global_bounds() const {
  float max_width = 0;
  float height = 0;

  for (auto &widget : _list.widgets()) {
    auto bounds = widget->get_global_bounds();
    max_width = std::max(max_width, bounds.width);
    height += bounds.height;
  }

  // Add the spaces between to width
  height += (_list.size() - 1) * _space_between;

  return {__pos.x, __pos.y, max_width, height};
}

void Column::set_position(float x, float y) {
  Widget::set_position(x, y);

  auto bounds = get_global_bounds();
  float cur_x = x + bounds.width / 2, cur_y = y;

  for (auto &widget : _list.widgets()) {
    auto wid_bounds = widget->get_global_bounds();
    widget->set_position(cur_x - wid_bounds.width / 2, cur_y);
    cur_y += wid_bounds.height + _space_between;
  }
}
