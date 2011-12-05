#include <SymboleConstante.hpp>
#include <cstdlib>
#include <iostream>

SymboleConstante::SymboleConstante(int id, Type *type) : Symbole(id, CATEGORIE_CONSTANTE) {
    this->type = type;
}

Type *SymboleConstante::getType() {
    return type;
}

static std::string getNomSymboleCategorie(int categorie) {
    return "Constant";
}

void SymboleConstante::toString(std::ostream &flux) {
    flux << "\t"
            <<tableDesIdentificateurs.getNom(this->getId())
            << "\t"
            << getNomSymboleCategorie(this->getCategorie())
            << "\t\t["
            << "0"
            << "]\n";
}
