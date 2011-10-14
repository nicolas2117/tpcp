/**
 *
 */
#ifndef TABLE_DES_SYMBOLES
#define TABLE_DES_SYMBOLES

#include <vector>
#include <ostream>

#include <Symbole.hpp>

class TableDesSymboles
{
    private:
        std::vector<Symbole *> *symboles;
    public:
    /**
     *
     */
    TableDesSymboles();
    ~TableDesSymboles();
    void ajouterSymbole(Symbole *symbole);
    void afficher(std::ostream &flux);
};

#endif
