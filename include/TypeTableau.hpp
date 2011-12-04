
#ifndef TYPETABLEAU_H
#define TYPETABLEAU_H
#include <Type.hpp>
#include <cstdlib>
#include <iostream>


class TypeTableau : public Type
{
    private:
    public:
    Type * t;
    TypeTableau();
    TypeTableau(Type * tDuTab);
    TypeTableau(TypeTableau * tT);
    bool operator== (Type& type);
    void toString(std::ostream flux){ flux << "type:tableau"; };
};

#endif // TYPETABLEAU_H
