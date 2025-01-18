#pragma once

/**
 * @brief A list of unique pointers of widgets
 */
#include "Widget.hpp"
#include <list>
#include <memory>
class WidgetList : public std::list<std::unique_ptr<Widget>> {
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
  explicit WidgetList(std::list<std::unique_ptr<Widget>> elements);

  /**
   * @brief Move Constructor
   */
  WidgetList(WidgetList &&);

  /**
   * @brief Move Assignment
   */
  WidgetList &operator=(WidgetList &&);

  /**
   * @brief Across all widgets
   */
  const std::list<std::unique_ptr<Widget>> &widgets() const;

  /**
   * @brief Getter for size
   */
  unsigned int size() const;

private:
  std::list<std::unique_ptr<Widget>> _elems;
  bool valid;
};
