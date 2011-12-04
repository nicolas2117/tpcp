#ifndef SYMBOLE_VARIABLE
#define SYMBOLE_VARIABLE

/**
 * @file SymboleVariable.hpp
 * @brief Fichier qui contient la définition de la classe SymboleVariable.
 * @author Nicolas CHARREL
 */

#include <Symbole.hpp>
#include <Type.hpp>
#include "TableDesIdentificateurs.hpp"

extern TableDesIdentificateurs tableDesIdentificateurs;

/**
 * @brief Classe symboleVariable.
 */
class SymboleVariable : public Symbole {
private:
    Type *type; /**< Type de la variable. */

public:
    /**
     * @brief Constructeur.
     * @param id id du symbole.
     * @param type Type de la variable.
     */
    SymboleVariable(int id, Type *type);

    /**
     * @brief Retourne le type de la variable.
     * @return Le Type de la variable.
     */
    Type *getType();

    void toString(std::ostream &flux);
};

#endif

