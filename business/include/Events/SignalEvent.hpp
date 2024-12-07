#pragma once

#include "Event.hpp"
#include <string>
class SignalEvent : public Event {
private:
public:
  SignalEvent();

  /*
   * @brief Getter for the signal name
   */
  const std::string &get_signal_name() const;

private:
  std::string name;
};
