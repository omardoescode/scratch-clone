#pragma once
#include "DTOs/Sections.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Utils/Button.hpp"
#include "Widget.hpp"
#include <memory>

// TODO: Document This class
class SectionsWidget : public Widget {
public:
  SectionsWidget(unsigned width, unsigned height);

  void render(RenderData) override;
  void handle_events(EventData) override;
  void update(UpdateData) override;
  sf::FloatRect get_global_bounds() const override;
  void set_position(float x, float y) override;

private:
  /*
   * @brief Initialize the sections buttons
   */
  void init_sections();

private:
  // Setup a getter for sections in the business layer
  std::vector<DTO::Section> sections;
  std::unique_ptr<sf::RectangleShape> box; // The Box for sections
  std::vector<std::unique_ptr<Widget>> sections_buttons;
};
