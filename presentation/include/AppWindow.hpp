#include "DTOs/Sections.hpp"
#include "SFML/Graphics.hpp"
#include "Widgets/SectionsWidget.hpp"

class AppWindow {
public: // Constants for the scratc
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
  std::unique_ptr<Widget> sections;
  DTO::SectionType current;
};
