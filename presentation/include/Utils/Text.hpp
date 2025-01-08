#pragma once

#include "Widget.hpp"

class Text : public Widget {
public:
  /**
   * @brief Default Constructor
   */
  Text();

  /**
   * @brief Constructor
   *
   * @details Pass the text and font as members
   */
  Text(std::unique_ptr<sf::Text>, std::unique_ptr<sf::Font>);

  /**
   * @brief Render the text
   */
  void render(RenderData) override;

  /**
   * @brief Handle Events
   */
  void handle_events(EventData) override;

  /**
   * @brief Update the Text
   */
  void update(UpdateData) override;
  /**
   * @brief Setter the Text
   */
  void set_text(std::unique_ptr<sf::Text>);

  /**
   * @brief Setter the Font
   */
  void set_font(std::unique_ptr<sf::Font>);

  /**
   * @brief Change the font size
   */
  void set_character_size(unsigned size);

  /**
   * @brief Change the color
   */
  void set_fill_color(sf::Color color);

  /**
   * @brief Change the text string (lvalue)
   */
  void set_string(const std::string &value);

  /**
   * @brief Change the text string (rvalue)
   */
  void set_string(std::string &&value);

private:
  std::unique_ptr<sf::Text> _text;
  std::unique_ptr<sf::Font> _font;
};
