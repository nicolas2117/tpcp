#include <SymboleParametre.hpp>

SymboleParametre::SymboleParametre(int id, Type *type): Symbole(id, CATEGORIE_PARAMETRE)
{
    this->type = type;
}

const Type *SymboleParametre::getType()
{
    return type;
}
