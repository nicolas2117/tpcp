#include <GenerateurType.hpp>

TypeEntier* GenerateurType::tEntier=NULL;
TypeBool* GenerateurType::tBool=NULL;
TypeCaractere* GenerateurType::tCaractere=NULL;
TypeReel* GenerateurType::tReel=NULL;
TypeTableau* GenerateurType::tTableau=NULL;
TypeInterval* GenerateurType::tInterval=NULL;

Type* GenerateurType::creerTypeEntier ( ){
        if(GenerateurType::tEntier==NULL)
        {
            GenerateurType::tEntier=new TypeEntier;
        }
        return GenerateurType::tEntier;
}

Type* GenerateurType::creerTypeBool ( ){
    if(GenerateurType::tBool==NULL)
        {
            GenerateurType::tBool=new TypeBool;
        }
        return GenerateurType::tBool;
}

Type* GenerateurType::creerTypeCaractere ( ){
    if(GenerateurType::tCaractere==NULL)
        {
            GenerateurType::tCaractere=new TypeCaractere;
        }
        return GenerateurType::tCaractere;
}

Type* GenerateurType::creerTypeReel ( ){
    if(GenerateurType::tReel==NULL)
        {
            GenerateurType::tReel=new TypeReel;
        }
        return GenerateurType::tReel;
}

Type* GenerateurType::creerTypeTableau ( ){
    if(GenerateurType::tTableau==NULL)
        {
            GenerateurType::tTableau=new TypeTableau;
        }
        return GenerateurType::tTableau;
}

Type* GenerateurType::creerTypeInterval ( ){
    if(GenerateurType::tInterval==NULL)
        {
            GenerateurType::tInterval=new TypeInterval;
        }
        return GenerateurType::tInterval;
}


