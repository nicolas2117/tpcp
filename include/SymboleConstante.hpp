#ifndef SYMBOLE_CONSTANTE
#define SYMBOLE_CONSTANTE

/**
 * @file SymboleConstante.hpp
 * @brief Fichier qui contient la définition de la classe SymboleConstante.
 * @author Nicolas CHARREL
 */

#include <Symbole.hpp>
#include <Type.hpp>
#include "TableDesIdentificateurs.hpp"

extern TableDesIdentificateurs tableDesIdentificateurs;
extern TableDesIdentificateurs tableDesIdentificateurs;

/**
 * @brief Classe symboleConstante.
 */
class SymboleConstante : public Symbole {
private:
    Type *type; /**< Type de la constante. */

public:
    /**
     * @brief Constructeur.
     * @param id id du symbole.
     * @param type Type de la constante.
     */
    SymboleConstante(int id, Type *type);

    /**
     * @brief Retourne le type de la constante.
     * @return Le Type de la constante.
     */
    Type *getType();
    void toString(std::ostream &flux);
    
};

#endif
