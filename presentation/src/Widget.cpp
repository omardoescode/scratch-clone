#include "Widget.hpp"

void Widget::set_position(float x, float y) { _pos = {x, y}; }
void Widget::set_position(sf::Vector2f pos) { set_position(pos.x, pos.y); }
void Widget::handle_click() {}
