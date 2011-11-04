
#ifndef TYPEINTERVAL_H
#define TYPEINTERVAL_H
#include <Type.hpp>


class TypeInterval : public Type
{
    private:
    int borneInf;
    int borneSup;
    public:
    TypeInterval();
    TypeInterval(int bI,int bS);
    bool operator==(Type& type);
};

#endif // TYPEINTERVAL_H
