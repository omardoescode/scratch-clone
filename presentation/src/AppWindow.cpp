#include "AppWindow.hpp"
#include "DTOs/Sections.hpp"
#include "Widgets/InstructionSetView.hpp"
#include "Widgets/SectionsWidget.hpp"
#include <memory>

AppWindow::AppWindow() : _current_section(static_cast<DTO::SectionType>(0)) {
  _sections_widget = std::make_unique<SectionsWidget>(
      sf::Color(216, 203, 219),
      [this](DTO::SectionType type) { set_current_section(type); });
  _sections_widget->set_position(0, 0);
  //
  // // Get Instructions
  // auto instructions =
  //     CommandSet::get_instance().get_section_commands(_current_section);
  //
  // TextBuilder builder;
  // Text txt = builder.setFont(FontFactory::get_instance().get_primary_font())
  //                .setText(DTO::sectiontype_name_mapper(_current_section))
  //                .setSize(12)
  //                .build();
  //
  // ButtonConfig conf = {std::make_unique<Text>(std::move(txt))};
  //
  // auto lst = std::list<std::unique_ptr<Widget>>();
  // lst.emplace_back(std::make_unique<Button>(std::move(conf)));
  // _instruction_set = std::make_unique<GridView>(std::move(lst), 1);
  // _instruction_set->set_position(0, SECTIONS_HEIGHT);
  _instruction_set = std::make_unique<InstructionSetView>();
}
void AppWindow::handle_events(EventData evt) {
  _sections_widget->handle_events(evt);
  _instruction_set->handle_events(evt);
}

void AppWindow::render(RenderData ren) {
  _sections_widget->render(ren);
  _instruction_set->render(ren);
}

void AppWindow::update(UpdateData upd) {
  _sections_widget->update(upd);
  _instruction_set->update(upd);
}
void AppWindow::set_current_section(DTO::SectionType type) {
  _current_section = type;
}
