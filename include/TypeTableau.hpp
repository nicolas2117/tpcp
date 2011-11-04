
#ifndef TYPETABLEAU_H
#define TYPETABLEAU_H
#include <Type.hpp>


class TypeTableau : public Type
{
    private:
    public:
    Type * t;
    TypeTableau();
    TypeTableau(Type * tDuTab);
    TypeTableau(TypeTableau * tT);
    bool operator== (Type& type);
};

#endif // TYPETABLEAU_H
