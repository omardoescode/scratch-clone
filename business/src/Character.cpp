#include "Character.hpp"
#include <cassert>
#include <string>

Character::Character(const std::string &sprite)
    : position(0, 0), current_sprite(0), rotation(0) {
  add_sprite(sprite);
}

void Character::add_sprite(const std::string &sprite) {
  sprites.push_back(sprite);
}

bool Character::remove_sprite(unsigned int index) {
  // Check if the index is valid
  assert(0 <= index && index < sprites.size());

  // Check if it's possible to remove
  if (sprites.size() == 1)
    return false;

  // erase
  sprites.erase(sprites.begin() + index);
  return true;
}

void Character::change_sprite(unsigned int index) {
  // Check if the index is valid
  assert(0 <= index && index < sprites.size());

  current_sprite = 0;
  notify_observers(Event::CHARACTER_CHANGE_SPRITE);
}

PositionVector_t Character::get_position() { return position; }
void Character::update_position(PositionVector_t pos) { position = pos; }

int Character::get_rotation() { return rotation; }
void Character::update_rotation(int rot) {
  rotation = rot;
  notify_observers(Event::CHARACTER_CHANGE_ROTATION);
}

std::vector<std::shared_ptr<InstructionStack>> Character::get_instructions() {
  return stacks;
}

void Character::add_stack(std::shared_ptr<InstructionStack> stack) {
  stacks.push_back(stack);
}
void Character::remove_stack(unsigned int index) {
  stacks.erase(stacks.begin() + index);
}
