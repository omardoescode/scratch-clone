#pragma once

#include "Commands/Constant.hpp"
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
  Input(std::shared_ptr<Constant> constant_exp,
        sf::Color clr = sf::Color::Black,
        sf::Color background = sf::Color::White,
        unsigned maximum_char_length = -1);

  void render(RenderData) override;
  void handle_events(EventData) override;
  void update(UpdateData) override;
  sf::FloatRect get_global_bounds() const override;
  void set_position(float x, float y) override;

  /**
   * @brief A predicate to determine if the character inputted is valid for the
   * input
   */
  virtual bool is_valid_char(char c) const;

  /**
   * @brief A predicate to determine if the whole input is valid
   * @note default no restrictions
   * @note don't use to check for new characters, for that, use `is_valid_char`
   */
  virtual bool is_valid_value(const std::string &) const;

  virtual void on_unfocus();

protected:
  void set_value(std::string &&);

protected:
  std::shared_ptr<Text> __txt_widget;

private:
  std::shared_ptr<Container> _widget;
  std::shared_ptr<RectangularBorder> _border;
  std::shared_ptr<unsigned> _cursor_change_id;
  std::shared_ptr<Constant> _constant_exp;
  std::function<void()> _cursor_change_callback;
  bool _is_focused;
  sf::Color _txt_color;
  sf::Color _bg_color;
  unsigned _maximum_char_length;
};
