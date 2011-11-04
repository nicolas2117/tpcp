#include <iostream>
#include <TableDesIdentificateurs.hpp>

TableDesIdentificateurs::TableDesIdentificateurs()
{
    
}

TableDesIdentificateurs::~TableDesIdentificateurs()
{
    
}

const std::string& TableDesIdentificateurs::getNom(int id)
{
    return _mapId[id];
}

int TableDesIdentificateurs::getId(std::string nom)
{
    std::map<int, std::string>::const_iterator it; //itérateur sur map
    for (it = _mapId.begin(); it !=_mapId.end(); it++)
    {
        if (nom == it->second)
        {
            return it->first;
        }
    }
    return -1;
}

void TableDesIdentificateurs::afficher(std::ostream &flux)
{
	flux << "Table des identificateurs" << std::endl;
    std::map<int, std::string>::const_iterator it; //itérateur sur map
    for(it = _mapId.begin(); it != _mapId.end(); it++)
    {
        flux << (*it).first << " => " << (*it).second << std::endl;
    }
}

int TableDesIdentificateurs::ajouter(const char *str)
{
    int temp = getId(str);
    if (temp==-1)
    {
        _mapId[_mapId.size()] = str;
        return _mapId.size()-1;
    }
    else
    {
        return temp;
    }
}
