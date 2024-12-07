#pragma once

// Must support the < operator so can used in a map
#include "EventType.hpp"
class Event {
public:
  Event();

  /*
   * @brief Support the < operator
   *
   * @note Compare by event type
   */
  virtual bool operator<(Event rhs);

private:
  EventType type;
};
