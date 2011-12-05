#include <cstdlib>
#include <iostream>
#include <TableDesSymboles.hpp>
#include <SymboleProcedure.hpp>
#include <SymboleFonction.hpp>

#include "TableDesIdentificateurs.hpp"

extern TableDesIdentificateurs tableDesIdentificateurs;

TableDesSymboles::TableDesSymboles() {
    this->parent = NULL;
}

TableDesSymboles::TableDesSymboles(TableDesSymboles *parent) {
    this->parent = parent;
}

TableDesSymboles::~TableDesSymboles() {

}

void TableDesSymboles::ajouterSymbole(Symbole *symbole) {
    symboles.push_back(symbole);
}

Symbole *TableDesSymboles::getSymbole(int id) {
    unsigned int i;
    for (i = 0; i < symboles.size(); i++) {
        if (symboles[i]->getId() == id)
            return symboles[i];
    }
    if (parent == NULL) {
        return NULL;
    } else {
        return parent->getSymbole(id);
    }
}

void TableDesSymboles::afficher(std::ostream &flux) {
    /*
     * Max has left the building
     */
    unsigned int i;
    std::vector<TableDesSymboles *> tables;



    flux << "+++SymbolTable(" << this->idContexte << ":" << 0 << ")" << std::endl;
    for (i = 0; i < symboles.size(); i++) {
        symboles[i]->toString(flux);
        if (symboles[i]->getCategorie() == CATEGORIE_FONCTION) {
            tables.push_back(dynamic_cast<SymboleFonction*> (symboles[i])->getTableDesSymboles());
        }
        if (symboles[i]->getCategorie() == CATEGORIE_PROCEDURE) {
            tables.push_back(dynamic_cast<SymboleProcedure*> (symboles[i])->getTableDesSymboles());
        }

    }
    flux << "---SymbolTable" << std::endl;
    for (i = 0; i < tables.size(); i++) {
        tables[i]->afficher(flux);
    }
}

TableDesSymboles* TableDesSymboles::getParent() {
    return this->parent;
}

void TableDesSymboles::setIdContexte(int nom) {
    this->idContexte = nom;
}



