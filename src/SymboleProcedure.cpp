#include <SymboleProcedure.hpp>

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
