#include "Commands/IExpression.hpp"

class BaseExpression : public IExpression {
public:
  virtual ~BaseExpression() = default;
  virtual Value execute(CharacterManager &character, SymbolTable &symbol_table,
                        ScriptExecution &exeuction,
                        Vector<double> mouse_pointer, Time time) = 0;

private:
};
