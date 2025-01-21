#pragma once

#include "Utils/WidgetList.hpp"
#include "Widget.hpp"
#include <functional>
class WidgetListBuilder {
public:
  WidgetListBuilder() = delete; // Delete the default constructor
  static WidgetList build(int count,
                          std::function<std::shared_ptr<Widget>(int)> handler);
};
