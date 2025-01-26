#pragma once
#include "Commands/CommandPart.hpp"
#include "DTOs/Sections.hpp"
#include "DataType.hpp"
#include <map>
#include <memory>
#include <vector>

class Expression;
class Command {
public:
  Command(DTO::SectionType);

  /*
   * @brief Getter for section
   */
  DTO::SectionType get_section() const;

  /*
   * @brief Getter for parts
   */
  const std::vector<CommandPart> &get_parts();

  /*
   * @brief Return all sections names and colors
   */
  static std::vector<DTO::Section> get_sections();

  /**
   * @breif Add a sub-expression to the command
   */
  void add_subexpression(std::string, std::shared_ptr<Expression>);

  /**
   * @brief Retrieve a sub-expresssion
   */
  std::shared_ptr<Expression> retrieve_subexpression(std::string name);

  /**
   * @breif Return the datatype for the sub-expression
   */
  DataType retreive_subexpression_datatype(std::string name);

protected:
  /*
   * @brief Setter for parts
   */
  void set_parts(std::vector<CommandPart> &&);

private:
  DTO::SectionType _section;
  std::vector<CommandPart> _parts;
  std::map<std::string, std::shared_ptr<Expression>> _expressions;
};
