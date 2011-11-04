
#ifndef TYPEBOOL_H
#define TYPEBOOL_H
#include <Type.hpp>


class TypeBool : public Type
{
    public:
    bool operator== (Type& type);
};

#endif // TYPEBOOL_H
