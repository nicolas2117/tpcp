/* 
 * File:   Operande.hpp
 * Author: Maxime Mélinon
 *
 * Created on 4 novembre 2011, 16:25
 */

#ifndef OPERANDE_HPP
#define	OPERANDE_HPP

#include "Valeur.hpp"

class Operande {
public:
    Operande(int identificateur);
    Operande(Valeur* valeur);
    Operande(Operande& orig);
    virtual ~Operande();
private:
    bool OperandeEstValeur;
    union {
        Valeur* valeur;
        int identificateur;
    };
};

#endif	/* OPERANDE_HPP */

