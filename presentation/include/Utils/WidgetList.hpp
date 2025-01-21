#pragma once

/**
 * @brief A list of unique pointers of widgets
 */
#include "Widget.hpp"
#include <list>
#include <memory>
class WidgetList {
public:
  /**
   * @brief Default constructor
   */
  WidgetList() = default;

  /**
   * @brief Constructor
   *
   * @details Take a prepared list of pointers
   */
  explicit WidgetList(std::list<std::shared_ptr<Widget>> elements);

  /**
   * @brief Across all widgets
   */
  const std::list<std::shared_ptr<Widget>> &widgets() const;

  /**
   * @brief Getter for size
   */
  unsigned int size() const;

  /**
   * @brief Append elements to the widget list
   */
  void append_item(std::shared_ptr<Widget>);

private:
  std::list<std::shared_ptr<Widget>> _elems;
  bool valid;
};
