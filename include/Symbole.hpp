#ifndef SYMBOLE
#define SYMBOLE

#include <Type.hpp>

class Symbole
{
	private:
        int id;
        Type *type;

	public:
        Symbole();
        ~Symbole();
        int getId();

};

#endif
