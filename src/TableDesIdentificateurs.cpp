#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <TableDesIdentificateurs.hpp>

TableDesIdentificateurs::TableDesIdentificateurs() {

}

TableDesIdentificateurs::~TableDesIdentificateurs() {

}

const std::string& TableDesIdentificateurs::getNom(int id) {
    return _mapId[id]; // On retourne l'identificateur correspondant à l'id.
}

int TableDesIdentificateurs::getId(std::string nom) {
    std::map<int, std::string>::const_iterator it; // Itérateur sur map.
    for (it = _mapId.begin(); it != _mapId.end(); it++) // On parcourt toute la table
    {
        if (nom == it->second) // Si pour un élément donné de la table, il y a correspondance
        {
            return it->first; // On retourne cet élément.
        }
    }
    return -1; // Sinon, l'identificateur n'a pas été trouvé.
}

void TableDesIdentificateurs::afficher(std::ostream &flux) {
    flux << "+++IdentificatorTable" << std::endl;
    std::map<int, std::string>::const_iterator it; // Itérateur sur map
    for (it = _mapId.begin(); it != _mapId.end(); it++) // On parcourt toute la table.
    {
        flux << "\t";
        for (int i = 0; i < (6-((int) (1 + log10((*it).first+1))) ); i++) {
            flux << " ";
        }
        flux << (*it).first+1 << " : " << (*it).second << std::endl;
    }
    flux << "---IdentificatorTable" << std::endl;
}

int TableDesIdentificateurs::ajouter(const char *str) {
    int temp = getId(str); // On récupère l'id.
    if (temp == -1) // Si l'identificateur n'est pas dans la table
    {
        _mapId[_mapId.size()] = str; // On l'ajoute à la dernière position de la table.
        return _mapId.size() - 1; // Du coup la taille de la table augmente de 1. On retourne donc l'indice moins 1 (-1) qui correspond au dernier élément ajouté.
    } else {
        return temp; // Sinon on retourne son id directement car l'identificateur est dans la table.
    }
}
