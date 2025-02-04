#include "Utils/Input.hpp"
#include "Data/RenderData.hpp"
#include "SFML/Graphics/Color.hpp"
#include "Timer/Timer.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/Padding.hpp"
#include "Utils/RectangularBorder.hpp"
#include "Utils/WithBackground.hpp"
#include <cctype>
#include <memory>

Input::Input(std::shared_ptr<Constant> constant_exp, sf::Color clr,
             sf::Color background, unsigned maximum_char_length, int char_size)
    : _constant_exp(constant_exp), _is_focused(false), _txt_color(clr),
      _bg_color(background), _maximum_char_length(maximum_char_length) {
  assert(_constant_exp);

  __txt_widget =
      std::make_shared<Text>(std::make_shared<sf::Text>(),
                             FontFactory::get_instance().get_primary_font());
  __txt_widget->set_fill_color(_txt_color);
  __txt_widget->set_string(_constant_exp->get_value());
  __txt_widget->set_character_size(char_size);

  _cursor = std::make_shared<RectangularBorder>(
      __txt_widget, sf::Color::Transparent, EdgeInsets(EdgeInsets::RIGHT, 2));

  _widget = std::make_shared<WithBackground>(_cursor, _bg_color);

  _cursor_change_callback = [this]() {
    _cursor->set_color(_cursor->get_color() != sf::Color::Transparent
                           ? sf::Color::Transparent
                           : _txt_color);
  };
}

void Input::render(RenderData ren) {
  assert(_widget);
  _widget->render(ren);
}

void Input::handle_events(EventData evt) {
  assert(__txt_widget);
  // Case 1: If clicking, alter focus depending on mouse position
  if (evt.event.type == sf::Event::MouseButtonPressed) {
    bool new_focus = is_hovered(*_widget, evt.mouse_position);
    if (_is_focused != new_focus) {
      if (_cursor_change_id) {
        Timer::get_instance().cancel_interval(*_cursor_change_id);
        _cursor_change_id = nullptr;
        _cursor->set_color(sf::Color::Transparent);
        on_unfocus();
        _is_focused = false;
      } else {
        handle_click();
      }
    }
  }
  // Case 2: Handle Input
  else if (_is_focused && evt.event.type == sf::Event::TextEntered) {
    char new_char = evt.event.text.unicode;
    if (new_char == '\b') {
      std::string new_string = __txt_widget->get_string();
      set_value(new_string.substr(0, new_string.length() - 1));
    } else {
      auto str = __txt_widget->get_string() + new_char;
      if (!is_valid_char(new_char) || str.size() > _maximum_char_length ||
          !is_valid_value(str))
        return;

      set_value(std::move(str));
    }
  }
}

void Input::update(UpdateData upd) {
  assert(_widget);
  _widget->update(upd);
}

sf::FloatRect Input::get_global_bounds() const {
  assert(_widget);
  return _widget->get_global_bounds();
}

void Input::set_position(float x, float y) {
  assert(_widget);
  Widget::set_position(x, y);
  _widget->set_position(x, y);
}

bool Input::is_valid_char(char c) const {
  return std::isalpha(c) || std::isdigit(c) || std::isspace(c) || c == '.';
}

bool Input::is_valid_value(const std::string &inp) const { return true; }

void Input::on_unfocus() {}

void Input::set_value(std::string &&value) {
  __txt_widget->set_string(value);
  _constant_exp->set_value(std::move(value));
}

sf::Color Input::get_background_color() const { return _bg_color; }

void Input::handle_click() {
  if (_cursor_change_id)
    return;
  _cursor_change_id =
      std::make_shared<unsigned>(Timer::get_instance().set_interval(
          _cursor_change_callback, CURSOR_CHANGE_DELAY));
  _is_focused = true;
}
