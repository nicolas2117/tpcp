#include <TypeReel.hpp>
#include <typeinfo>

bool TypeReel::operator==(Type& type) {
    return typeid (*this) == typeid (type);
};

void TypeReel::toString(std::ostream &flux) {
    flux << "type:real";
};