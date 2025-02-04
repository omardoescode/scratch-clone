#include "Debug/DebugRect.hpp"
#include "Data/UpdateData.hpp"

DebugRect::DebugRect(std::shared_ptr<Widget> wid) : _widget(wid) {
  assert(_widget);
  auto bounds = wid->get_global_bounds();
  _rect.setPosition(bounds.left, bounds.top);
  _rect.setSize({bounds.width, bounds.height});
  _rect.setFillColor(sf::Color::Transparent);
  _rect.setOutlineColor(sf::Color::Red);
  _rect.setOutlineThickness(5.f);
}

void DebugRect::render(RenderData ren) {
  assert(_widget);
  ren.window.draw(_rect);
}

void DebugRect::update(UpdateData) {
  assert(_widget);
  auto bounds = _widget->get_global_bounds();
  _rect.setPosition(bounds.left, bounds.top);
}
