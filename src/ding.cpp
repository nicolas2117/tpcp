#include <stdlib.h>
#include <iostream>
#include <TableDesIdentificateurs.hpp>
#include <string.h>

int main(int argc, char *argv[])
{
    TableDesIdentificateurs TDI;
    char s[50];
    strcpy(s, "testa");
    TDI.ajouter(s);
    strcpy(s, "testb");
    TDI.ajouter(s);
    TDI.ajouter("tata");
    TDI.afficher(std::cout);
    int testId = TDI.getId("tata");
    std::cout << "ID de tata : " << testId << std::endl;
    std::cout << TDI.getNom(0) << std::endl;
    return EXIT_SUCCESS;
}