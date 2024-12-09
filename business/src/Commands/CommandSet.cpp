#include "Commands/CommandSet.hpp"

std::map<Command::Section, std::string> CommandSet::colors = {
    {Command::Section::MOTION, "#687eec"},
    {Command::Section::SENSING, "#687eec"},
    {Command::Section::CONTROL, "#687eec"},
    {Command::Section::LOOKS, "#687eec"},
    {Command::Section::SOUND, "#687eec"},
    {Command::Section::OPERATORS, "#687eec"},
    {Command::Section::VARIABLES, "#687eec"},
};
