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

Input::Input(sf::Color clr, sf::Color background, unsigned maximum_char_length)
    : _is_focused(false), _txt_color(clr), _bg_color(background),
      _maximum_char_length(maximum_char_length) {
  _txt_widget =
      std::make_shared<Text>(std::make_shared<sf::Text>(),
                             FontFactory::get_instance().get_primary_font());
  _txt_widget->set_fill_color(_txt_color);
  _txt_widget->set_string("0");

  _border = std::make_shared<RectangularBorder>(
      _txt_widget, sf::Color::Transparent, EdgeInsets(EdgeInsets::RIGHT, 2));

  // TODO: Fix the bug of WithBackground not changing size with `update` here
  _widget = std::make_shared<WithBackground>(
      std::make_shared<Padding>(_border, EdgeInsets(EdgeInsets::ALL, 10)),
      _bg_color);

  _cursor_change_callback = [this]() {
    _border->set_color(_border->get_color() != sf::Color::Transparent
                           ? sf::Color::Transparent
                           : _txt_color);
  };
}

void Input::render(RenderData ren) {
  assert(_widget);
  _widget->render(ren);
}

void Input::handle_events(EventData evt) {
  assert(_txt_widget);
  // Case 1: If clicking, alter focus depending on mouse position
  if (evt.event.type == sf::Event::MouseButtonPressed) {
    bool new_focus = is_hovered(*_widget, evt.mouse_position);
    if (_is_focused != new_focus) {
      if (_cursor_change_id) {
        Timer::get_instance().cancel_interval(*_cursor_change_id);
        _cursor_change_id = nullptr;
        _border->set_color(sf::Color::Transparent);
      } else {
        _cursor_change_id =
            std::make_shared<unsigned>(Timer::get_instance().set_interval(
                _cursor_change_callback, CURSOR_CHANGE_DELAY));
      }

      _is_focused = new_focus;
    }
  } else if (_is_focused && evt.event.type == sf::Event::TextEntered) {
    char new_char = evt.event.text.unicode;
    if (is_valid_char(new_char)) {
      auto str = _txt_widget->get_string();
      if (str.size() == _maximum_char_length)
        return;

      _txt_widget->set_string(str + new_char);
    } else if (new_char == '\b') {
      std::string new_string = _txt_widget->get_string();
      _txt_widget->set_string(new_string.substr(0, new_string.length() - 1));
    }
    set_position(__pos.x, __pos.y);
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
  return std::isalpha(c) || std::isdigit(c) || std::isspace(c);
}
