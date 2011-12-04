
#ifndef TYPEREEL_H
#define TYPEREEL_H
#include <Type.hpp>
#include <cstdlib>
#include <iostream>


class TypeReel : public Type
{
    public:
    bool operator== (Type& type);
    void toString(std::ostream &flux);
};

#endif // TYPEREEL_H
