#include "Commands/Command.hpp"
#include "Commands/Expression.hpp"
#include "DTOs/Sections.hpp"
#include <stdexcept>

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
