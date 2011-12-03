#ifndef TABLE_DES_SYMBOLES
#define TABLE_DES_SYMBOLES

/**
 * @file TableDesSymboles.hpp
 * @brief Fichier qui contient la définition de la classe TableDesSymboles.
 * @author Nicolas CHARREL
 */

#include <vector>
#include <ostream>

#include <Symbole.hpp>

/**
 * @brief Classe TableDesSymboles.
 */
class TableDesSymboles {
private:
    std::vector<Symbole *> symboles; /**< Liste des symboles. */
    TableDesSymboles *parent; /**< Pointeur vers la table des symboles parent. */

public:
    /**
     * @brief constructeur.
     */
    TableDesSymboles();

    /**
     * @brief constructeur.
     * @param parent Pointeur vers la table des symboles parent.
     */
    TableDesSymboles(TableDesSymboles *parent);

    /**
     * @brief Destructeur.
     */
    ~TableDesSymboles();

    /**
     * @brief Ajoute un symbole à la table.
     * @param symbole Un symbole.
     */
    void ajouterSymbole(Symbole *symbole);

    /**
     * @brief Retourne un pointeur vers un symbole.
     * @param id L'id du symbole que l'on veut récupèrer.
     * @return Un pointeur vers un symbole.
     */
    Symbole *getSymbole(int id);

    /**
     * @brief Affiche la table des symboles.
     * @param flux Le flux sur lequel afficher la table.
     */
    void afficher(std::ostream &flux);

    /**
     * @brief Retourne la table des symboles parents
     * @param la table des symboles du parent
     */
    TableDesSymboles* getParent();
};

#endif
