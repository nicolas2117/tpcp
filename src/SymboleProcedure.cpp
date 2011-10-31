#include <SymboleProcedure.hpp>

SymboleProcedure::SymboleProcedure(int id, const TableDesSymboles *parent): Symbole(id, CATEGORIE_PROCEDURE)
{
    tablesDesSymbolesProcedure = new TableDesSymboles(parent);
}

SymboleProcedure::~SymboleProcedure()
{
    delete tablesDesSymbolesProcedure;
}

