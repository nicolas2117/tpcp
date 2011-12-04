
#ifndef TYPEINTERVAL_H
#define TYPEINTERVAL_H
#include <Type.hpp>
#include <cstdlib>
#include <iostream>


class TypeInterval : public Type
{
    private:
    int borneInf;
    int borneSup;
    public:
    TypeInterval();
    TypeInterval(int bI,int bS);
    bool operator==(Type& type);
    void toString(std::ostream &flux);
};

#endif // TYPEINTERVAL_H
