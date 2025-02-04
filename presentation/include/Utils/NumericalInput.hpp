#include "Utils/Input.hpp"

class NumericalInput : public Input {
public:
  /**
   * @breif Default Constructor
   */
  NumericalInput(std::shared_ptr<Constant> constant_exp,
                 sf::Color clr = sf::Color::Black,
                 sf::Color background = sf::Color::White,
                 unsigned maximum_char_length = -1, int char_size = 15);
  /**
   * @brief Make sure the character is a digit
   */
  virtual bool is_valid_char(char c) const override;

  /**
   * @breif Make sure there's a value in the input
   */
  virtual void on_unfocus() override;
};
