#include "Commands/Expression.hpp"

Expression::Expression(DTO::SectionType type, DataType return_type)
    : Command(type), _datatype(return_type) {}

DataType Expression::get_datatype() const { return _datatype; }
