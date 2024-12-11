#include "SFML/Graphics.hpp"
#include "Widgets/SectionsWidget.hpp"

class AppWindow {
private:
  SectionsWidget sections;

public:
  /*
   * @brief Handle SFML Events
   *
   * @param event The event to handle
   */
  void handle_events(const sf::RenderWindow *window, const sf::Event &event);

  /*
   * @brief Render the Entire Application in `window`
   */
  void render(sf::RenderWindow *window);
};
