#pragma once
#include "DTOs/Sections.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Utils/Button.hpp"
#include "Utils/GridView.hpp"
#include "Widget.hpp"
#include <functional>
#include <memory>

// TODO: Document This class
class SectionsWidget : public Widget {
public:
  SectionsWidget(unsigned width, unsigned height, sf::Color background,
                 std::function<void(DTO::SectionType)> handler);

  void render(RenderData) override;
  void handle_events(EventData) override;
  void update(UpdateData) override;
  sf::FloatRect get_global_bounds() const override;
  void set_position(float x, float y) override;

private:
  /*
   * @brief Initialize the sections buttons
   *
   * @param The handler to run when the section is clicked on
   */
  void init_sections(std::function<void(DTO::SectionType)> handler);

private:
  std::unique_ptr<GridView> _grid;
};
