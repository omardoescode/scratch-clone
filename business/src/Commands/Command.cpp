#include "Commands/Command.hpp"
#include "DTOs/Sections.hpp"

Command::Command(DTO::SectionType section) : _section{section} {}

void Command::set_parts(std::vector<CommandPart> &&parts) { _parts = parts; }
// TODO: Using a json file, build sections from a json file, including finding
// some library to handle this (or handle it later, don't think it will be hard)
// By building a class class DataInitalizer or GameInitializer
std::vector<DTO::Section> Command::get_sections() {
  return {
      {DTO::MOTION, {0xFF, 00, 00}},  {DTO::CONTROL, {11, 11, 11}},
      {DTO::SENSING, {11, 11, 11}},   {DTO::LOOKS, {11, 11, 11}},
      {DTO::SOUND, {11, 11, 11}},     {DTO::OPERATORS, {11, 11, 11}},
      {DTO::VARIABLES, {11, 11, 11}},
  };
}

const std::vector<CommandPart> &Command::get_parts() { return _parts; }
