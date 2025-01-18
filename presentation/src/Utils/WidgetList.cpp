#include "Utils/WidgetList.hpp"

WidgetList::WidgetList(std::list<std::unique_ptr<Widget>> elements)
    : _elems(std::move(elements)) {}

WidgetList::WidgetList(WidgetList &&rhs) : _elems(std::move(rhs._elems)) {
  rhs._elems.clear();
}

WidgetList &WidgetList::operator=(WidgetList &&rhs) {
  _elems = std::move(rhs._elems);
  rhs._elems.clear();
  return *this;
}

const std::list<std::unique_ptr<Widget>> &WidgetList::widgets() const {
  return _elems;
}

unsigned int WidgetList::size() const { return _elems.size(); }
