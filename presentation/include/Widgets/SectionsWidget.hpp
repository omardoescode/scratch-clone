#pragma once
#include "DTOs/Sections.hpp"
#include "Debug/DebugRect.hpp"
#include "Utils/Button.hpp"
#include "Utils/GridView.hpp"
#include "Widget.hpp"
#include <functional>
#include <memory>

// TODO: Document This class
class SectionsWidget : public Widget {
public:
  SectionsWidget(sf::Color background,
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
  std::shared_ptr<GridView> _grid;
};
