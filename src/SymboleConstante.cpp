#include <SymboleConstante.hpp>

SymboleConstante::SymboleConstante(int id, Type *type): Symbole(id, CATEGORIE_CONSTANTE)
{
    this->type = type;
}

const Type *SymboleConstante::getType()
{
    return type;
}
