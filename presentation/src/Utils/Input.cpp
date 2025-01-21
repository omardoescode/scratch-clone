#include "Utils/Input.hpp"
#include "Data/RenderData.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/Text.hpp"
#include "Utils/WithBackground.hpp"
#include <memory>

Input::Input() : _is_focused(false) {
  _widget =
      std::make_unique<Text>(std::make_shared<sf::Text>(),
                             FontFactory::get_instance().get_primary_font());
  _widget->set_fill_color(sf::Color::Green);
  _widget->set_string("Hello there cutie");
}

void Input::render(RenderData ren) { _widget->render(ren); }

void Input::handle_events(EventData evt) {
  // Case 1: If clicking, alter focus depending on mouse position
  if (evt.event.type == sf::Event::MouseButtonPressed) {
    _is_focused = is_hovered(*_widget, evt.mouse_position);
  } else if (_is_focused && evt.event.type == sf::Event::TextEntered) {
    std::string neww = _widget->get_string();
    neww += evt.event.text.unicode;
    _widget->set_string(neww);
    std::cout << evt.event.text.unicode;
  }
}
void Input::update(UpdateData) {}
sf::FloatRect Input::get_global_bounds() const {
  return _widget->get_global_bounds();
}
void Input::set_position(float x, float y) { _widget->set_position(x, y); }
