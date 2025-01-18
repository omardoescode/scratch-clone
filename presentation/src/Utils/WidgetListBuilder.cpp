#include "Utils/WidgetListBuilder.hpp"
#include "Utils/WidgetList.hpp"
#include <memory>

WidgetList
WidgetListBuilder::build(int count,
                         std::function<std::unique_ptr<Widget>(int)> handler) {
  std::list<std::unique_ptr<Widget>> lst;

  for (int i = 0; i < count; i++)
    lst.emplace_back(handler(i));

  return WidgetList(std::move(lst));
}
