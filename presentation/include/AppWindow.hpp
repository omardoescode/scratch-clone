#include "DTOs/Sections.hpp"
#include "Data/EventData.hpp"
#include "Data/RenderData.hpp"
#include "Data/UpdateData.hpp"
#include "Widget.hpp"

class AppWindow {
public:
  static constexpr unsigned SIDEBAR_WIDTH = 250;
  static constexpr unsigned SECTIONS_HEIGHT = 200;

public:
  /*
   * @brief Constructor for initializing all widgets
   */
  AppWindow();
  /*
   * @brief Handle SFML Events
   *
   * @param event The event to handle
   */
  void handle_events(EventData);

  /*
   * @brief Render the Entire Application in `window`
   */
  void render(RenderData);

  /**
   * @brief Update The app state
   */
  void update(UpdateData);

private:
  /**
   * @brief Updates the current instruction set to be of the chosen section
   */
  void set_current_section(DTO::SectionType type);

private:
  std::shared_ptr<Widget> _sections_widget;
  std::shared_ptr<Widget> _instruction_set;
  DTO::SectionType _current_section;
};
