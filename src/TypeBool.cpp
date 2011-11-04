#include <TypeBool.hpp>
#include <typeinfo>


bool TypeBool::operator== (Type& type){
    return typeid(*this) == typeid(type);
};
