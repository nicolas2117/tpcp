#include <SymboleVariable.hpp>

SymboleVariable::SymboleVariable(int id, Type *type): Symbole(id, CATEGORIE_VARIABLE)
{
    this->type = type;
}

const Type *SymboleVariable::getType()
{
    return type;
}
