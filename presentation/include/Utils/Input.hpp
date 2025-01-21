#pragma once

#include "Data/UpdateData.hpp"
#include "Interfaces/Hoverable.hpp"
#include "Utils/Container.hpp"
#include "Utils/RectangularBorder.hpp"
#include "Utils/Text.hpp"
#include "Widget.hpp"

class Input : public Widget, public Hoverable {
public:
  static constexpr int CURSOR_CHANGE_DELAY = 500;

public:
  Input(sf::Color clr = sf::Color::Black,
        sf::Color background = sf::Color::White);

  void render(RenderData) override;
  void handle_events(EventData) override;
  void update(UpdateData) override;
  sf::FloatRect get_global_bounds() const override;
  void set_position(float x, float y) override;

  virtual bool is_valid_char(char c) const;

private:
  std::shared_ptr<Container> _widget;
  std::shared_ptr<Text> _txt_widget;
  std::shared_ptr<RectangularBorder> _border;
  std::shared_ptr<unsigned> _cursor_change_id;
  std::function<void()> _cursor_change_callback;
  bool _is_focused;
  sf::Color _txt_color;
  sf::Color _bg_color;
};
