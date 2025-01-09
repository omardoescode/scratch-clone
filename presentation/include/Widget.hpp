#pragma once

#include "Data/EventData.hpp"
#include "Data/RenderData.hpp"
#include "Data/UpdateData.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"

class Widget {
public:
  /*
   * @brief Render the widget in the given window
   *
   * @param ren Current Render Data
   */
  virtual void render(RenderData) = 0;

  /*
   * @brief Handle Events for the widget
   *
   * @param dat Current Event Data
   */
  virtual void handle_events(EventData) = 0;

  /**
   * @brief Update the widget
   */
  virtual void update(UpdateData) = 0;

  /**
   * @brief Get Global Bounds
   */
  virtual sf::FloatRect get_global_bounds() const = 0;

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

  /**
   * @brief Handle click
   */
  virtual void handle_click();

  /**
   * @brief Get the background of the widget
   */
  virtual sf::Color get_background_color();

protected:
  sf::Vector2f __pos;
};
