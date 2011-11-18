#ifndef GENERATEURTYPE_H
#define GENERATEURTYPE_H
#include <Type.hpp>
#include <TypeEntier.hpp>
#include <TypeBool.hpp>
#include <TypeCaractere.hpp>
#include <TypeReel.hpp>
#include <TypeTableau.hpp>
#include <TypeInterval.hpp>
#include <cstddef>
#include <cstdlib>


class GenerateurType
{
    private:
        static TypeEntier* tEntier;
        static TypeBool* tBool;
        static TypeCaractere* tCaractere;
        static TypeReel* tReel;
        static TypeTableau* tTableau;
        static TypeInterval* tInterval;
    public:
        static Type* creerTypeEntier ( );
        static Type* creerTypeBool ( );
        static Type* creerTypeCaractere ( );
        static Type* creerTypeReel ( );
        static Type* creerTypeTableau ( );
        static Type* creerTypeInterval ( );
        //static Type* creerTypePointeur ( Type* typeElementPointe );
};

#endif // GENERATEURTYPE_H

