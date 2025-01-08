#include "Utils/EdgeInsets.hpp"

EdgeInsets::EdgeInsets(int direction, float value) {
  bool has_top = direction & TOP;
  bool has_bottom = direction & BOTTOM;
  bool has_left = direction & LEFT;
  bool has_right = direction & RIGHT;

  if (has_top)
    _offsets.top = value;
  if (has_bottom)
    _offsets.bottom = value;
  if (has_left)
    _offsets.left = value;
  if (has_right)
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
