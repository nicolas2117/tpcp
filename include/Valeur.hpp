/* 
 * File:   Valeur.hpp
 * Author: Maxime Mélinon
 *
 * Created on 18 novembre 2011, 16:05
 */

#ifndef VALEUR_HPP
#define	VALEUR_HPP

#define TYPE_INT 0
#define TYPE_DOUBLE 1
#define TYPE_CHAR 2
#define TYPE_BOOL 3

class Valeur {
public:
    Valeur();
    Valeur(int valeur);
    Valeur(double valeur);
    Valeur(char valeur);
    Valeur(bool valeur);
    virtual ~Valeur();
private:
    int type;
    union {
        int intValeur;
        double doubleValeur;
        char charValeur;
        bool boolValeur;
    };
};

#endif	/* VALEUR_HPP */

