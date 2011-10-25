#include <iostream>
#include <Symbole.hpp>

Symbole::Symbole(int id, std::string categorie)
{
	this->id = id;
	this->categorie = categorie;
}

int Symbole::getId()
{
    return id;
}

std::string &Symbole::getCategorie()
{
    return categorie;
}
