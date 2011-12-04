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
    return "INCONNU";
}

void SymboleFonction::toString(std::ostream &flux) {
    flux << "\t"
            <<tableDesIdentificateurs.getNom(this->getId())
            << "\t"
            << getNomSymboleCategorie(this->getCategorie())
            << "\t\t["
            << "0"
            << "]\n";
}
