#include <SymboleFonction.hpp>
#include <cstdlib>
#include <iostream>



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

static std::string getNomSymboleCategorie(int categorie) {
    return "Function";
}

void SymboleFonction::toString(std::ostream &flux) {
    flux << "\t"
            <<tableDesIdentificateurs.getNom(this->getId())
            << "\t"
            << getNomSymboleCategorie(this->getCategorie())
            << "\t\t["
            << "arity:" << this->arite
            << ",return:";
            this->typeDeRetour->toString(flux);
            flux << "]\n";
}
