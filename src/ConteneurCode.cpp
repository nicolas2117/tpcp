/* 
 * File:   ConteneurCode.cpp
 * Author: Maxime Mélinon
 * 
 * Created on 4 novembre 2011, 16:28
 */

#include <vector>
#include "ConteneurCode.hpp"
#include "Instruction.hpp"

ConteneurCode::ConteneurCode() {
}

ConteneurCode::ConteneurCode(ConteneurCode& orig) {
}

ConteneurCode::~ConteneurCode() {
}

void ConteneurCode::ajouterCode(Instruction* instruction) {
    this->listeInstructions.push_back(instruction);
}

void ConteneurCode::ajouterCode(ConteneurCode* conteneur) {
    for ( unsigned int i ; i < conteneur->listeInstructions.size() ; i++) {
        this->listeInstructions.push_back(conteneur->listeInstructions[i]);
    }
}