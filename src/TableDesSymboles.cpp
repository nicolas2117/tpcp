#include <cstdlib>
#include <iostream>
#include <TableDesSymboles.hpp>

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
    
    flux << "+++SymbolTable(" << 0 << ":" << 0 << ")" << std::endl;
    for (i = 0; i < symboles.size(); i++) {
        symboles[i]->toString(flux);
    }
    flux << "---SymbolTable" << std::endl;
}

TableDesSymboles* TableDesSymboles::getParent() {
    return this->parent;
}


