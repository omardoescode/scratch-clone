#pragma once

#include "Utils/WidgetList.hpp"
#include "Widget.hpp"
#include <functional>
class WidgetListBuilder {
public:
  static WidgetList build(int count,
                          std::function<std::unique_ptr<Widget>(int)> handler);
};
