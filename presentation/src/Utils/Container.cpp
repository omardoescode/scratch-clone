#include "Utils/Container.hpp"
#include <memory>

Container::Container(std::unique_ptr<Widget> widget)
    : _widget(std::move(widget)) {}
