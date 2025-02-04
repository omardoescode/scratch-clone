#include "Commands/Command.hpp"
#include "Commands/Expression.hpp"
#include "DTOs/Sections.hpp"
#include <stdexcept>

Command::Command(DTO::SectionType section) : _section_type{section} {}

void Command::set_parts(std::vector<CommandPart> &&parts) { _parts = parts; }
// TODO: Using a json file, build sections from a json file, including finding
// some library to handle this (or handle it later, don't think it will be hard)
// By building a class class DataInitalizer or GameInitializer
std::map<DTO::SectionType, DTO::SectionData> Command::get_sections() {
  static std::map<DTO::SectionType, DTO::SectionData> data = {
      {DTO::MOTION, {{0x00, 0x42, 0x9e}}},
      {DTO::CONTROL, {{0xFF, 0xBF, 0x00}}},
      {DTO::SENSING, {{0x5C, 0xB1, 0xD6}}},
      {DTO::LOOKS, {{0x99, 0x66, 0xff}}},
      {DTO::SOUND, {{0xCF, 0x63, 0xCF}}},
      {DTO::OPERATORS, {{0x59, 0xC0, 0x59}}},
      {DTO::VARIABLES, {{0xFF, 0x8C, 0x1A}}}};
  return data;
}

const std::vector<CommandPart> &Command::get_parts() { return _parts; }

void Command::add_subexpression(std::string name,
                                std::shared_ptr<Expression> expression) {
  auto itr = _expressions.find(name);
  if (itr != _expressions.end())
    throw std::runtime_error(name + " expression already exists\n");
  _expressions[name] = expression;
}

std::shared_ptr<Expression> Command::retrieve_subexpression(std::string name) {
  auto itr = _expressions.find(name);
  if (itr == _expressions.end())
    throw std::runtime_error("Invalid " + name +
                             ": doesn't exist in the expression manage");
  return itr->second;
}

DataType Command::retreive_subexpression_datatype(std::string name) {
  auto exp = retrieve_subexpression(name);
  return exp->get_datatype();
}

DTO::SectionType Command::get_section_type() const { return _section_type; }
