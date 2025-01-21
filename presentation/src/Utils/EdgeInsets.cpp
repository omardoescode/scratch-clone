#include "Utils/EdgeInsets.hpp"

EdgeInsets::EdgeInsets(int direction, float value) {
  if (direction & TOP)
    _offsets.top = value;
  if (direction & BOTTOM)
    _offsets.bottom = value;
  if (direction & LEFT)
    _offsets.left = value;
  if (direction & RIGHT)
    _offsets.right = value;
}

EdgeInsets::EdgeInsets(float top, float left, float bottom, float right) {
  _offsets.top = top;
  _offsets.left = left;
  _offsets.bottom = bottom != -1 ? bottom : top;
  _offsets.right = right != -1 ? right : left;
}

float EdgeInsets::top() const { return _offsets.top; }
float EdgeInsets::left() const { return _offsets.left; }
float EdgeInsets::bottom() const { return _offsets.bottom; }
float EdgeInsets::right() const { return _offsets.right; }
