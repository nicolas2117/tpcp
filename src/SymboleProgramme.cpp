#include <SymboleProgramme.hpp>
#include <cstdlib>
#include <iostream>



SymboleProgramme::SymboleProgramme(int id): Symbole(id, CATEGORIE_PROGRAMME)
{

}

static std::string getNomSymboleCategorie(int categorie) {
    return "Program";
}

void SymboleProgramme::toString(std::ostream &flux) {
    flux << "\t"
            <<tableDesIdentificateurs.getNom(this->getId())
            << "\t"
            << getNomSymboleCategorie(this->getCategorie())
            << "\t\t["
            << "]\n";
}
