#pragma once

#include <string>

enum class CommandPartType { TEXT, EXPRESSION };

/* @brief represent a part of a command
 *
 * @description
 *  case (part, value):
 *    part == TEXT
 *    value -> the text
 *
 *    part == EXPRESSION
 *    value -> The name of the expression that is stored
 *          -> Must be either InstructionWithExpression or RcursiveExpression,
 * where we will find the pointer to the expression mapped to this value
 */
typedef std::pair<CommandPartType, std::string> CommandPart;
