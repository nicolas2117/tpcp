#include <SymboleProcedure.hpp>

SymboleProcedure::SymboleProcedure(int id, const TableDesSymboles *parent, int arite): Symbole(id, CATEGORIE_PROCEDURE)
{
    tablesDesSymbolesProcedure = new TableDesSymboles(parent);
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
