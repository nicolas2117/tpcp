#include <TypeCaractere.hpp>
#include <typeinfo>

bool TypeCaractere::operator==(Type& type) {
    return typeid (*this) == typeid (type);
};

void TypeCaractere::toString(std::ostream &flux) {
    flux << "type:char";
};