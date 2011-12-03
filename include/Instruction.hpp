/* 
 * File:   Instruction.hpp
 * Author: Maxime Mélinon
 *
 * Created on 4 novembre 2011, 16:27
 */

#ifndef INSTRUCTION_HPP
#define	INSTRUCTION_HPP

#include "Operande.hpp"

class Instruction {
public:
    Instruction();
    Instruction(Instruction& orig);
    virtual ~Instruction();
private:
    Operande* operande1;
    Operande* operande2;
    Operande* operande3;

    int numeroInstruction;
    int operation;
};

#endif	/* INSTRUCTION_HPP */

