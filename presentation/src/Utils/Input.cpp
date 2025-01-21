#include "Utils/Input.hpp"
#include "Data/RenderData.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/Padding.hpp"
#include "Utils/Text.hpp"
#include <cctype>
#include <memory>

Input::Input() : _is_focused(false) {
  auto text =
      std::make_unique<Text>(std::make_shared<sf::Text>(),
                             FontFactory::get_instance().get_primary_font());
  text->set_fill_color(sf::Color::Green);
  text->set_string("Hello there cutie");

  _widget = std::make_unique<Padding>(std::move(text),
                                      EdgeInsets(EdgeInsets::ALL, 10));
}

void Input::render(RenderData ren) { _widget->render(ren); }

void Input::handle_events(EventData evt) {
  // Case 1: If clicking, alter focus depending on mouse position

  auto text_widget = std::dynamic_pointer_cast<Text>(_widget->get_child());

  if (evt.event.type == sf::Event::MouseButtonPressed) {
    _is_focused = is_hovered(*text_widget, evt.mouse_position);
  } else if (_is_focused && evt.event.type == sf::Event::TextEntered) {
    char new_char = evt.event.text.unicode;
    if (is_valid_char(new_char))
      text_widget->set_string(text_widget->get_string() + new_char);
    else if (new_char == '\b') {
      std::string new_string = text_widget->get_string();
      text_widget->set_string(new_string.substr(0, new_string.length() - 1));
    }
  }
}
void Input::update(UpdateData) {}
sf::FloatRect Input::get_global_bounds() const {
  return _widget->get_global_bounds();
}
void Input::set_position(float x, float y) { _widget->set_position(x, y); }

bool Input::is_valid_char(char c) const {
  return std::isalpha(c) || std::isdigit(c) || std::isspace(c);
}
