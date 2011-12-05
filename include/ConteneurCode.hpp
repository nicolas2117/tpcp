/* 
 * File:   ConteneurCode.hpp
 * Author: Maxime Mélinon
 *
 * Created on 4 novembre 2011, 16:28
 */

#ifndef CONTENEURCODE_HPP
#define	CONTENEURCODE_HPP

#include "Instruction.hpp"
#include <vector>

class ConteneurCode {
public:
    ConteneurCode();
    ConteneurCode(ConteneurCode& orig);
    virtual ~ConteneurCode();

    void ajouterCode(Instruction* instruction);
    void ajouterCode(ConteneurCode* conteneur);
    void afficherCode3a();
private:
    std::vector<Instruction *> listeInstructions;
    
    

};

#endif	/* CONTENEURCODE_HPP */

