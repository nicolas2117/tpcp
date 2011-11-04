#ifndef SYMBOLE_PROGRAMME
#define SYMBOLE_PROGRAMME

/**
 * @file SymboleProgramme.hpp
 * @brief Fichier qui contient la définition de la classe SymboleProgramme.
 * @author Nicolas CHARREL
 */

#include <Symbole.hpp>

/**
 * @brief Classe SymboleProgramme.
 */
class SymboleProgramme : public Symbole
{
	public:
        /**
         * @brief Constructeur.
         * @param id id du symbole.
         */
        SymboleProgramme(int id);
};

#endif

