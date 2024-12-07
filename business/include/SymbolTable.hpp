#pragma once

#include "DataType.hpp"
#include "Value.hpp"
#include <map>
#include <string>
class SymbolTable {
public:
  /*
   * @brief Check if a variable exists in the table
   *
   * return `true` if the variable `var` exists in the table
   */
  bool contains(const std::string &var);

  /*
   * @brief Create a value in the symbol table
   *
   * @note Must set a default value for each kind of value
   */
  void add_var(const std::string &var);

  /*
   * @brief Change a value in the symbol table
   */
  void set_var(const std::string &var);

private:
  std::map<std::string, std::pair<DataType, Value>> vars;
};
