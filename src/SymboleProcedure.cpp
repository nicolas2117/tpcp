#include <SymboleProcedure.hpp>
#include <cstdlib>
#include <iostream>



SymboleProcedure::SymboleProcedure(int id, TableDesSymboles *parent, int arite): Symbole(id, CATEGORIE_PROCEDURE)
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

static std::string getNomSymboleCategorie(int categorie) {
    switch (categorie) {
        case CATEGORIE_CONSTANTE:
            return "Constante";
            break;
        case CATEGORIE_ETIQUETTE:
            return "Étiquette";
            break;
        case CATEGORIE_FONCTION:
            return "Fonction";
            break;
        case CATEGORIE_PARAMETRE:
            return "Paramètre";
            break;
        case CATEGORIE_PROCEDURE:
            return "Procédure";
            break;
        case CATEGORIE_PROGRAMME:
            return "Programme";
            break;
        case CATEGORIE_TEMPORAIRE:
            return "Temporaire";
            break;
        case CATEGORIE_TYPE:
            return "Type";
            break;
        case CATEGORIE_VARIABLE:
            return "Variable";
            break;
    }
}

void SymboleProcedure::toString(std::ostream &flux) {
    flux << "\t"
            <<tableDesIdentificateurs.getNom(this->getId())
            << "\t"
            << getNomSymboleCategorie(this->getCategorie())
            << "\t\t["
            << "0"
            << "]\n";
}