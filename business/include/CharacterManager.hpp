#pragma once
#include <memory>
#include <vector>

class Character;

class CharacterManger {
public:
  /*
   * @brief Subscribe to all events by all characters scripts
   */
  void subscible_all_scripts();

  /*
   * @brief Add a character
   */
  void add_character(const std::shared_ptr<Character> &character);

  /*
   * @brief Remove a character
   */
  void remove_character(unsigned int index);

  /*
   * @brief Detect touching
   *
   * @return returns `true` if colliding/touching
   * TODO: Use a specific class for detecting collision (probabily create some
   * class Touchable/Object that must have x's and y's and sizes and keep track
   * of such info)
   */
  bool is_colliding(unsigned int ch1, unsigned int ch2);

private:
  std::vector<std::shared_ptr<Character>> characters;
};
