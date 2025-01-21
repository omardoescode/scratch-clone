#include "Utils/WidgetListBuilder.hpp"
#include "Utils/WidgetList.hpp"
#include <memory>

WidgetList
WidgetListBuilder::build(int count,
                         std::function<std::shared_ptr<Widget>(int)> handler) {
  std::list<std::shared_ptr<Widget>> lst;

  for (int i = 0; i < count; i++)
    lst.emplace_back(handler(i));

  return WidgetList(lst);
}
