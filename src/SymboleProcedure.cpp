#include <SymboleProcedure.hpp>
#include <cstdlib>
#include <iostream>



SymboleProcedure::SymboleProcedure(int id, int arite, TableDesSymboles *tablesDesSymboles): Symbole(id, CATEGORIE_PROCEDURE)
{
    tablesDesSymbolesProcedure = tablesDesSymboles;
	this->arite = arite;
}

SymboleProcedure::~SymboleProcedure()
{
    delete tablesDesSymbolesProcedure;
}

int SymboleProcedure::getArite()
{
    return arite;
}

TableDesSymboles* SymboleProcedure::getTableDesSymboles() {
    return this->tablesDesSymbolesProcedure;
}

static std::string getNomSymboleCategorie(int categorie) {
    return "Procedure";
}

void SymboleProcedure::toString(std::ostream &flux) {
    flux << "\t"
            <<tableDesIdentificateurs.getNom(this->getId())
            << "\t"
            << getNomSymboleCategorie(this->getCategorie())
            << "\t\t["
            << "arity:" << this->arite
            << "]\n";
}
