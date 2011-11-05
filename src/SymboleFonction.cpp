#include <SymboleFonction.hpp>

SymboleFonction::SymboleFonction(int id, Type *typeDeRetour, const TableDesSymboles *parent, int arite): Symbole(id, CATEGORIE_FONCTION)
{
    this->typeDeRetour = typeDeRetour;
    tablesDesSymbolesFonction = new TableDesSymboles(parent);
	this->arite = arite;
}

SymboleFonction::~SymboleFonction()
{
    delete tablesDesSymbolesFonction;
}

int SymboleFonction::getArite()
{
    return arite;
}
