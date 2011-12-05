#include <SymboleParametre.hpp>
#include <cstdlib>
#include <iostream>


SymboleParametre::SymboleParametre(int id, Type *type, bool constant): Symbole(id, CATEGORIE_PARAMETRE)
{
    this->type = type;
	this->constant = constant;
}

Type *SymboleParametre::getType() {
    return type;
}

static std::string getNomSymboleCategorie(int categorie) {
    return "FormalArgument";
}

void SymboleParametre::toString(std::ostream &flux) {
    flux << "\t"
            << tableDesIdentificateurs.getNom(this->getId())
            << "\t"
            << getNomSymboleCategorie(this->getCategorie())
            << "\t\t[type:";
    this->type->toString(flux);
    if (constant)
    {
        flux << ",constant:true";
    } else {
        flux << ",constant:false";
    }
    flux << "]\n";
}
