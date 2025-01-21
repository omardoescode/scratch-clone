#pragma once

#include <string>
class Observer {
public:
  /**
   * @brief A virtual method to be called when an observable want to to notify
   * all of its observers
   *
   * @details What to do is left to the sub-class
   */
  virtual void on_event(const std::string &);
};
