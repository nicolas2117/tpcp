#include <iostream>
#include <TableDesIdentificateurs.hpp>

using namespace std;

TableDesIdentificateurs::TableDesIdentificateurs()
{
    _mapId[0] = "init";
}

TableDesIdentificateurs::~TableDesIdentificateurs()
{
    
}

const std::string& TableDesIdentificateurs::getId(int num)
{
    return _mapId[num];
}

int TableDesIdentificateurs::getNum(std::string id)
{
    std::map<int, std::string>::const_iterator it; //itérateur sur map
    for (it = _mapId.begin(); it !=_mapId.end(); it++)
    {
        if (id == it->second)
        {
            return it->first;
        }
    }
    return -1;
}

void TableDesIdentificateurs::affichageMapId()
{
    std::map<int, std::string>::const_iterator it; //itérateur sur map
    for(it = _mapId.begin(); it != _mapId.end(); it++)
    {
        cout << (*it).first << " => " << (*it).second << endl;
    }
}

int TableDesIdentificateurs::ajouterId(const std::string& newId)
{
    int temp = getNum(newId);
    if (temp==-1)
    {
        _mapId[_mapId.size()] = newId;
        return _mapId.size()-1;
    }
    else
    {
        return temp;
    }
}