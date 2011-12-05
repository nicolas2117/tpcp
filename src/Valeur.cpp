/* 
 * File:   Valeur.cpp
 * Author: Maxime Mélinon
 * 
 * Created on 18 novembre 2011, 16:05
 */

#include "Valeur.hpp"

Valeur::Valeur() {
}

Valeur::Valeur(int valeur)
{
    intValeur = valeur;
    type = TYPE_INT;
}

Valeur::Valeur(double valeur)
{
    doubleValeur = valeur;

}

Valeur::Valeur(char valeur)
{
    charValeur = valeur;
}

Valeur::Valeur(bool valeur)
{
    boolValeur = valeur;
}

Valeur::~Valeur() {
}

