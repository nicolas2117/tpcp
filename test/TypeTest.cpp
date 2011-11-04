#include <iostream>
#include <TypeEntier.hpp>
#include <TypeReel.hpp>
#include <TypeBool.hpp>
#include <TypeTableau.hpp>

int main(int argc, char *argv[])
{
    TypeEntier TE1, TE2;
    std::cout << "Comparaison entre deux type Entier" << std::endl;
    std::cout << (int) (TE1 == TE2) << std::endl;
    TypeReel TR1,TR2;
    std::cout << "Comparaison entre deux type Reel" << std::endl;
    std::cout << (int) (TR1 == TR2) << std::endl;
    std::cout << "Comparaison entre un type reel et un entier" << std::endl;
    std::cout << (int) (TE1 == TR2) << std::endl;
    TypeBool TB1,TB2;
    std::cout << "Comparaison entre deux boolean" << std::endl;
    std::cout << (int) (TB1 == TB2) << std::endl;
    std::cout << "Comparaison entre un type reel et un Bool" << std::endl;
    std::cout << (int) (TR1 == TB2) << std::endl;
    std::cout << "Comparaison entre un type Bool et un entier" << std::endl;
    std::cout << (int) (TB1 == TE2) << std::endl;
    TypeTableau TT1,TT2;
    TT1=new TypeTableau(&TE1);
    TT2=new TypeTableau(&TE2);
    std::cout << "Comparaison entre deux tableau d'entier" << std::endl;
    std::cout << (int) (TT1 == TT2) << std::endl;
    TypeTableau TT3,TT4;
    TT3=new TypeTableau(&TR1);
    TT4=new TypeTableau(&TB2);
    std::cout << "Comparaison entre deux tableau d'entier et de reel" << std::endl;
    std::cout << (int) (TT1 == TT3) << std::endl;
    TypeTableau TT5,TT6;
    TT5=new TypeTableau(&TT1);
    TT6=new TypeTableau(&TT2);
    std::cout << "Comparaison entre deux tableau de tableau d'entier" << std::endl;
    std::cout << (int) (TT5 == TT6) << std::endl;
    TypeTableau TT7;
    TT7=new TypeTableau(&TT3);
    std::cout << "Comparaison entre deux tableau de tableau d'entier et de tableau de reel" << std::endl;
    std::cout << (int) (TT5 == TT7) << std::endl;




    return 0;
}
