#include <stdlib.h>
#include <iostream>
#include <TableDesIdentificateurs.hpp>

int main(int argc, char *argv[])
{
    TableDesIdentificateurs TDI;
    TDI.ajouter("toto");
    TDI.ajouter("titi");
    TDI.ajouter("tata");
    TDI.afficher(std::cout);
    int testId = TDI.getId("tata");
    std::cout << "ID de tata : " << testId << std::endl;
    std::cout << TDI.getNom(0) << std::endl;
    return EXIT_SUCCESS;
}