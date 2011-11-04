#include <SymboleFonction.hpp>

SymboleFonction::SymboleFonction(int id, Type *typeDeRetour, const TableDesSymboles *parent): Symbole(id, CATEGORIE_FONCTION)
{
    this->typeDeRetour = typeDeRetour;
    tablesDesSymbolesFonction = new TableDesSymboles(parent);
}

SymboleFonction::~SymboleFonction()
{
    delete tablesDesSymbolesFonction;
}
