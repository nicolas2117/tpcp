#include <cstdlib>
#include <iostream>
#include <Symbole.hpp>
#include <SymboleProgramme.hpp>

int main(int argc, char *argv[])
{
    Symbole symbole(1, CATEGORIE_PROGRAMME);
    std::cout << "Id = " << symbole.getId() << " categorie = " << symbole.getCategorie() << std::endl;

    SymboleProgramme symboleProgramme(1);
    std::cout << "Id = " << symboleProgramme.getId() << " categorie = " << symboleProgramme.getCategorie() << std::endl;

    return EXIT_SUCCESS;
}
