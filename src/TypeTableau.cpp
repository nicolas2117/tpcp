#include <TypeTableau.hpp>
#include <typeinfo>
#include <iostream>


TypeTableau::TypeTableau(){//initialise un tableau de type indefini
    this->t=0;
}

TypeTableau::TypeTableau(Type * tDuTab){
    this->t=tDuTab;
}

TypeTableau::TypeTableau(TypeTableau * tT){
    this->t=tT->t;
}

bool TypeTableau::operator== (Type & type){
    if(typeid(*this) == typeid(type))//si c'est un tableau
    {
        //if(*(this->t)==*(Tab.t))
        if((*(this->t))==(*((dynamic_cast<TypeTableau&>(type)).t)))
        {
                std::cout << "Les deux tableaux sont du meme type" << std::endl;
                return true;
        }//comparaison du type des elements du tableau*/
        std::cout << "Les Tableaux ne sont pas du meme type" << std::endl;
        return false;
    }
    std::cout << "Ce ne sont pas deux tableau" << std::endl;
    return false;
};
