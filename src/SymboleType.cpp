#include <SymboleType.hpp>
#include <cstdlib>
#include <iostream>



static std::string getNomSymboleCategorie(int categorie) {
    return "Type";
}

void SymboleType::toString(std::ostream &flux) {
    flux << "\t"
            <<tableDesIdentificateurs.getNom(this->getId())
            << "\t"
            << getNomSymboleCategorie(this->getCategorie())
            << "\t\t["
            << "Type:…"
            << "]\n";
}
