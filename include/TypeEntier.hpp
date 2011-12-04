
#ifndef TYPEENTIER_H
#define TYPEENTIER_H
#include <Type.hpp>
#include <cstdlib>
#include <iostream>


class TypeEntier : public Type
{
    public:
    bool operator== (Type& type);
    void toString(std::ostream &flux);
};

#endif // TYPEENTIER_H
