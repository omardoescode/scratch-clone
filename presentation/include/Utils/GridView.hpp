#pragma once

#include "Utils/WidgetList.hpp"
#include "Widget.hpp"

class GridView : public Widget {
public:
  /**
   * @brief Constructor
   */
  GridView(WidgetList widgets, unsigned widgets_per_row,
           unsigned main_axis_spacing, unsigned cross_axis_spacing);

  GridView(WidgetList widgets, unsigned widgets_per_row = 1,
           unsigned axis_spacing = 0);

  /*
   * @brief Render the Grid View
   */
  virtual void render(RenderData ren);

  /*
   * @brief Handle Events for the Grid
   */
  virtual void handle_events(EventData);

  /**
   * @brief Update the widget
   */
  virtual void update(UpdateData);

  /**
   * @brief Get Global Bounds
   */
  virtual sf::FloatRect get_global_bounds() const;

  /**
   * @brief Set Position
   *
   * @param x The X Position
   * @param y The Y Position
   */
  virtual void set_position(float x, float y);

  /**
   * @brief Set Position
   *
   * @param pos The Position Vector
   */
  void set_position(sf::Vector2f);

private:
  /**
   * @brief a helper to calculate a grid cell size
   *
   * @details Based on the maximum width of height of all cells
   */
  sf::Vector2f calculate_size() const;

private:
  unsigned _widgets_per_row;
  unsigned _main_axis_spacing;
  unsigned _cross_axis_spacing;
  WidgetList _list;
};
