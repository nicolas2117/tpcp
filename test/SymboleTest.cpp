#include <cstdlib>
#include <iostream>
#include <Symbole.hpp>
#include <SymboleProgramme.hpp>
#include <SymboleConstante.hpp>
#include <SymboleVariable.hpp>
#include <SymboleParametre.hpp>
#include <SymboleProcedure.hpp>
#include <SymboleFonction.hpp>
#include <TableDesSymboles.hpp>

int main(int argc, char *argv[])
{
    Symbole symbole(1, CATEGORIE_PROGRAMME);
    std::cout << "Id = " << symbole.getId() << " categorie = " << symbole.getCategorie() << std::endl;

    SymboleProgramme symboleProgramme(1);
    std::cout << "Id = " << symboleProgramme.getId() << " categorie = " << symboleProgramme.getCategorie() << std::endl;

    SymboleVariable symboleVariable(1, new Type());
    std::cout << "Id = " << symboleVariable.getId() << " categorie = " << symboleVariable.getCategorie() << std::endl;

    SymboleConstante symboleConstante(1, new Type());
    std::cout << "Id = " << symboleConstante.getId() << " categorie = " << symboleConstante.getCategorie() << std::endl;

    SymboleParametre symboleParametre(1, new Type());
    std::cout << "Id = " << symboleParametre.getId() << " categorie = " << symboleParametre.getCategorie() << std::endl;

    SymboleFonction symboleFonction(1, new Type(), new TableDesSymboles());
    std::cout << "Id = " << symboleFonction.getId() << " categorie = " << symboleFonction.getCategorie() << std::endl;

    SymboleProcedure symboleProcedure(1, new TableDesSymboles());
    std::cout << "Id = " << symboleProcedure.getId() << " categorie = " << symboleProcedure.getCategorie() << std::endl;

    return EXIT_SUCCESS;
}
