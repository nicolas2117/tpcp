#ifndef TYPE
#define TYPE
#include <iostream>

class Type {

    public:
    virtual bool operator== (Type& type)=0;
    virtual void toString(std::ostream &flux){};
};

#endif
