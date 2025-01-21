#include "Utils/Input.hpp"
#include "Data/RenderData.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/Padding.hpp"
#include "Utils/RectangularBorder.hpp"
#include "Utils/WithBackground.hpp"
#include <cctype>
#include <memory>

Input::Input() : _is_focused(false) {
  _txt_widget =
      std::make_shared<Text>(std::make_shared<sf::Text>(),
                             FontFactory::get_instance().get_primary_font());
  _txt_widget->set_fill_color(sf::Color::Green);
  _txt_widget->set_string("Hello there cutie");

  _border = std::make_shared<RectangularBorder>(
      _txt_widget, sf::Color::Red, EdgeInsets(EdgeInsets::RIGHT, 2));

  _widget = std::make_shared<WithBackground>(
      std::make_shared<Padding>(_border, EdgeInsets(EdgeInsets::ALL, 10)),
      sf::Color::White);
}

void Input::render(RenderData ren) { _widget->render(ren); }

void Input::handle_events(EventData evt) {
  // Case 1: If clicking, alter focus depending on mouse position

  if (evt.event.type == sf::Event::MouseButtonPressed) {
    _is_focused = is_hovered(*_txt_widget, evt.mouse_position);
  } else if (_is_focused && evt.event.type == sf::Event::TextEntered) {
    char new_char = evt.event.text.unicode;
    if (is_valid_char(new_char))
      _txt_widget->set_string(_txt_widget->get_string() + new_char);
    else if (new_char == '\b') {
      std::string new_string = _txt_widget->get_string();
      _txt_widget->set_string(new_string.substr(0, new_string.length() - 1));
    }
    set_position(__pos.x, __pos.y);
  }
}
void Input::update(UpdateData) {}
sf::FloatRect Input::get_global_bounds() const {
  return _widget->get_global_bounds();
}

void Input::set_position(float x, float y) {
  Widget::set_position(x, y);
  _widget->set_position(x, y);
}

bool Input::is_valid_char(char c) const {
  return std::isalpha(c) || std::isdigit(c) || std::isspace(c);
}
