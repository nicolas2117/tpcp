#ifndef SYMBOLE_FONCTION
#define SYMBOLE_FONCTION

/**
 * @file SymboleFonction.hpp
 * @brief Fichier qui contient la définition de la classe SymboleFonction.
 * @author Nicolas CHARREL
 */

#include <Symbole.hpp>
#include <TableDesSymboles.hpp>
#include <Type.hpp>
#include "TableDesIdentificateurs.hpp"

extern TableDesIdentificateurs tableDesIdentificateurs;

/**
 * @brief Classe symboleFonction.
 */
class SymboleFonction : public Symbole {
private:
    TableDesSymboles *tablesDesSymbolesFonction; /**< Table des symboles de la fonction. */
    Type *typeDeRetour; /**< Type de retour de la fonction. */
    int arite; /**< Arité de la fonction. */

public:
    /**
     * @brief Constructeur.
     * @param id id du symbole.
     * @param typeDeRetour Type de retour de la fonction.
     * @param parent La table des symboles parent.
     * @param arite L'arité de la fonction.
     */
    SymboleFonction(int id, Type *typeDeRetour, int arite, TableDesSymboles *tablesDesSymboles);

    /**
     * @brief destructeur.
     */
    ~SymboleFonction();

    /**
     * @brief Retourne l'arité de la fonction.
     * @return L'arité de la fonction.
     */
    int getArite();
    /**
     * @brief Retourne la table des symboles de la fonction.
     * @return La table des symboles.
     */
    TableDesSymboles* getTableDesSymboles();
    void toString(std::ostream &flux);
};

#endif

