#pragma once

#include "Observer.hpp"
#include <future>
#include <string>
#include <vector>

template <typename T> class Observable {
public:
  void notify_observers(std::string &&value) {
    for (auto &obs : observers)
      obs->on_event(value);
  }

private:
  std::vector<std::shared_ptr<Observer>> observers;
};
