/* 
 * File:   Operande.cpp
 * Author: Maxime Mélinon
 * 
 * Created on 4 novembre 2011, 16:25
 */

#include "Operande.hpp"

Operande::Operande(int identificateur) {
    this->OperandeEstValeur = false;
    this->identificateur = identificateur;
}
Operande::Operande(Valeur* valeur) {
    this->OperandeEstValeur = true;
    this->valeur = valeur;
}

Operande::Operande(Operande& orig) {
}

Operande::~Operande() {
}

