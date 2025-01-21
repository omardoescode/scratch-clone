#include "Utils/WidgetList.hpp"

WidgetList::WidgetList(std::list<std::shared_ptr<Widget>> elements)
    : _elems(elements) {}

const std::list<std::shared_ptr<Widget>> &WidgetList::widgets() const {
  return _elems;
}

unsigned int WidgetList::size() const { return _elems.size(); }

void WidgetList::append_item(std::shared_ptr<Widget> element) {
  _elems.emplace_back(element);
}
