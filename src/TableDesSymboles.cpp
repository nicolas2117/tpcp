#include <typeinfo>

#include <TableDesSymboles.hpp>

TableDesSymboles::TableDesSymboles()
{
    symboles = new std::vector<Symbole *>();
}

TableDesSymboles::~TableDesSymboles()
{
    delete symboles;
}

void TableDesSymboles::ajouterSymbole(Symbole *symbole)
{
    symboles->push_back(symbole);
}

Symbole *getSymbole(int id)
{

}

void TableDesSymboles::afficher(std::ostream &flux)
{
    int i;
    int size = (int) symboles->size();
    for(i = 0; i < size; i++)
    {
        flux << typeid(symboles[i]).name() << std::endl;
    }
    flux << "Hello world !!!" << std::endl;
}
