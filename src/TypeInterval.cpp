#include <TypeInterval.hpp>
#include <typeinfo>
#include <iostream>

TypeInterval::TypeInterval() {//initialisation par default d'un interval
    this->borneInf = 0;
    this->borneSup = 0;
}

TypeInterval::TypeInterval(int bI, int bS) {//initialisation d'un interval avec les bornes passer en parametre
    this->borneInf = bI;
    this->borneSup = bS;
}

bool TypeInterval::operator==(Type & type) {
    if (typeid (*this) == typeid (type))//si c'est un Interval
    {
        if (this->borneInf == (dynamic_cast<TypeInterval&> (type)).borneInf && this->borneSup == (dynamic_cast<TypeInterval&> (type)).borneSup) {
            return true;
        } else {
            return false;
        }
    }
    std::cout << "Ce ne sont pas deux Interval" << std::endl;
    return false;
};

void TypeInterval::toString(std::ostream &flux) {
    flux << "type:interval";
};