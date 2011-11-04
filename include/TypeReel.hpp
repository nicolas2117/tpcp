
#ifndef TYPEREEL_H
#define TYPEREEL_H
#include <Type.hpp>


class TypeReel : public Type
{
    public:
    bool operator== (Type& type);
};

#endif // TYPEREEL_H
