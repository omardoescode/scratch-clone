#pragma once
#include "DTOs/Sections.hpp"
#include "Utils/Column.hpp"
#include "Views/CommandView.hpp"
#include "Widget.hpp"
#include <list>

/**
 * @brief This represents the instruction set of a specific section.
 */
class SectionInstructionSetView : public Widget {
public:
  SectionInstructionSetView(DTO::SectionType section);

  void render(RenderData);
  void handle_events(EventData);
  void update(UpdateData);
  sf::FloatRect get_global_bounds() const;
  void set_position(float x, float y);

private:
  DTO::SectionType _section;
  std::shared_ptr<Column> _commands;
};
