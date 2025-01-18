#include "Views/CommandView.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/TextBuilder.hpp"
#include <iostream>

CommandView::CommandView(std::shared_ptr<Command>) {
  TextBuilder builder;
  txt = builder.setText("Hello")
            .setSize(30)
            .setColor(sf::Color::Red)
            .setFont(FontFactory::get_instance().get_primary_font())
            .build();
}
void CommandView::render(RenderData ren) { txt.render(ren); }

void CommandView::handle_events(EventData) {}
void CommandView::update(UpdateData) {}
sf::FloatRect CommandView::get_global_bounds() const {
  return txt.get_global_bounds();
}
void CommandView::set_position(float x, float y) {}
void CommandView::handle_click() {}
sf::Color CommandView::get_background_color() {
  return txt.get_background_color();
}
