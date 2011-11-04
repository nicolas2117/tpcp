#include <cstdlib>
#include <iostream>
#include <TableDesSymboles.hpp>

TableDesSymboles::TableDesSymboles()
{
    this->parent = NULL;
}

TableDesSymboles::TableDesSymboles(const TableDesSymboles *parent)
{
    this->parent = parent;
}

TableDesSymboles::~TableDesSymboles()
{

}

void TableDesSymboles::ajouterSymbole(Symbole *symbole)
{
    symboles.push_back(symbole);
}

const Symbole *TableDesSymboles::getSymbole(int id)
{
    unsigned int i;
    for(i = 0; i < symboles.size(); i++)
    {
        if(symboles[i]->getId() == id)
            return symboles[i];
    }
    return NULL;
}

void TableDesSymboles::afficher(std::ostream &flux)
{
    unsigned int i;
    for(i = 0; i < symboles.size(); i++)
    {
        std::cout << symboles[i]->getId() <<  " " << symboles[i]->getCategorie() << std::endl;
    }
}
