
#ifndef TYPEBOOL_H
#define TYPEBOOL_H
#include <Type.hpp>
#include <cstdlib>
#include <iostream>


class TypeBool : public Type
{
    public:
    bool operator== (Type& type);
    void toString(std::ostream &flux);
};

#endif // TYPEBOOL_H
