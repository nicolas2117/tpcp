#ifndef SYMBOLE_VARIABLE
#define SYMBOLE_VARIABLE

#include <Symbole.hpp>
#include <Type.hpp>

class SymboleVariable : public Symbole
{
	public:
	SymboleVariable(int id, Type *type);
};

#endif

