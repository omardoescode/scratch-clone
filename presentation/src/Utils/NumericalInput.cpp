#include "Utils/NumericalInput.hpp"
#include <cctype>

NumericalInput::NumericalInput(sf::Color clr, sf::Color background,
                               unsigned maximum_char_length)
    : Input(clr, background, maximum_char_length) {}
bool NumericalInput::is_valid_char(char c) const { return std::isdigit(c); }

void NumericalInput::on_unfocus() {
  if (__txt_widget->get_string().empty())
    __txt_widget->set_string("0");
}
