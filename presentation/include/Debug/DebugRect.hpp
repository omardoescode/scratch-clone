
#include "Data/RenderData.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "Widget.hpp"
#include <memory>

class DebugRect {
public:
  DebugRect(std::shared_ptr<Widget>);

  void render(RenderData);

private:
  sf::RectangleShape _rect;
};
