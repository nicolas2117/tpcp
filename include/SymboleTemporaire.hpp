#ifndef SYMBOLE_TEMPORAIRE
#define SYMBOLE_TEMPORAIRE

#include <Symbole.hpp>
#include "TableDesIdentificateurs.hpp"

extern TableDesIdentificateurs tableDesIdentificateurs;

class SymboleTemporaire : public Symbole {
    void toString(std::ostream &flux);
};

#endif
