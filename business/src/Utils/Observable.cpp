#include "Utils/Observable.hpp"

void Observable::register_observer(Event event,
                                   std::shared_ptr<Observer> observer) {
  events[event].push_back(observer);
}
void Observable::notify_observers(Event event) {
  for (auto &obs : events[event])
    obs->onEvent(event);
}
