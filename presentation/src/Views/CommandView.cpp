#include "Views/CommandView.hpp"
#include "Utils/FontFactory.hpp"
#include "Utils/TextBuilder.hpp"
#include <iostream>

CommandView::CommandView(std::shared_ptr<Command>) : parts(WidgetList()) {
  TextBuilder builder;
  WidgetList lst;
  lst.append_item(std::make_unique<Text>(
      builder.setText("Hello")
          .setSize(30)
          .setColor(sf::Color::Red)
          .setFont(FontFactory::get_instance().get_primary_font())
          .build()));

  lst.append_item(std::make_unique<Text>(
      builder.setText("Worl\nd")
          .setSize(30)
          .setColor(sf::Color::Red)
          .setFont(FontFactory::get_instance().get_primary_font())
          .build()));
  lst.append_item(std::make_unique<Text>(
      builder.setText("Hello")
          .setSize(30)
          .setColor(sf::Color::Red)
          .setFont(FontFactory::get_instance().get_primary_font())
          .build()));
  parts = Row(std::move(lst));
}
void CommandView::render(RenderData ren) { parts.render(ren); }

void CommandView::handle_events(EventData evt) { parts.handle_events(evt); }
void CommandView::update(UpdateData dat) { parts.update(dat); }
sf::FloatRect CommandView::get_global_bounds() const {
  return parts.get_global_bounds();
}
void CommandView::set_position(float x, float y) { parts.set_position(x, y); }
void CommandView::handle_click() {}
