#pragma once
#include "Utils/Event.hpp"
#include "Utils/Observer.hpp"
#include <map>
#include <memory>
#include <vector>

/*
 * @brief Represents an abstraction of any class that can send signals
 *
 * @note It allows observers to register them selves when some event happens
 */
class Observable {
public:
  /*
   * @breif Register an observer to the event `event`
   */
  void register_observer(Event event, std::shared_ptr<Observer> observer);

  /*
   * @brief Notifies all observers that subscribed to the event `event`
   */
  void notify_observers(Event event);

private:
  std::map<Event, std::vector<std::shared_ptr<Observer>>> events;
};
