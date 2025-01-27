#pragma once

#include "Utils/WidgetList.hpp"
#include "Widget.hpp"

class Column : public Widget {
public:
  Column(WidgetList elements, int space_between = 0);

  void render(RenderData) override;
  void handle_events(EventData) override;
  void update(UpdateData) override;
  sf::FloatRect get_global_bounds() const override;
  void set_position(float x, float y) override;

private:
  WidgetList _list;
  int _space_between;
};
