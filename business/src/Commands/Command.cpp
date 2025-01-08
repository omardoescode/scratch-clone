#include "Commands/Command.hpp"
// TODO: Using a json file, build sections from a json file, including finding
// some library to handle this (or handle it later, don't think it will be hard)
// By building a class class DataInitalizer or GameInitializer
std::vector<DTO::Section> Command::get_sections() {
  return {
      {"Motion", {0xFF, 00, 00}},  {"Control", {11, 11, 11}},
      {"Sensing", {11, 11, 11}},   {"Looks", {11, 11, 11}},
      {"Sound", {11, 11, 11}},     {"Operators", {11, 11, 11}},
      {"Variables", {11, 11, 11}},
  };
}
