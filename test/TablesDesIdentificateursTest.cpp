#include <stdlib.h>
#include <iostream>
#include <TableDesIdentificateurs.hpp>

int main(int argc, char *argv[])
{
    TableDesIdentificateurs TDI;
    TDI.ajouterId("test");
    TDI.affichageMapId();
    return EXIT_SUCCESS;
}