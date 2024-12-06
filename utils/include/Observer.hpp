#pragma once

#include "Event.hpp"
class Observer {
public:
  virtual ~Observer() = default;
  /*
   * @brief Invoked when notified by `Observable::notify_observers
   *
   * @param
   * The event to be invoked
   */
  virtual void onEvent(Event event) = 0;
};
