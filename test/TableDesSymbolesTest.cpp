#include <cstdlib>
#include <iostream>
#include <TableDesSymboles.hpp>

int main(int argc, char *argv[])
{
    TableDesSymboles TDS;
    TDS.ajouterSymbole(new Symbole());
    TDS.afficher(std::cout);
    return EXIT_SUCCESS;
}
