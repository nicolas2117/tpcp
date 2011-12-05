#include <SymboleVariable.hpp>
#include <cstdlib>
#include <iostream>

SymboleVariable::SymboleVariable(int id, Type *type) : Symbole(id, CATEGORIE_VARIABLE) {
    this->type = type;
}

Type *SymboleVariable::getType() {
    return type;
}

static std::string getNomSymboleCategorie(int categorie) {
    return "Variable";
}

void SymboleVariable::toString(std::ostream &flux) {
    flux << "\t"
            << tableDesIdentificateurs.getNom(this->getId())
            << "\t"
            << getNomSymboleCategorie(this->getCategorie())
            << "\t\t[type:";
    this->type->toString(flux);
    flux << "]\n";
}
