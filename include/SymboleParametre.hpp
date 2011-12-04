#ifndef SYMBOLE_PARAMETRE
#define SYMBOLE_PARAMETRE

/**
 * @file SymboleParametre.hpp
 * @brief Fichier qui contient la définition de la classe SymboleParametre.
 * @author Nicolas CHARREL
 */

#include <Symbole.hpp>
#include <Type.hpp>
#include "TableDesIdentificateurs.hpp"

extern TableDesIdentificateurs tableDesIdentificateurs;

/**
 * @brief Classe SymboleParametre.
 */
class SymboleParametre : public Symbole {
private:
    Type *type; /**< Type du parametre. */
		bool constant;


public:
    /**
     * @brief Constructeur.
     * @param id id du symbole.
     * @param type Type du parametre.
     */
    SymboleParametre(int id, Type *type, bool constant);

    /**
     * @brief Retourne le type du parametre.
     * @return Le type du parametre.
     */
    Type *getType();
    void toString(std::ostream &flux);

};

#endif

