#pragma once

#include "Event.hpp"
class KeyboardEvent : public Event {
private:
  enum Keyboard { UNKNOWN = -1, A = 0, B };

public:
  KeyboardEvent();

  /*
   * @brief Getter for the key
   */
  Keyboard get_key();

private:
  Keyboard key;
};
