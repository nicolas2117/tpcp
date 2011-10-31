#ifndef SYMBOLE_PARAMETRE
#define SYMBOLE_PARAMETRE

/**
 * @file SymboleParametre.hpp
 * @brief Fichier qui contient la définition de la classe SymboleParametre.
 * @author Nicolas CHARREL
 */

#include <Symbole.hpp>
#include <Type.hpp>

/**
 * @brief Classe SymboleParametre.
 */
class SymboleParametre : public Symbole
{
    private:
        Type *type; /**< Type du parametre. */

	public:
        /**
         * @brief Constructeur.
         * @param id id du symbole.
         * @param type Type du parametre.
         */
        SymboleParametre(int id, Type *type);

        /**
         * @brief Retourne le type du parametre.
         * @return Le type du parametre.
         */
        const Type *getType();
};

#endif

