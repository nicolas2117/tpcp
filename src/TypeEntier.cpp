#include <TypeEntier.hpp>
#include <typeinfo>



bool TypeEntier::operator== (Type& type){
    return typeid(*this) == typeid(type);
};
