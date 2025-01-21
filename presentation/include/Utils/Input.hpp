#pragma once

#include "Data/UpdateData.hpp"
#include "Interfaces/Hoverable.hpp"
#include "Utils/Text.hpp"
#include "Widget.hpp"

class Input : public Widget, public Hoverable {
public:
  Input();

  void render(RenderData) override;
  void handle_events(EventData) override;
  void update(UpdateData) override;
  sf::FloatRect get_global_bounds() const override;
  void set_position(float x, float y) override;

private:
  std::unique_ptr<Text> _widget;
  bool _is_focused;
};
