#ifndef TABLE_DES_IDENTIFICATEURS
#define TABLE_DES_IDENTIFICATEURS

/**
 * @file TableDesIdentificateurs.hpp
 * @brief Fichier qui contient la définition de la classe TableDesIdentificateurs.
 * @author Claude MAKOSSO-MAKOSSO
 */

#include <map>
#include <string>

/**
 * @brief Classe TableDesIdentificateurs.
 */

class TableDesIdentificateurs
{
public:
    /**
     * @brief Constructeur.
     */
    TableDesIdentificateurs();
    
    /**
     * @brief Destructeur.
     */
    ~TableDesIdentificateurs();
      
    /**
     * @brief Enregistre un identificateur
     * @param str L'identificateur.
     * @return L'id de l'identificateur dans la table
     */
    int ajouter(const char *str);
    
    /**
     * @brief Affiche la table des identificateurs.
     * @param flux Le flux sur lequel afficher la table.
     */
    void afficher(std::ostream &flux);
    
    /**
     * @brief Retourne l'identificateur à partir de son numéro.
     * @param id L'id de l'identificateur que l'on veut récupérer.
     * @return L'identificateur.
     */
    const std::string& getNom (int id);
    
    /**
     * @brief Retourne l'id de l'identificateur.
     * @param nom L'identificateur dont on veut récupérer l'id.
     * @return L'id.
     */
    int getId (std::string nom);
    
private:
    //map
    std::map<int, std::string> _mapId; /**< Liste des identificateurs. */
};

#endif
