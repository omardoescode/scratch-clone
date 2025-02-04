#include "Utils/GridView.hpp"
#include "Data/UpdateData.hpp"
#include <algorithm>

GridView::GridView(WidgetList widgets, unsigned widgets_per_row,
                   unsigned main_axis_spacing, unsigned cross_axis_spacing)
    : _widgets_per_row(widgets_per_row), _main_axis_spacing(main_axis_spacing),
      _cross_axis_spacing(cross_axis_spacing), _list(std::move(widgets)) {
  assert(widgets_per_row > 0);
  assert(main_axis_spacing >= 0);
  assert(cross_axis_spacing >= 0);
}

GridView::GridView(WidgetList widgets, unsigned widgets_per_row,
                   unsigned axis_spacing)
    : GridView(std::move(widgets), widgets_per_row, axis_spacing,
               axis_spacing) {}

void GridView::render(RenderData ren) {
  for (auto &widget : _list.widgets())
    widget->render(ren);
}
void GridView::update(UpdateData upd) {
  for (auto &widget : _list.widgets())
    widget->update(upd);
}
void GridView::handle_events(EventData evt) {
  for (auto &widget : _list.widgets())
    widget->handle_events(evt);
}

sf::FloatRect GridView::get_global_bounds() const {
  auto [width, height] = calculate_size();

  // Calculate rows needed
  size_t num_rows = (_list.size() + _widgets_per_row - 1) / _widgets_per_row;

  // Total width = (widget width × widgets per row) + (spacing × (widgets per
  // row - 1))
  float total_width =
      width * _widgets_per_row + _main_axis_spacing * (_widgets_per_row - 1);

  // Total height = (widget height × number of rows) + (spacing × (number of
  // rows - 1))
  float total_height = height * num_rows + _cross_axis_spacing * (num_rows - 1);

  return {__pos.x, __pos.y, total_width, total_height};
}

void GridView::set_position(float x, float y) {
  Widget::set_position(x, y);
  float wid_x = x, wid_y = y;
  int columns = 0;

  auto [width, height] = calculate_size();
  for (auto &widget : _list.widgets()) {
    widget->set_position(wid_x, wid_y);
    columns++;

    if (columns == _widgets_per_row)
      columns = 0, wid_x = x, wid_y += _cross_axis_spacing + height;
    else
      wid_x += _main_axis_spacing + width;
  }
}

sf::Vector2f GridView::calculate_size() const {
  // Find max width
  float max_width = 0;
  float max_height = 0;

  for (const auto &widget : _list.widgets()) {
    auto bounds = widget->get_global_bounds();
    max_width = std::max(max_width, bounds.width);
    max_height = std::max(max_height, bounds.height);
  }

  return {max_width, max_height};
}
