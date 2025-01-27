#include "Debug/DebugRect.hpp"

DebugRect::DebugRect(std::shared_ptr<Widget> wid) {
  assert(wid);
  auto bounds = wid->get_global_bounds();
  std::cout << bounds.top << " " << bounds.left << " " << bounds.height << " "
            << bounds.width << std::endl;

  _rect.setPosition(bounds.left, bounds.top);
  _rect.setSize({bounds.width, bounds.height});
  _rect.setFillColor(sf::Color::Transparent);
  _rect.setOutlineColor(sf::Color::Red);
  _rect.setOutlineThickness(5.f);
}

void DebugRect::render(RenderData ren) { ren.window.draw(_rect); }
