#include <cstdlib>
#include <iostream>
#include <TableDesSymboles.hpp>

int main(int argc, char *argv[])
{
    TableDesSymboles *TDS;
    TDS = new TableDesSymboles();
    TDS->ajouterSymbole(new Symbole());
    TDS->ajouterSymbole(new Symbole());
    TDS->afficher(std::cout);
    delete TDS;
    return EXIT_SUCCESS;
}
