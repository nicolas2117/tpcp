
#ifndef TYPECARACTERE_H
#define TYPECARACTERE_H
#include <Type.hpp>
#include <cstdlib>
#include <iostream>


class TypeCaractere : public Type
{
    public:
    bool operator== (Type& type);
    void toString(std::ostream &flux);
};

#endif // TYPECARACTERE_H

