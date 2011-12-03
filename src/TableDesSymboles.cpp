#include <cstdlib>
#include <iostream>
#include <TableDesSymboles.hpp>

TableDesSymboles::TableDesSymboles() {
    this->parent = NULL;
}

TableDesSymboles::TableDesSymboles(const TableDesSymboles *parent) {
    this->parent = parent;
}

TableDesSymboles::~TableDesSymboles() {

}

void TableDesSymboles::ajouterSymbole(Symbole *symbole) {
    symboles.push_back(symbole);
}

const Symbole *TableDesSymboles::getSymbole(int id) const {
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
    unsigned int i;
    flux << "+++SymbolTable(" << 0 << ":" << 0 << ")" << std::endl;
    for (i = 0; i < symboles.size(); i++) {
        std::cout << symboles[i]->getId() << " " << symboles[i]->getCategorie() << std::endl;
    }
    flux << "---SymbolTable" << std::endl;
}

const TableDesSymboles* TableDesSymboles::getParent() {
    return this->parent;
}


