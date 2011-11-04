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
    int ajouter(const char *str);
    
    //affiche la table des identificateurs
    void afficher(std::ostream &flux);
    
    //retourne l'identificateur à partir de son numéro
    const std::string& getNom (int id);
    
    //retourne le numéro de l'identificateur
    int getId (std::string nom);
    
private:
    //map
    std::map<int, std::string> _mapId;	
};

#endif
