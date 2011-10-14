#include <TableDesSymboles.hpp>

TableDesSymboles::TableDesSymboles()
{
    symboles = new std::vector<Symbole *>();
}

TableDesSymboles::~TableDesSymboles()
{

}

void TableDesSymboles::ajouterSymbole(Symbole *symbole)
{
    symboles->push_back(symbole);
}

void TableDesSymboles::afficher(std::ostream &flux)
{
    int i;
    int size = (int) symboles->size();
    for(i = 0; i < size; i++)
    {
        flux << "gna" << std::endl;
    }
    flux << "Hello world !!!" << std::endl;
}
