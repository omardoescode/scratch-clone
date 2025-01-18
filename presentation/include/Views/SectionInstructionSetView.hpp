#pragma once
#include "DTOs/Sections.hpp"
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
  std::list<std::shared_ptr<CommandView>>
      _commands; // < This is shared to enable drag-and-drop functionality to
                 // copy into canvas later
};
