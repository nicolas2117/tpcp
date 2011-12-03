#include <SymboleParametre.hpp>

SymboleParametre::SymboleParametre(int id, Type *type): Symbole(id, CATEGORIE_PARAMETRE)
{
    this->type = type;
}

Type *SymboleParametre::getType()
{
    return type;
}
