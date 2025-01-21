#pragma once

#include <atomic>
class Timer {
public:
  // Remove Copying
  Timer(Timer &) = delete;
  Timer operator=(Timer &) = delete;

  /**
   * @brief Getter for the instance
   */
  static Timer &get_instance();

  /**
   * @brief Allow a callback to run every `delay_in_milliseconds` milliseconds
   * @return returns a unique id for the time out, can be used to delete a timer
   * later
   */
  unsigned set_interval(std::function<void()> callback,
                        int delay_in_milliseconds);

  /**
   * @brief Given the current id of a timer, remove it
   */
  void cancel_interval(unsigned id);

private:
  /**
   * @brief Constructor
   *
   * @details set the initial value for `current_id` to 0
   */
  Timer();

private:
  std::atomic<unsigned> _current_id;
  std::map<int, std::shared_ptr<std::atomic<bool>>> _intervals;
  std::mutex _mutex; // A lock for the map
};
