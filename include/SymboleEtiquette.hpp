#ifndef SYMBOLE_ETIQUETTE
#define SYMBOLE_ETIQUETTE

#include <Symbole.hpp>
#include "TableDesIdentificateurs.hpp"

extern TableDesIdentificateurs tableDesIdentificateurs;

class SymboleEtiquette : public Symbole {
    void toString(std::ostream &flux);
};

#endif

