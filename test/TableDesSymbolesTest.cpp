#include <cstdlib>
#include <iostream>
#include <TableDesSymboles.hpp>
#include <SymboleParametre.hpp>
#include <SymboleVariable.hpp>

int main(int argc, char *argv[])
{
    TableDesSymboles *TDS;
    TDS = new TableDesSymboles();
    TDS->ajouterSymbole(new SymboleParametre(1, new Type()));
    TDS->ajouterSymbole(new SymboleParametre(2, new Type()));
    TDS->afficher(std::cout);
    std::cout << "Symbole @ = " << TDS->getSymbole(1) << std::endl;
    std::cout << "Symbole @ = " << TDS->getSymbole(5) << std::endl;
    delete TDS;
    return EXIT_SUCCESS;
}
