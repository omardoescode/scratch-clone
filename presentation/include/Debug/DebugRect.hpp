#pragma once
#include "Data/RenderData.hpp"
#include "Data/UpdateData.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "Widget.hpp"
#include <memory>

class DebugRect {
public:
  DebugRect(std::shared_ptr<Widget>);

  void update(UpdateData);
  void render(RenderData);

private:
  std::shared_ptr<Widget> _widget;
  sf::RectangleShape _rect;
};
