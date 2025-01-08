#pragma once
#include "Commands/Script.hpp"

#include "Vector.hpp"
#include "string"
#include <vector>

/*
 * @brief Position Vector
 */
typedef Vector<double> PositionVector_t;

/*
 * Invariants:
 *   - sprites.size() > 0
 */
class Character {
public:
  /*
   * @brief Create a character with a given sprite as the initial default one
   */
  Character(const std::string &sprite);

  /*
   * @brief Add a sprite from the library to this character
   */
  void add_sprite(const std::string &);

  /*
   * @brief Remove a sprite at index `index` from the library if possible
   *
   * @note it's possible to remove a sprite if we have >1 sprite; A character
   * must have one sprite at least
   *
   * @return Return true if the sprite has been removed
   */
  bool remove_sprite(unsigned int index);

  /*
   * @brief Change the current sprite
   *
   * @note Must assert the validity of the index
   * @note Must notify observers
   */
  void change_sprite(unsigned int index);

  /*
   * @brief Getter the current positon
   */
  PositionVector_t get_position();

  /*
   * @brief Update position
   */
  void update_position(PositionVector_t position);

  /*
   * @brief Getter the rotation
   */
  int get_rotation();

  /*
   * @brief Update position
   *
   * @note Must notify with change in position
   */
  void update_rotation(int rotation);

  /*
   * @brief Getter for Stacks
   */
  std::vector<std::shared_ptr<Script>> get_instructions();

  /*
   * @brief Add a stack to this character
   */
  void add_stack(std::shared_ptr<Script> stack);

  /*
   * @brief Remove a stack to this character with index `index`
   */
  void remove_stack(unsigned int index);

private:
  std::vector<std::string> sprites;
  unsigned int current_sprite;
  PositionVector_t position;
  int rotation;
  std::vector<std::shared_ptr<Script>> stacks;
  unsigned int size;
};
