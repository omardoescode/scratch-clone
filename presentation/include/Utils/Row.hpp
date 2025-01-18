#pragma once

#include "Utils/WidgetList.hpp"
#include "Widget.hpp"

class Row : public Widget {
public:
  Row(WidgetList elements);

  void render(RenderData) override;
  void handle_events(EventData) override;
  void update(UpdateData) override;
  sf::FloatRect get_global_bounds() const override;
  void set_position(float x, float y) override;

private:
  WidgetList _list;
};
