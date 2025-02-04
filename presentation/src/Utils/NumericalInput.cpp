#include "Utils/NumericalInput.hpp"
#include <cctype>

NumericalInput::NumericalInput(std::shared_ptr<Constant> constant_exp,
                               sf::Color clr, sf::Color background,
                               unsigned maximum_char_length, int char_size)
    : Input(constant_exp, clr, background, maximum_char_length, char_size) {}
bool NumericalInput::is_valid_char(char c) const {
  return std::isdigit(c) || c == '.';
}

void NumericalInput::on_unfocus() {
  if (__txt_widget->get_string().empty())
    __txt_widget->set_string("0");
}
