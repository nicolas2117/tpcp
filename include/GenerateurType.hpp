#ifndef GENERATEURTYPE_H
#define GENERATEURTYPE_H
#include <Type.hpp>


class GenerateurType
{
    private:
        static Type* tEntier;
        static Type* tBool;
        static Type* tCaractere;
        static Type* tReel;
        static Type* tTableau;
        static Type* tInterval;
    public:
        static Type* creerTypePointeurEntier ( );
        static Type* creerTypePointeurBool ( );
        static Type* creerTypePointeurCaractere ( );
        static Type* creerTypePointeurReel ( );
        static Type* creerTypePointeurTableau ( );
        static Type* creerTypePointeurInterval ( );
};

#endif // GENERATEURTYPE_H

