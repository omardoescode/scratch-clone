#pragma once

/**
 * @brief This class represents offsets in terms of the four directions: top,
 * left, right, and bottom
 */
class EdgeInsets {
public:
  struct EdgeOffsets {
    float top = 0;
    float left = 0;
    float bottom = 0;
    float right = 0;
  };

  enum Direction {
    TOP = 1,
    BOTTOM = 2,
    LEFT = 4,
    RIGHT = 8,
    VERTICAL = TOP | BOTTOM,
    HORIZONTAL = LEFT | RIGHT,
    ALL = VERTICAL | HORIZONTAL,
  };

public:
  /**
   * @brief Constructor by one value for multiple directions
   */
  explicit EdgeInsets(int direction, float value);
  /**
   * @brief Constructor for all 4 directions
   *
   * @details If a value is -1, this means, it should mirror the opposite one
   * (This is the default value for bottom and right)
   */
  explicit EdgeInsets(float top, float left = 0, float bottom = -1,
                      float right = -1);

  /**
   * @brief Getter for top offset
   */
  float top() const;

  /**
   * @brief Getter for left offset
   */
  float left() const;

  /**
   * @brief Getter for right offset
   */
  float right() const;

  /**
   * @brief Getter for bottom offset
   */
  float bottom() const;

private:
  EdgeOffsets _offsets;
};
