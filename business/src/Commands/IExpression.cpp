#include "Commands/IExpression.hpp"
#include "DTOs/Sections.hpp"

IExpression::IExpression(DTO::SectionType type, DataType return_type)
    : _return_type(return_type), Command(type) {}
DataType IExpression::get_return_type() const { return _return_type; }
