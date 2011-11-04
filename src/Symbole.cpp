#include <Symbole.hpp>

Symbole::Symbole(int id, Categorie categorie)
{
	this->id = id;
	this->categorie = categorie;
}

int Symbole::getId()
{
    return id;
}

Categorie Symbole::getCategorie()
{
    return categorie;
}
