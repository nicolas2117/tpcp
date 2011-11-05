#ifndef SYMBOLE_PROCEDURE
#define SYMBOLE_PROCEDURE

/**
 * @file SymboleProcedure.hpp
 * @brief Fichier qui contient la définition de la classe SymboleProcedure.
 * @author Nicolas CHARREL
 */

#include <Symbole.hpp>
#include <TableDesSymboles.hpp>

/**
 * @brief Classe symboleProcedure.
 */
class SymboleProcedure : public Symbole
{
    private:
        TableDesSymboles *tablesDesSymbolesProcedure; /**< Table des symboles de la procedure. */
		int arite; /**< Arité de la procédure. */
    public:
            /**
         * @brief Constructeur.
         * @param id id du symbole.
         * @param parent La table des symboles parent.
		 * @param arite L'arité de la procédure.
         */
        SymboleProcedure(int id, const TableDesSymboles *parent, int arite);

        /**
         * @brief destructeur.
         */
        ~SymboleProcedure();

		/**
         * @brief Retourne l'arité de la procédure.
         * @return L'arité de la procédure.
         */
		int getArite();
};

#endif
