#pragma once

#include "Data/UpdateData.hpp"
#include "Interfaces/Hoverable.hpp"
#include "Utils/Container.hpp"
#include "Widget.hpp"

class Input : public Widget, public Hoverable {
public:
  Input();

  void render(RenderData) override;
  void handle_events(EventData) override;
  void update(UpdateData) override;
  sf::FloatRect get_global_bounds() const override;
  void set_position(float x, float y) override;

  virtual bool is_valid_char(char c) const;

private:
  std::unique_ptr<Container> _widget;
  bool _is_focused;
};
