#include <iostream>
#include <TypeEntier.hpp>
#include <TypeReel.hpp>
#include <TypeBool.hpp>
#include <TypeTableau.hpp>
#include <TypeInterval.hpp>
#include <GenerateurType.hpp>

int main(int argc, char *argv[])
{
    //test entier
    TypeEntier TE1, TE2;
    std::cout << "Comparaison entre deux type Entier" << std::endl;
    std::cout << (int) (TE1 == TE2) << std::endl;

    //test reel
    TypeReel TR1,TR2;
    std::cout << "Comparaison entre deux type Reel" << std::endl;
    std::cout << (int) (TR1 == TR2) << std::endl;
    std::cout << "Comparaison entre un type reel et un entier" << std::endl;
    std::cout << (int) (TE1 == TR2) << std::endl;

    //test Booléan
    TypeBool TB1,TB2;
    std::cout << "Comparaison entre deux boolean" << std::endl;
    std::cout << (int) (TB1 == TB2) << std::endl;
    std::cout << "Comparaison entre un type reel et un Bool" << std::endl;
    std::cout << (int) (TR1 == TB2) << std::endl;
    std::cout << "Comparaison entre un type Bool et un entier" << std::endl;
    std::cout << (int) (TB1 == TE2) << std::endl;

    //test Tableau
    TypeTableau TT1(&TE1),TT2(&TE2);
    std::cout << "Comparaison entre deux tableau d'entier" << std::endl;
    std::cout << (int) (TT1 == TT2) << std::endl;
    TypeTableau TT3(&TR1),TT4(&TB2);
    std::cout << "Comparaison entre deux tableau d'entier et de reel" << std::endl;
    std::cout << (int) (TT1 == TT3) << std::endl;
    TypeTableau TT5(&TT1),TT6(&TT2);
    std::cout << "Comparaison entre deux tableau de tableau d'entier" << std::endl;
    std::cout << (int) (TT5 == TT6) << std::endl;
    TypeTableau TT7(&TT3);
    std::cout << "Comparaison entre deux tableau de tableau d'entier et de tableau de reel" << std::endl;
    std::cout << (int) (TT5 == TT7) << std::endl;
    TypeTableau TT8,TT9;
    std::cout << "Comparaison entre deux tableau sans type" << std::endl;
    std::cout << (int) (TT8 == TT9) << std::endl;
    std::cout << "Comparaison entre un tableau sans type et un tableau d'entier" << std::endl;
    std::cout << (int) (TT8 == TT2) << std::endl;


    //test Interval
    TypeInterval TI1(1,10),TI2(1,10),TI3(1,20);
    std::cout << "Comparaison de deux interval avec les meme bornes" << std::endl;
    std::cout << (int) (TI1 == TI2) << std::endl;
    std::cout << "Comparaison de deux interval avec des bornes differentes" << std::endl;
    std::cout << (int) (TI1 == TI3) << std::endl;
    std::cout << "Comparaison d'un interval avec un Entier" << std::endl;
    std::cout << (int) (TI1 == TE1) << std::endl;
    std::cout << "Comparaison d'un interval avec un tableau" << std::endl;
    std::cout << (int) (TI1 == TT1) << std::endl;


    //test Generateur Type
    GenerateurType Gen;
    TypeEntier* tEntier;
    TypeEntier* tEntier2;
    tEntier = (TypeEntier*)Gen.creerTypeEntier();
    tEntier2 = (TypeEntier*)Gen.creerTypeEntier();
    std::cout << "Comparaison de deux entier Généré par le generateur" << std::endl;
    std::cout << (int) (*tEntier == *tEntier2) << std::endl;
    std::cout << "Comparaison d'un TypeEntier et d'un autre Généré par le generateur" << std::endl;
    std::cout << (int) (*tEntier == TE1) << std::endl;
    std::cout << "Comparaison d'un TypeBoolean et d'un typeEntier Généré par le generateur" << std::endl;
    std::cout << (int) (*tEntier == TB1) << std::endl;

    TypeBool* tB;
    TypeBool* tB2;
    tB = (TypeBool*)Gen.creerTypeBool();
    tB2 = (TypeBool*)Gen.creerTypeBool();
    std::cout << "Comparaison de deux Booléan Généré par le generateur" << std::endl;
    std::cout << (int) (*tB == *tB2) << std::endl;

    TypeReel* tR;
    TypeReel* tR2;
    tR = (TypeReel*)Gen.creerTypeReel();
    tR2 = (TypeReel*)Gen.creerTypeReel();
    std::cout << "Comparaison de deux Reel Généré par le generateur" << std::endl;
    std::cout << (int) (*tR == *tR2) << std::endl;

    TypeTableau* tT;
    TypeTableau* tT2;
    tT = (TypeTableau*)Gen.creerTypeTableau();
    tT2 = (TypeTableau*)Gen.creerTypeTableau();
    std::cout << "Comparaison de deux Tableau Généré par le generateur" << std::endl;
    std::cout << (int) (*tT == *tT2) << std::endl;

    TypeInterval* tI;
    TypeInterval* tI2;
    tI = (TypeInterval*)Gen.creerTypeInterval();
    tI2 = (TypeInterval*)Gen.creerTypeInterval();
    std::cout << "Comparaison de deux Interval Généré par le generateur" << std::endl;
    std::cout << (int) (*tI == *tI2) << std::endl;



    return 0;
}
