#ifndef SYMBOLE
#define SYMBOLE

#include <string>

class Symbole
{
	private:
        int id;
        std::string categorie;

	public:
        Symbole(int id, std::string categorie);
        int getId();
        std::string &getCategorie();
};

#endif
