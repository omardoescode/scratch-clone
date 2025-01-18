#pragma once
#include "DTOs/Sections.hpp"
#include "Widget.hpp"
#include <map>

/**
 * @brief This represents the instruction set including all sections
 * This creates the eight section instruction sets and caches them
 */
class InstructionSetView : public Widget {
public:
  InstructionSetView();

  void render(RenderData);
  void handle_events(EventData);
  void update(UpdateData);
  sf::FloatRect get_global_bounds() const;
  void set_position(float x, float y);

  void change_section(DTO::SectionType);

private:
  std::shared_ptr<Widget> get_current_instruction_set();
  std::shared_ptr<Widget> get_current_instruction_set() const;

private:
  std::map<DTO::SectionType, std::shared_ptr<Widget>>
      _sections_instruction_sets;
  DTO::SectionType _current_section;
};
