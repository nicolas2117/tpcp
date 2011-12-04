#ifndef SYMBOLE_TYPE
#define SYMBOLE_TYPE

#include <Symbole.hpp>
#include "TableDesIdentificateurs.hpp"

extern TableDesIdentificateurs tableDesIdentificateurs;

class SymboleType : public Symbole {
    void toString(std::ostream &flux);
};

#endif
