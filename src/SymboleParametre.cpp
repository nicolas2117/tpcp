#include <SymboleParametre.hpp>

SymboleParametre::SymboleParametre(int id, Type *type, bool constant): Symbole(id, CATEGORIE_PARAMETRE)
{
    this->type = type;
	this->constant = constant;
}

Type *SymboleParametre::getType()
{
    return type;
}
