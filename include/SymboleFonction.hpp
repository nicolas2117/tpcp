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

/**
 * @brief Classe symboleFonction.
 */
class SymboleFonction : public Symbole
{
    private:
        TableDesSymboles *tablesDesSymbolesFonction; /**< Table des symboles de la fonction. */
        Type *typeDeRetour; /**< Type de retour de la fonction. */

    public:
            /**
         * @brief Constructeur.
         * @param id id du symbole.
         * @param typeDeRetour Type de retour de la fonction.
         * @param parent La table des symboles parent.
         */
        SymboleFonction(int id, Type *typeDeRetour, const TableDesSymboles *parent);

        /**
         * @brief destructeur.
         */
        ~SymboleFonction();
};

#endif

