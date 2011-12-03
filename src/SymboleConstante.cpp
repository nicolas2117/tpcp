#include <SymboleConstante.hpp>

SymboleConstante::SymboleConstante(int id, Type *type): Symbole(id, CATEGORIE_CONSTANTE)
{
    this->type = type;
}

Type *SymboleConstante::getType()
{
    return type;
}
