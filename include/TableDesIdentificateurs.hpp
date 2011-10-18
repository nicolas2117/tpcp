#ifndef TABLE_DES_IDENTIFICATEURS
#define TABLE_DES_IDENTIFICATEURS

#include <map>
#include <string>

class TableDesIdentificateurs
{
public:
    //initialise la table des identificateurs
    TableDesIdentificateurs();
    
    //vide la table des identificateurs
    ~TableDesIdentificateurs();
      
    //enregistre un identificateur et renvoie son numéro dans la table
    int ajouterId(const std::string& newId);
    
    //affiche la table des identificateurs
    void affichageMapId();
    
    //retourne l'identificateur à partir de son numéro
    const std::string& getId (int num);
    
    //retourne le numéro de l'identificateur
    int getNum (std::string id);
    
private:
    //map
    std::map<int, std::string> _mapId;	
};

#endif
