/* 
 * File:   Instruction.cpp
 * Author: Maxime Mélinon
 * 
 * Created on 4 novembre 2011, 16:27
 */

#include "Instruction.hpp"

Instruction::Instruction(Operande* operande1, Operande* operande2, Operande* operande3, int numeroInstruction) {
    this->operande1 = operande1;
    this->operande2 = operande2;
    this->operande3 = operande3;
    this->numeroInstruction = numeroInstruction;
}


Instruction::~Instruction() {
}

