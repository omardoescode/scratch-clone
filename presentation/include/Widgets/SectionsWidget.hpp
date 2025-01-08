#pragma once
#include "DTOs/Sections.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Utils/Button.hpp"
#include "Widget.hpp"
#include <memory>

class SectionsWidget : public Widget {
  static constexpr unsigned long WIDTH = 300, HEIGHT = 200;

public:
  SectionsWidget();

  void render(RenderData) override;
  void handle_events(EventData) override;
  void update(UpdateData) override;

private:
  /*
   * @brief Initialize the sections buttons
   */
  void init_sections();

private:
  // Setup a getter for sections in the business layer
  std::vector<DTO::Section> sections;
  std::unique_ptr<sf::Drawable> box; // The Box for sections
  std::vector<std::unique_ptr<Button>> sections_buttons;
};
