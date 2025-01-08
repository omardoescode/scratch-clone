#include "SFML/Graphics.hpp"
#include "Widgets/SectionsWidget.hpp"

class AppWindow : public Widget {
private:
  SectionsWidget sections;

public:
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
};
