#pragma once

#include "Commands/Command.hpp"
#include "Widget.hpp"
// TODO: Switch to Container
class CommandView : public Widget {
public:
  CommandView(std::shared_ptr<Command>);
  void render(RenderData);
  void handle_events(EventData);
  void update(UpdateData);
  sf::FloatRect get_global_bounds() const;
  void set_position(float x, float y);
  void handle_click();

private:
  std::shared_ptr<Widget> _widget;
};
