#include <SymboleFonction.hpp>

SymboleFonction::SymboleFonction(int id, Type *typeDeRetour, int arite, TableDesSymboles *tablesDesSymboles): Symbole(id, CATEGORIE_FONCTION)
{
    this->typeDeRetour = typeDeRetour;
    tablesDesSymbolesFonction = tablesDesSymboles;
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

TableDesSymboles* SymboleFonction::getTableDesSymboles() {
    return this->tablesDesSymbolesFonction;
}
