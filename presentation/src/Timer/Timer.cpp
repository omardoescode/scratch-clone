#include "Timer/Timer.hpp"
#include <chrono>
#include <functional>
#include <mutex>
#include <thread>

Timer::Timer() : _current_id(0) {}

Timer &Timer::get_instance() {
  static Timer instance;
  return instance;
}

unsigned Timer::set_interval(std::function<void()> callback,
                             int delay_in_milliseconds) {
  auto id = _current_id++;
  auto cancel_flag = std::make_shared<std::atomic<bool>>(false);

  // Store the cancel flag in the map
  {
    std::lock_guard<std::mutex> lock(_mutex);
    _intervals[id] = cancel_flag;
  }

  // Create a thread
  std::thread([this, id, callback, delay_in_milliseconds, cancel_flag]() {
    while (!cancel_flag->load()) {
      callback();
      std::this_thread::sleep_for(
          std::chrono::milliseconds(delay_in_milliseconds));
    }

    // When done, remove
    std::lock_guard<std::mutex> lock(_mutex);
    _intervals.erase(id);
  }).detach();

  return id;
}

void Timer::cancel_interval(unsigned id) {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_intervals.count(id)) {
    _intervals[id]->store(true);
    _intervals.erase(id);
  }
}
