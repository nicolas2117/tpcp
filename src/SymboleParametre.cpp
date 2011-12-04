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

void SymboleParametre::toString(std::ostream &flux) {
    flux << "\t"
            << tableDesIdentificateurs.getNom(this->getId())
            << "\t"
            << getNomSymboleCategorie(this->getCategorie())
            << "\t\t[";
    this->type->toString(flux);
    flux << "]\n";
}
