#include <TypeReel.hpp>
#include <typeinfo>


bool TypeReel::operator== (Type& type){
    return typeid(*this) == typeid(type);
};
