#pragma once

#include "Event.hpp"
#include <functional>
#include <map>
typedef std::function<void(void)> Callback;
class EventBroker {
public:
  /*
   * @brief Add a callback to an event
   */
  void add_subscriber(Event, Callback callback);

  /*
   * @brief Notify all subscribers by calling their callbacks
   */
  void publish_event(Event);

private:
  std::map<Event, Callback> callbacks;
};
